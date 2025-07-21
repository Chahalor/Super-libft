/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/21 11:07:32 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----|  System  |-----*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

inline int	_show_help(
	const t_args_spec *specs,
	t_args_data *args_data
)
{
	register int	i;

	args_data->help = 1;
	printf("Usage: %s", args_data->argv[0]);
	i = -1;
	while (specs[++i].name)
	{
		if (specs[i].is_positional)
			printf(" <%s>", specs[i].name);
	}
	printf(" [options]\n\n"
			"Options:\n");
	i = -1;
	while (specs[++i].name)
	{
		if (specs[i].is_positional)
			printf("  -%c, --%s", specs[i].short_name, specs[i].name);
		if (specs[i].type == ARG_TYPE_STRING || specs[i].type == ARG_TYPE_FILE)
			printf(" <value>");
		else if (specs[i].type == ARG_TYPE_INT)
			printf(" <number>");
		printf("\n");
	}
	return (0);
}

#pragma endregion Functions