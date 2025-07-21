/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args-parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/21 10:31:50 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----|  System  |-----*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
# include <ctype.h> // rm

/* -----| Internal |-----*/
#include "_internal/_args-parser.h"
#include "args-parser.h"

/* -----|   Core   |-----*/
#include "_core_/config.h"
#include "_core_/memory/_memory.h"
#include "_core_/error/_error.h"
#include "_core_/shortcut/_shortcut.h"

/* -----|  Module  |-----*/
	//...

#pragma endregion Header
#pragma region    Statics

static inline int	_word_size(
	const char *str
)
{
	int	size;

	if (unlikely(!str))
		return (0);
	while (*str && isspace(*str))
		++str;
	size = 0;
	while (str[size] && !isspace(str[size]))
		++size;
	return (size);
}

static inline int	_count_digits(
	char *n
)
{
	int	count;

	if (!n)
		return (0);
	count = 0;
	while (*n)
	{
		if (isdigit(*n))
			++count;
		++n;
	}
	return (count);
}

static inline char	*_worddup(
	const char *s
)
{
	char	*dup;
	size_t	len;

	if (!s)
		return (NULL);
	while (*s && isspace(*s))
		++s;
	len = _word_size(s);
	dup = (char *)_mem_alloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	strncpy(dup, s, len);
	dup[len] = '\0';
	return (dup);
}

#pragma endregion Statics
#pragma region    Functions

static inline int	_set_value(
	t_args_spec *spec,
	const char *value,
	t_args_data *args_data
)
{
	++args_data->nb_parsed;
	spec->_is_set = 1;
	if (spec->type == ARG_TYPE_BOOL)
	{
		*(int *)(spec->value_ptr) = 1;
		return (0);
	}
	else if (spec->type == ARG_TYPE_INT)
	{
		*(int *)(spec->value_ptr) = atoi(value);
		return (_count_digits((char *)value));
	}
	else if (spec->type == ARG_TYPE_STRING || spec->type == ARG_TYPE_FILE)
	{
		*(char **)(spec->value_ptr) = _worddup(value);
		return (_word_size(value));
	}
	else
		return (0);
}

static inline int	handle_long_option(
	const char *option,
	t_args_spec *specs,
	t_args_data *args_data
)
{
	register int	i;
	register int	j;

	i = -1;
	while (specs[++i].name)
	{
		j = _strlen(specs[i].name);
		if (strncmp(specs[i].name, option, j) == 0)
		{
			fprintf(stderr, "long Option: <%s>\n", specs[i].name);
			return (j + 2 + _set_value(&specs[i], option + j + 1, args_data));
		}
	}
	args_data->error = 1;
	return (-1);
}

static inline int	handle_short_option(
	const char *option,
	t_args_spec *specs,
	t_args_data *args_data
)
{
	register int	i;

	(void)args_data;
	i = -1;
	while (specs[++i].name)
	{
		if (specs[i].short_name == option[0])
		{
			fprintf(stderr, "short Option: <-%c>\n", specs[i].short_name);
			return (2 + _set_value(&specs[i], option + 1, args_data));
		}
	}
	return (0);
}

static inline int	handle_positional_argument(
	const char *arg,
	t_args_spec *specs,
	t_args_data *args_data
)
{
	register int	i;

	i = -1;
	while (specs[++i].name)
	{
		if (specs[i].is_positional && !specs[i]._is_set)
		{
			return (_set_value(&specs[i], arg, args_data));
		}
	}
	return (1);
}

__attribute__((malloc))
static inline char	*cat_options(
	const int argc,
	const char **argv
)
{
	char	*result;
	int		i;
	int		total_length;

	total_length = 0;
	i = 0;
	while (++i < argc)
		total_length += _strlen(argv[i]) + 1;
	result = (char *)_mem_alloc((total_length + 1) * sizeof(char));
	if (unlikely(!result))
		return (NULL);
	i = 0;
	while (++i < argc - 1)
	{
		strcat(result, argv[i]);
		strcat(result, " ");
	}
	strcat(result, argv[argc - 1]);
	return (result);
}

int	args_parser(
	const int argc,
	const char ** argv,
	t_args_spec *specs
)
{
	t_args_data	args_data;
	register int	i;

	args_data = (t_args_data){.argc = argc, .argv = (char **)argv};
	args_data.one_string = cat_options(argc, argv);
	if (unlikely(!args_data.one_string))
		return (-1);
	fprintf(stderr, "One string: <%s>\n", args_data.one_string);	//rm
	i = 0;
	while (args_data.one_string[i] && !args_data.error)
	{
		if (args_data.one_string[i] == '-')
		{
			if (args_data.one_string[i + 1] == '-')
				i += handle_long_option(&args_data.one_string[i + 2], specs, &args_data);
			else
				i += handle_short_option(&args_data.one_string[i + 1], specs, &args_data);
		}
		else if (!isspace(args_data.one_string[i]))
			i += handle_positional_argument(&args_data.one_string[i], specs, &args_data);
		else
			++i;
	}
	_mem_free(args_data.one_string);
	if (args_data.error)
		return (printf("Error parsing arguments\n"), -1);
	else
		return (args_data.nb_parsed);
}

#pragma endregion Functions