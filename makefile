# Big Header

MAKEFLAGS += --no-print-directory	# no Entering / Leaving messages

# ***************************************************** #
# *                VARIABLES                          * #
# ***************************************************** #

# Name of the executable
NAME :=			super-libft.a

CC :=			cc
CFLAGS =		-Wall -Wextra -Werror -I./$(DIR_INCL) -Isuper_libft.h
AR =			ar rcs
DEBUGFLAGS =
ARGS =

# Directories
DIR_SRC =	src
DIR_OBJ =	.obj
DIR_INCL =	includes

# ***************************************************** #
# *                     Path SRC                      * #
# ***************************************************** #

# directories
DIR_CHAR =	$(DIR_SRC)/char
DIR_IS =	$(DIR_SRC)/is
DIR_LIST =	$(DIR_SRC)/list
DIR_MATH =	$(DIR_SRC)/math
DIR_MEM =	$(DIR_SRC)/memory
DIR_STR =	$(DIR_SRC)/string
DIR_UTILS =	$(DIR_SRC)/utils

AR_MEM = $(DIR_MEM)/super-memory.a

AR_ALL = $(AR_MEM)

# ***************************************************** #
# *                      Main Rules                   * #
# ***************************************************** #

all: write_header norm $(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) compile

# ***************************************************** #
# *                 Compile Rule                      * #
# ***************************************************** #

.PHONY: compile

compile: $(DIR_OBJ) $(AR_ALL)
	@printf "\n"
	@echo "\033[32m ✅ Compilation done\033[0m"
	@$(AR) $(NAME) $(DIR_OBJ)/*.o
	@ranlib $(NAME)
#@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(OBJ) $(LIBFT)-o $(NAME) # compile commmand for executable
	@echo "\033[32m ✅ $(NAME) created\033[0m"

$(AR_MEM):
	@make -C $(DIR_MEM)
	@$(AR) $(AR_MEM)
	@ranlib $(AR_MEM)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

# ***************************************************** #
# *                    Clean Rules                    * #
# ***************************************************** #

.PHONY: clean fclean re

clean:
	@rm -rf $(DIR_OBJ)

fclean: clean
	@rm -f $(NAME)
	-@make -C $(DIR_MEM) fclean

re: fclean all

# ***************************************************** #
# *                    Debug Rules                    * #
# ***************************************************** #

.PHONY: debug debug.fsanitize debug.fs

debug:
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -g3 -D DEBUG=1)


debug.fsanitize: debug
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -fsanitize=address)

debug.fs: debug.fsanitize

# ***************************************************** #
# *                      Utils                        * #
# ***************************************************** #

.PHONY: run write_header norm reset_count make_norm compile_object write_goals

run:
	./$(NAME) $(ARGS)

write_header:
	@clear
	@printf "header"

norm:
	@$(call make_norm)

define make_norm
	@norminette $(DIR_SRC)/ super_libft.h > /tmp/norm_output.txt; \
	if grep -q " Error!" /tmp/norm_output.txt; then \
		cat /tmp/norm_output.txt | grep "Error"; \
		echo " ❌ \e[31mNorminette failed\e[0m"; \
	else \
		echo " ✅ \e[32mNorminette passed\e[0m"; \
	fi; \
	rm -- /tmp/norm_output.txt
endef

define write_goals
	line_size=97; \
	line="$(if $(MAKECMDGOALS), $(MAKECMDGOALS), all)"; \
	line_size=$$(( $$line_size - $${#line} )); \
	printf "║    \e[4mRule(s):\e[0m %s%*s\e[0m║\n" "$$line" $$line_size " "
endef

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
		printf " "
	@true
endef
