io_INCLUDES := -I./src/io -I./src/io/_internal -I./src/io/_internal/print -I./src/io/_internal/print/_internal -I./src/io/_internal/scan -I./src/io/_internal/scan/_internal 
io_SRCS := \
    ./src/io/_internal/_io.c \
    ./src/io/_internal/print/_internal/_utils.c \
    ./src/io/_internal/print/_internal/writer.c \
    ./src/io/_internal/print/ft_printf.c \
    ./src/io/_internal/print/interface.c \
    ./src/io/_internal/scan/_internal/numbers.c \
    ./src/io/_internal/scan/_internal/strings.c \
    ./src/io/_internal/scan/scan.c \
    ./src/io/io.c \
    ./src/io/standard.c \

io_OBJS := $(io_SRCS:%.c=.build/obj/%.o)
io_INCLUDES := -I./src/io -I./src/io/_internal -I./src/io/_internal/print -I./src/io/_internal/print/_internal -I./src/io/_internal/scan -I./src/io/_internal/scan/_internal 

$(io_OBJS): CFLAGS += $(io_INCLUDES)

$(io_OBJS):
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $(patsubst $(OBJDIR)/%.o,%.c,$@) -o $@
