NAME			:= Super-Libft.a
AR				:= ar rcs
CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -MMD -Isrc/ -Isrc/_core_
BUILD			:= .build
OBJDIR			:= .build/obj

CORE_MODULES	:= _core_
MODULES			?=
ALL_MODULES		:= $(CORE_MODULES) $(MODULES)

MKFILES := $(wildcard src/_core_/makefile.mk) $(foreach mod,$(MODULES),src/$(mod)/makefile.mk)
# MKFILES			:= $(foreach mod,$(ALL_MODULES),src/$(mod)/makefile.mk)
include			$(wildcard $(MKFILES))

OBJECTS			:=  $(_core__OBJS) $(io_OBJS) $(math_OBJS) $(strings_OBJS)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@mkdir -p $(dir $(NAME))
	$(AR) $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean:
	rm -rf $(BUILD) $(NAME)

re: fclean all
