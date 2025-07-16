#!/bin/bash

# Configurations
CC="cc"
CFLAGS="-Wall -Wextra -Werror -MMD -Isrc/ -Isrc/_core_"
AR="ar rcs"
NAME="Super-Libft.a"

# Répertoires
ROOT_DIR="$(dirname "$0")"
SRC_DIR="$ROOT_DIR/src"
BUILD_DIR=".build"
OBJ_DIR="$BUILD_DIR/obj"

# Global variables
ALL_OBJS=""

# Génère makefile.mk pour un module
gen_makefile_mk()
{
	local module_path="$1"
	local module_name="$2"
	local output="$module_path/makefile.mk"
	local includes=$(find "$module_path" -type d -exec printf -- "-I%s " {} \;)

	echo "Génération de $output"

	# Trouve tous les .c dans ce module
	src_files=$(find "$module_path" -name "*.c")

	echo "${module_name}_INCLUDES := $includes" > "$output"
	# Construction des variables Makefile
	echo "${module_name}_SRCS := \\" >> "$output"
	for src in $src_files; do
		echo "    $src \\" >> "$output"
	done

	echo "" >> "$output"
	echo "${module_name}_OBJS := \$(${module_name}_SRCS:%.c=${OBJ_DIR}/%.o)" >> "$output"
	echo "${module_name}_INCLUDES := ${includes}" >> "${output}"
	echo "" >> "${output}"

	ALL_OBJS+=" \$(${module_name}_OBJS)"

	# Règle générique de compilation
	cat >> "$output" << EOF
\$(${module_name}_OBJS): CFLAGS += \$(${module_name}_INCLUDES)

\$(${module_name}_OBJS):
	@mkdir -p \$(dir \$@)
	\$(CC) \$(CFLAGS) -c \$(patsubst \$(OBJDIR)/%.o,%.c,\$@) -o \$@
EOF
}

# Génère le makefile.mk du module _core_ avec un traitement spécifique
gen_makefile_core() {
	local core_path="$1"
	local module_name="_core_"
	local output="$core_path/makefile.mk"
	local includes=$(find "$core_path" -type d -exec printf -- "-I%s " {} \;)


	echo "Génération spéciale de $output (CORE)"

	src_files=$(find "$core_path" -name "*.c")

	echo "${module_name}_SRCS := \\" > "$output"
	for src in $src_files; do
		echo "    $src \\" >> "$output"
	done

	echo "" >> "$output"
	echo "${module_name}_OBJS := \$(${module_name}_SRCS:%.c=${OBJ_DIR}/%.o)" >> "$output"
	echo "${module_name}_INCLUDES := ${includes}" >> "${output}"
	echo "" >> "$output"

	# Règle avec includes pour tous les sous-dossiers (memory, error…)
	ALL_OBJS+=" \$(${module_name}_OBJS)"

	cat >> "$output" << EOF
\$(${module_name}_OBJS): CFLAGS += \$(${module_name}_INCLUDES)

\$(${module_name}_OBJS):
	@mkdir -p \$(dir \$@)
	\$(CC) \$(CFLAGS) -c \$(patsubst \$(OBJDIR)/%.o,%.c,\$@) -o \$@
EOF
}

# Génère tous les makefile.mk
echo "🔧 Génération des makefile.mk..."
for module_path in "$SRC_DIR"/*; do
	[ -d "$module_path" ] || continue
	module_name=$(basename "$module_path")

	if [ "$module_name" == "_core_" ]; then
		gen_makefile_core "$module_path"
		continue
	else
		gen_makefile_mk "$module_path" "$module_name"
	fi
done

# Génère le Makefile principal
echo "🔧 Génération du Makefile principal..."
cat > "$ROOT_DIR/Makefile" << EOF
NAME			:= ${NAME}
AR				:= ${AR}
CC				:= ${CC}
CFLAGS			:= ${CFLAGS}
BUILD			:= ${BUILD_DIR}
OBJDIR			:= ${OBJ_DIR}

CORE_MODULES	:= _core_
MODULES			?=
ALL_MODULES		:= \$(CORE_MODULES) \$(MODULES)

MKFILES := \$(wildcard src/_core_/makefile.mk) \$(foreach mod,\$(MODULES),src/\$(mod)/makefile.mk)
# MKFILES			:= \$(foreach mod,\$(ALL_MODULES),src/\$(mod)/makefile.mk)
include			\$(wildcard \$(MKFILES))

OBJECTS			:= ${ALL_OBJS}

.PHONY: all clean fclean re

all: \$(NAME)

\$(NAME): \$(OBJECTS)
	@mkdir -p \$(dir \$(NAME))
	\$(AR) \$(NAME) \$(OBJECTS)

clean:
	rm -f \$(OBJECTS)

fclean: clean
	rm -f \$(NAME)

re: fclean all
EOF

echo "✅ Fichiers Makefile générés avec succès."