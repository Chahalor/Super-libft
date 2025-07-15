NAME := _memory_.a

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
AR := ar
ARFLAGS := rcs

RM := rm -f

INCLUDES := -I./ -I_internal/ -I../

SRCS := \
	_internal/_memory_.c \
	_memory.c

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