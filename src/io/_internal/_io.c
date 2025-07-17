/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _io.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/17 15:27:49 by nduvoid          ###   ########.fr       */
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

t_file	*_sft_io_open(
	const int fd,
	const char *const filename
)
{
	const int			len = _strlen(filename) + 1;
	t_file				*file;
	struct s_sft_file	*_file;

	file = (t_file *)malloc(0
		+ sizeof(struct s_sft_file)
		+ sizeof(t_file)
		+ sizeof(char) * (len + 1));
	if (unlikely(!file))
		return (_register_error(ENOMEM), NULL);
	_file = (struct s_sft_file *)(file);
	_file->fd = fd;
	_file->path = (char *)(_file + 1);
	_cpy(_file->path, filename, len, 1);
	_file->advance = 0;
	_file->eof = 0;
	_file->closed = 0;
	_file->std = !filename;
	file->read = sft_read;
	file->print = sft_printf;
	file->close = sft_close;
	return (file);
}

#pragma endregion Functions