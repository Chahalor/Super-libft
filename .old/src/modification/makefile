# memory makefile

# variables
NAME :=	super-modif.a

CC :=		cc
CFLAGS =	-Wall -Wextra -Werror
AR =		ar rcs
INCFLAGS = 	-I./$(DIR_INCL)

# Directories

DIR_INCL =	../../
DIR_SRC =	.
DIR_OBJ =	../../.obj/

SRC =	sft_atoi.c

OBJ = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

# rules
.PHONY: all clean fclean re

all:  $(DIR_OBJ) $(NAME)

$(NAME): $(OBJ)
	@$(AR) $@ $^
	@echo "\n\033[32m[✔]\033[0m \033[1m$@\033[0m created"

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	$(call compile_object, $(INCFLAGS), $(OBJ), $(COLOR_YELLOW))

clean:
	@rm -rf $(DIR_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: reset_count compile_object
# Helper function to print a progress bar
# Credits: ugwentzi@student.42mulhouse.fr
#=- Progress Bar -=#
BAR_LENGTH =	42
PADDING =		10
COLOR_YELLOW =	\033[1;33m
COLOR_GREEN =	\033[1;32m
COLOR_CYAN =	\033[1;36m
COLOR_RED =		\033[31m
COLOR_RESET =	\033[0m

reset_count:
	$(eval COUNT := 0)

define compile_object
	$(eval COUNT := $(shell echo $$(( $(COUNT) + 1 ))))
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(1) -c $< -o $@
	@printf "\r$(3)\bCompiling %s%*s[%-$(BAR_LENGTH)s] %d/%d$(COLOR_RESET)" \
		"$<" \
		$$(($(PADDING) - $$(echo -n "$(NAME)" | wc -c))) "" \
		$(shell printf '=%.0s' $$(seq 1 $$(echo "$$(( $(BAR_LENGTH) * $(COUNT) / $(words $(2)) ))"))) \
		$(COUNT) \
		$(words $(2))
	@true
	@printf " "
endef

