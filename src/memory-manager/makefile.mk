SRC_MM			:= mm.c 
SRC_INTERNAL_MM	:= _mm.c 

OBJ_MM			:= $(patsubst $(DIR_SRC)/%.c,$(DIR_BUILD)/%.o,$(SRC_MM))
OBJ_INTERNAL_MM	:= $(patsubst $(DIR_SRC)/%.c,$(DIR_BUILD)/%.o,$(SRC_INTERNAL_MM))

OBJ_MM_ALL		:= $(OBJ_MM) $(OBJ_INTERNAL_MM)

# compile module
$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $< -> $@"