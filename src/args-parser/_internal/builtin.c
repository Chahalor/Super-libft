/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/21 11:28:29 by nduvoid          ###   ########.fr       */
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

t_args_spec *_get_builtin_args(void)
{
	static t_args_spec	builtin[] = {
		{"help", 'h', ARG_TYPE_BOOL, "Show this help message", _show_help, NULL, 0, 0, 0},
		{NULL, '\0', ARG_TYPE_BOOL, NULL, NULL, NULL, 0, 0, 0}
	};
	return (builtin);
}

#pragma endregion Functions