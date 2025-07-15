/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _manager.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 08:22:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/24 08:47:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| interface |----- */
#include "args_parser.h"

/* -----| Internal  |----- */
#include "_args.h"

#pragma endregion Headers
#pragma region Functions

void	*_add_arg(
	t_parser *const restrict parser,
	const t_args *option
)
{
	if (parser->nb_options >= MAX_OPTIONS)
		return (NULL);
	parser->options[parser->nb_options++] = option;
	return (&parser->options[parser->nb_options - 1]);
}

void	*_add(
	t_parser *const restrict parser,
	void *const restrict data,
	const int access
)
{
	const struct s_access *const restrict	access_data = data;

	if (__builtin_expect(!data, 0))
		return (NULL);
	else if (access_data->access == e_access_args)
		return (_add_arg(t_args *)access_data->data, parser);
	else if (access_data->access == e_access_options)
		return (_add_option(t_option *)access_data->data, parser);
	else
		return (NULL);
}

void	*_load_default(
	t_parser *const restrict parser
)
{
	_add_args(parser, &(t_option){"help", "Display help information", NULL, 0, 0});
}

void	*_args_manager(
	void *const restrict data,
	const int access
)
{
	static t_parser	parser = {0};

	if (access == e_args_add)
		return (_add(&parser, data, access));
	else if (access == e_args_get)
		return (_get(&parser));
	else if (access == e_args_parse)
		return (_parse(&parser));
	else if (__builtin_expect(!parser.first_access, 0))
		return (_load_default(&parser));
	else
		return (NULL);
}

#pragma endregion Functions