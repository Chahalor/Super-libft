/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args-parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/21 11:29:24 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----|  System  |-----*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# include <string.h> //rm

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
	t_args_spec		*builtins;
	register int	i;
	register int	j;
	
	builtins = _get_builtin_args();
	i = -1;
	while (builtins[++i].name)
	{
		j = _strlen(builtins[i].name);
		if (!builtins[i]._is_set &&  strncmp(builtins[i].name, option, j) == 0)
		{
			fprintf(stderr, "builtin Option: <%s>\n", builtins[i].name); //rm
			builtins[i]._is_set = 1;
			return (j + 2 + ((int (*)(const t_args_spec *, t_args_data *))builtins[i].value_ptr)(builtins, args_data));
		}
	}
	while (specs[++i].name)
	{
		j = _strlen(specs[i].name);
		if (strncmp(specs[i].name, option, j) == 0)
		{
			fprintf(stderr, "long Option: <%s>\n", specs[i].name); //rm
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
	t_args_spec	*builtins;
	register int		i;

	builtins = _get_builtin_args();
	i = -1;
	while (builtins[++i].name)
	{
		if (builtins[i].short_name == option[0])
		{
			fprintf(stderr, "builtin Option: <-%c>\n", builtins[i].short_name); //rm
			builtins[i]._is_set = 1;
			return (2 + ((int (*)(const t_args_spec *, t_args_data *))builtins[i].value_ptr)(builtins, args_data));
		}
	}
	i = -1;
	while (specs[++i].name)
	{
		if (specs[i].short_name == option[0])
		{
			fprintf(stderr, "short Option: <-%c>\n", specs[i].short_name); //rm
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
		else if (!_isspace(args_data.one_string[i]))
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