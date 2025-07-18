math_INCLUDES := -I./src/math 
math_SRCS := \
    ./src/math/math.c \

math_OBJS := $(math_SRCS:%.c=.build/obj/%.o)
math_INCLUDES := -I./src/math 

$(math_OBJS): CFLAGS += $(math_INCLUDES)

$(math_OBJS):
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $(patsubst $(OBJDIR)/%.o,%.c,$@) -o $@
