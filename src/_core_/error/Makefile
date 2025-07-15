NAME := _error_.a

CC := cc
CFLAGS := -Wall -Wextra -Werror -g3
AR := ar
ARFLAGS := rcs

RM := rm -f

INCLUDES := -I./ -I_internal/

SRCS := \
	_internal/_error_.c \
	_error.c

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