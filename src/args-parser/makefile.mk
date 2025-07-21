args-parser_INCLUDES := -I./src/args-parser -I./src/args-parser/_internal 
args-parser_SRCS := \
    ./src/args-parser/args-parser.c \

args-parser_OBJS := $(args-parser_SRCS:%.c=.build/obj/%.o)
args-parser_INCLUDES := -I./src/args-parser -I./src/args-parser/_internal 

$(args-parser_OBJS): CFLAGS += $(args-parser_INCLUDES)

$(args-parser_OBJS):
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $(patsubst $(OBJDIR)/%.o,%.c,$@) -o $@
