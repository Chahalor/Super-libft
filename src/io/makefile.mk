io_INCLUDES := -I./src/io -I./src/io/_internal 
io_SRCS := \
    ./src/io/_internal/_io.c \
    ./src/io/io.c \
    ./src/io/standard.c \

io_OBJS := $(io_SRCS:%.c=.build/obj/%.o)
io_INCLUDES := -I./src/io -I./src/io/_internal 

$(io_OBJS): CFLAGS += $(io_INCLUDES)

$(io_OBJS):
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $(patsubst $(OBJDIR)/%.o,%.c,$@) -o $@
