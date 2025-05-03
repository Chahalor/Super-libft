# Big Header #

# ***************************************************** #
# *                 Configuation                      * #
# ***************************************************** #

MAKEFLAGS += --no-print-directory

# ***************************************************** #
# *                 Variables                         * #
# ***************************************************** #

# Compilation
NAME		:= libft.a
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
AR			:= ar
ARFLAGS		:= rcs

# Directories
DIR_SRC		:= src
DIR_BUILD	:= .build
DIR_HEADER	:=

# Source files
SRC_MEMORY	:=
SRC_STRING	:=
SRC_LIST	:=
SRC_MATH	:=
SRC_ARGS	:=
include $(DIR_SRC)/memory_manager/makefile.mk
SRC_PRINTF	:=
SRC_GNL		:=

# Object files
OBJ_MEMORY	:= $(patsubst $(DIR_SRC)/%.c,$(DIR_BUILD)/%.o,$(SRC_MEMORY))
OBJ_STRING	:= $(patsubst $(DIR_SRC)/%.c,$(DIR_BUILD)/%.o,$(SRC_STRING))
OBJ_LIST	:= $(patsubst $(DIR_SRC)/%.c,$(DIR_BUILD)/%.o,$(SRC_LIST))
OBJ_MATH	:= $(patsubst $(DIR_SRC)/%.c,$(DIR_BUILD)/%.o,$(SRC_MATH))
OBJ_ARGS	:= $(patsubst $(DIR_SRC)/%.c,$(DIR_BUILD)/%.o,$(SRC_ARGS))
OBJ_MM		:= $(patsubst $(DIR_SRC)/%.c,$(DIR_BUILD)/%.o,$(SRC_MM))
OBJ_PRINTF	:= $(patsubst $(DIR_SRC)/%.c,$(DIR_BUILD)/%.o,$(SRC_PRINTF))
OBJ_GNL		:= $(patsubst $(DIR_SRC)/%.c,$(DIR_BUILD)/%.o,$(SRC_GNL))
OBJ_ALL		:= $(OBJ_MM_ALL)


# ***************************************************** #
# *                 Compiling Tag                     * #
# ***************************************************** #

# Compiling Tag

TAG_LIBFT		= false	# default libft
TAG_ADVANCED	= false	# advanced

MODULES := MEMORY STRING LIST MATH ARGS MM PRINTF GNL

# Initialise tous les TAG_* à false
$(foreach m,$(MODULES),$(eval TAG_$(m) := false))

GROUP_LIBFT := MEMORY STRING
GROUP_ADVANCED := LIST MATH ARGS MM PRINTF GNL

# ***************************************************** #
# *                 Rules                             * #
# ***************************************************** #

.PHONY: all bonus libft advanced printf gnl memory string list math args mm

# Rules

all: libft $(NAME)

bonus: list libft $(NAME)

libft:
	$(foreach m,$(GROUP_LIBFT),$(eval TAG_$(m) := true))

advanced:
	$(foreach m,$(GROUP_ADVANCED),$(eval TAG_$(m) := true))

	$(foreach m,$(MODULES),$(eval $(shell echo $(m) | tr A-Z a-z)): $(eval TAG_$(m) := true))

# ***************************************************** #
# *                 Internal                          * #
# ***************************************************** #

.PHONY: update_obj

update_obj:
	$(foreach m,$(MODULES),\
		$(if $(filter true,$(TAG_$(m))),\
			$(eval OBJ_ALL += $(OBJ_$(m)))\
		)\
	)

define generate_tag_rule
$(1):
	$(eval TAG_$(shell echo $(1) | tr a-z A-Z) := true)
endef

# ***************************************************** #
# *                 Compilation                       * #
# ***************************************************** #

compile: update_obj $(NAME)

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(DIR_HEADER) -c $< -o $@

$(NAME): update_obj
	$(AR) $(ARFLAGS) $@ $(OBJ_ALL)

# ***************************************************** #
# *                 Clean                            * #
# ***************************************************** #

.PHONY: clean fclean re

clean:
	@rm -rf $(DIR_BUILD)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# ***************************************************** #
# *                 Debugging                         * #
# ***************************************************** #

.PHONY: debug debug.fs

debug:
	$(eval CFLAGS := $(CFLAGS) -g3)

debug.fs: debug
	$(eval CFLAGS := $(CFLAGS) -fsanitize=address)

info:
	@echo "CFLAGS: $(CFLAGS)"
	@echo "ARFLAGS: $(ARFLAGS)"
	@echo "CC: $(CC)"
	@echo "AR: $(AR)"
	@echo "NAME: $(NAME)"
	@echo "DIR_SRC: $(DIR_SRC)"
	@echo "DIR_BUILD: $(DIR_BUILD)"
	@echo "DIR_HEADER: $(DIR_HEADER)"
	@echo "SRC_MEMORY: $(SRC_MEMORY)"
	@echo "SRC_STRING: $(SRC_STRING)"
	@echo "SRC_LIST: $(SRC_LIST)"
	@echo "SRC_MATH: $(SRC_MATH)"
	@echo "SRC_ARGS: $(SRC_ARGS)"
	@echo "SRC_MM: $(SRC_MM)"
	@echo "SRC_PRINTF: $(SRC_PRINTF)"
	@echo "SRC_GNL: $(SRC_GNL)"
	@echo "OBJ_ALL: $(OBJ_ALL)"