_DIR_MODULE_STRINGS		:= strings
_DIR_INTERFACE_STRINGS	:= $(_DIR_MODULE_STRINGS)
_DIR_INTERNAL_STRINGS	:= $(_DIR_MODULE_STRINGS)/_internal

_SRC_INTERFACE_STRINGS	:= string.c 
_SRC_INTERNAL_STRINGS	:= append/_append.c check/_check.c memory/_memory.c change/_change.c 

_OBJ_STRINGS			:= $(addprefix $(DIR_OBJ)/$(_DIR_INTERFACE_STRINGS)/, $(_SRC_INTERFACE_STRINGS:.c=.o))
_OBJ_STRINGS			+= $(addprefix $(DIR_OBJ)/$(_DIR_INTERNAL_STRINGS)/, $(_SRC_INTERNAL_STRINGS:.c=.o))
_OBJ_ALL						+= $(_OBJ_STRINGS)

$(DIR_OBJ)/$(_DIR_MODULE_STRINGS)/%.o: $(DIR_SRC)/$(_DIR_MODULE_STRINGS)/%.c
	@mkdir -p $(dir $@)
	@printf "\r ⚙️ $(_YELLOW) Compiling$(_RESET) %-60s" "$<"
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -I$(DIR_SRC)/$(_DIR_MODULE_STRINGS)/_internal -c $< -o $@

