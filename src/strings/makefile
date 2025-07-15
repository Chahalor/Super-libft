NAME	:= sft_string.a

CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -g3
AR		:= ar
ARFLAGS	:= rcs

RM		:= rm -f

INCLUDES := -I./ -I/home/nduvoid/Desktop/Super-libft/src/_internal_ -I_internal/ -I_internal/append -I_internal/check -I_internal/memory -I_internal/change

SRCS := \
	_internal/append/_append.c \
	_internal/check/_check.c \
	_internal/memory/_memory.c \
	_internal/change/_change.c \
	string.c

OBJS := $(SRCS:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY: all clean fclean re