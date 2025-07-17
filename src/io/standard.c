/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/17 15:31:32 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----|  System  |-----*/
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

/* -----| Internal |-----*/
#include "_internal/_io.h"
#include "io.h"

/* -----|   Core   |-----*/
#include "error/_error.h"
#include "shortcut/_shortcut.h"

/* -----|  Module  |-----*/
	//...

#pragma endregion Header
#pragma region    Functions

__attribute__((used, pure))
static t_file	*_get_std(
	const int stdnb
)
{
	static t_file	std_files[3] = {
		{.data = {0}, .read = sft_read, .print = sft_printf, .close = sft_close},
		{.data = {0}, .read = sft_read, .print = sft_printf, .close = sft_close},
		{.data = {0}, .read = sft_read, .print = sft_printf, .close = sft_close}
	};

	((struct s_sft_file *)(std_files[stdnb].data))->std = 1;
	return (&std_files[stdnb]);
}

__attribute__((used))
t_file	*sftout(void)
{
	return (_get_std(0));
}

__attribute__((used))
t_file	*sftin(void)
{
	return (_get_std(1));
}

__attribute__((used))
t_file	*sfterr(void)
{
	return (_get_std(2));
}

#pragma endregion Functions