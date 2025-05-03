/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:10:18 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/22 14:58:13 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| interface |----- */
#include "args_parser.h"
#include "str.h"

/* -----| Internal  |----- */
#include "_args.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((cold)) static int	_parse_argument(
	t_args *arguments,
	register int i,
	const char **argv,
	t_error *error
)
{
	t_args	*current;

	if (__builtin_expect(!arguments, 0))
		return (0);
	current = arguments;
	while (current)
	{
		if (current->type == e_flag)
		{
			current->value.b_value = e_true;
			return (1);
		}
		else if (current->type == e_int)
		{
			current->value.i_value = ft_atoi(argv[i]);
			return (1);
		}
		else if (current->type == e_str)
		{
			if (argv[i])
			{
				current->value.s_value = ft_strdup(argv[i]);
				return (1);
			}
		}
	}
	*error = (t_error){.error = e_invalid_argument, .index = i, .pos = 0};
	return (-1);
}

/** */
__attribute__((cold)) static int	_parse_long_options(
	t_parser *parser,
	register int i,
	const char **argv,
	t_error *error
)
{
	register int	j;

	j = -1;
	while (argv[i] && parser->options[++j])
	{
		if (ft_strncmp(&argv[i][2], parser->options[j]->name,
			ft_strlen(parser->options[j]->name)) == 0)
		{
			parser->options[j]->used = 1;
			return (_parse_argument(parser->options[j]->argument, i + 1,
				argv, error) + 1);
		}
	}
	*error = (t_error){.error = e_invalid_option, .index = i, .pos = 2};
	return (-1);
}

/** */
__attribute__((cold)) static int	_parse_short_options(
	t_parser *parser,
	register int i,
	const char **argv,
	t_error *error
)
{
	register int	j;

	j = -1;
	while (argv[i] && parser->options[++j])
	{
		if (argv[i][1] == parser->options[j]->name[0] && argv[i][2] == '\0')
		{
			parser->options[j]->used = 1;
			return (_parse_argument(parser->options[j]->argument, i + 1, argv,
				error)) + 1;
		}
	}
	*error = (t_error){.error = e_invalid_option, .index = i, .pos = 1};
	return (-1);
}

/** */
__attribute__((cold)) int	_parse(
	t_parser *parser,
	int argc,
	const char **argv
)
{
	register int	i;
	t_error			error;

	error = (t_error){.error = 0, .index = -1, .index = -1};
	i = 0;
	while (i < argc && !error.error)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == '-')
				i += _parse_long_option(parser, i, argv, &error);
			else
				i += _parse_short_option(parser, i, argv, &error);
		}
		else
			i += _parse_argument(parser, i, argv, &error);
	}
	if (__builtin_expect(error.error, 0))
		;// error message logic
	return (i); // should be the number of options parsed
}

#pragma endregion Functions