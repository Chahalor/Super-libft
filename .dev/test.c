typedef enum {
	TYPE_INT,
	TYPE_STRING,
	TYPE_BOOL,
	// ajoute plus ici si besoin
} ArgType;

typedef struct {
	char *name;
	char *help;
	ArgType type;
	union {
		int i_val;
		char *s_val;
		int b_val; // 0 ou 1
	} value;
} ArgOption;

typedef struct {
	ArgOption *options;
	int count;
	int capacity;
} Args;


void args_init(Args *args) {
	args->count = 0;
	args->capacity = 4;
	args->options = malloc(sizeof(ArgOption) * args->capacity);
}

void args_add_option(Args *args, const char *name, ArgType type, const char *help) {
	if (args->count >= args->capacity) {
		args->capacity *= 2;
		args->options = realloc(args->options, sizeof(ArgOption) * args->capacity);
	}
	ArgOption *opt = &args->options[args->count++];
	opt->name = strdup(name);
	opt->help = strdup(help);
	opt->type = type;

	// init default value
	if (type == TYPE_STRING)
		opt->value.s_val = NULL;
	else if (type == TYPE_INT || type == TYPE_BOOL)
		opt->value.i_val = 0;
}
