/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 08:20:10 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/21 11:15:44 by nduvoid          ###   ########.fr       */
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
 * return a new parser
 */
__attribute__((cold, malloc)) t_parser	*parser_init(void)
{
	return (_parser_init());
}

/**
 * destroy the parser, return NULL anyway
 */
__attribute__((cold)) void	*parser_destroy(
	t_parser *parser
)
{
	return (_destroy_parser(parser));
}

/**
 * return the number of options parsed
 */
__attribute__((cold)) int	parse(
	t_parser *parser,
	int argc,
	const char **argv
)
{
	return (_parse(parser, argc, argv));
}

int	main(int argc, const char **argv)
{
	t_parser	*parser;

	parser = get_parser(NULL);
	if (!parser)
		return (1);
	parser->add_option(parser, "Help", "help doc", e_flag, NULL);	// this will be a default one
	parser->add_option(parser, "Int", "int doc", e_int, NULL);		// return the option id
	parser->add_option(parser, "String", "string doc", e_str, NULL);
	parser->add_option(parser, "Flag", "flag doc", e_flag, NULL);

	parser->parse(parser, argc, argv);

	parser->get_option(parser, "Help", e_flag);


	parser->destroy(parser);
}

#pragma endregion Functions