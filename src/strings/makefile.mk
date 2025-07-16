strings_INCLUDES := -I./src/strings -I./src/strings/_internal -I./src/strings/_internal/append -I./src/strings/_internal/check -I./src/strings/_internal/memory -I./src/strings/_internal/change 
strings_SRCS := \
    ./src/strings/_internal/append/_append.c \
    ./src/strings/_internal/check/_check.c \
    ./src/strings/_internal/memory/_memory.c \
    ./src/strings/_internal/change/_change.c \
    ./src/strings/string.c \

strings_OBJS := $(strings_SRCS:%.c=.build/obj/%.o)
strings_INCLUDES := -I./src/strings -I./src/strings/_internal -I./src/strings/_internal/append -I./src/strings/_internal/check -I./src/strings/_internal/memory -I./src/strings/_internal/change 

$(strings_OBJS): CFLAGS += $(strings_INCLUDES)

$(strings_OBJS):
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $(patsubst $(OBJDIR)/%.o,%.c,$@) -o $@
