/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _initi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:48:23 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/17 18:26:44 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Includes"

/* Systeme */

/* Global */
	//...

/* Modules */
#include "args_parser.h"
#include "_args.h"

#pragma endregion Includes
#pragma region Functions

/** */
__attribute__((malloc)) static t_option	**add_default_option(
	void
)
{
	t_option	**new_option;

	new_option = (t_option **)malloc((NB_BUILTIN_OPTIONS + 1)
		* (sizeof(t_option *) + sizeof(t_option)));
	if (!new_option)
		return (NULL);
	*new_option[0] = (t_option){
		.name = "help", .doc = "Display this help message", .argument = NULL,
		.id = 0, .builtin = 1};
	new_option[1] = NULL;
	return (new_option);
}

/** */
__attribute__((cold, malloc, visibility("hidden"))) t_parser	*_parser_init(
	void
)
{
	t_parser	*new_parser;

	new_parser = (t_parser *)malloc(sizeof(t_parser));
	if (!new_parser)
		return (NULL);
	*new_parser = (t_parser){
		.options = add_default_option(),
		.nb_options = 1,
		.destroy = parser_destroy,
		.parse = parse,
		.add_option = add_option,
		.get_option = get_option,
	};
	return (new_parser);
}

#pragma endregion Functions