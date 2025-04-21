/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _methodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:15:03 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/21 11:15:49 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| interface |----- */
#include "args_parser.h"

/* -----| Internal  |----- */
#include "_args.h"

#pragma endregion Headers
#pragma region Functions

/**
 * return the option id
 */
__attribute__((cold)) int	add_option(
	t_parser *parser,
	char *name,
	char *doc,
	t_types type
)
{
	return (_add_option(parser, name, doc, type));
}

__attribute__((cold)) int	add_argument(
	t_parser *parser,
	char *name,
	char *doc,
	t_types type
)
{
	return (_add_argument(parser, name, doc, type));
}

/**
 * return the option
 */
__attribute__((cold)) void	*get_option(
	t_parser *parser
)
{
	return (_get_option(parse));
}

/** */
__attribute__((cold)) void	*get_arguments(
	t_parser *parser
)
{
	return (_get_arguments(parser));
}

#pragma endregion Functions