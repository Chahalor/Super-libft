#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

typedef struct s_str t_str;

#pragma pack(push, 1)

struct s_str {
	char *c_str;
	int len;

	int (*print)(t_str *);
	t_str *(*copy)(t_str *);
	void (*destroy)(t_str *);
};

#pragma pack(pop)

int	str_print(t_str *s)
{
	printf("%s\n", s->c_str);
	return 0;
}

t_str	*str_copy(t_str *s)
{
	t_str *new = malloc(sizeof(t_str));
	new->c_str = strdup(s->c_str);
	new->len = s->len;
	new->print = str_print;
	new->copy = str_copy;
	new->destroy = s->destroy;
	return new;
}

void	str_destroy(t_str *s)
{
	free(s->c_str);
	free(s);
}

t_str	*str_new(const char *text)
{
	t_str *s = malloc(sizeof(t_str));
	s->c_str = strdup(text);
	s->len = strlen(text);
	s->print = str_print;
	s->copy = str_copy;
	s->destroy = str_destroy;
	return s;
}


int main() {
	t_str *s = str_new("Hello, World!");
	s->print(s);

	t_str *s_copy = s->copy(s);
	s_copy->print(s_copy);

	write(1, s_copy, 64);
	write(1, "\n", 1);

	s->destroy(s);
	s_copy->destroy(s_copy);

	return 0;
}