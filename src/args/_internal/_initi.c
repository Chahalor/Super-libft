/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _initi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:48:23 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/17 12:52:55 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Includes"

/* Systeme */
#include <errno.h>

/* Global */
	//...

/* Modules */
#include "args.h"
#include "_args.h"
#include "formating.h"

#pragma endregion Includes
#pragma region Functions

/** */
__attribute__((cold, malloc, visibility("hidden")))
t_parser	*_parser_init(void)
{
	t_parser	*new_parser;

	new_parser = (t_parser *)malloc(sizeof(t_parser));
	if (!new_parser)
	{
		errno = ENOMEM;
		return (NULL);
	}
	*new_parser = (t_parser){
		.version = {PARSER_MAJOR, PARSER_MINOR, PARSER_PATCH},
		.options = NULL,
		.count = 0,
		.destroy = NULL, // @todo
		.parse = NULL, // @todo
		.add_option = NULL, // @todo
		.get_option = NULL, // @todo
	};
	return (new_parser);
}

#pragma endregion Functions