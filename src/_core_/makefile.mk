_core__SRCS := \
    ./src/_core_/error/_internal/_error_.c \
    ./src/_core_/error/_error.c \
    ./src/_core_/memory/_internal/_memory_.c \
    ./src/_core_/memory/_memory.c \

_core__OBJS := $(_core__SRCS:%.c=.build/obj/%.o)
_core__INCLUDES := -I./src/_core_ -I./src/_core_/error -I./src/_core_/error/_internal -I./src/_core_/memory -I./src/_core_/memory/_internal 

$(_core__OBJS): CFLAGS += $(_core__INCLUDES)

$(_core__OBJS):
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $(patsubst $(OBJDIR)/%.o,%.c,$@) -o $@
