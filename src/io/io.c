/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/16 18:40:19 by nduvoid          ###   ########.fr       */
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

__attribute__((used))
t_file	*sft_open(
	const char *const filename,
	const int mode,
	const int permissions
)
{
	const int			len = _strlen(filename) + 1;
	t_file				*file;
	struct s_sft_file	*_file;

	if (unlikely(!filename || !*filename))
		return (_register_error(EINVAL), NULL);
	file = malloc(sizeof(0
		+ sizeof(struct s_sft_file)
		+ sizeof(t_file)
		+ sizeof(char) * (len + 1)));
	if (unlikely(!file))
		return (_register_error(ENOMEM), NULL);
	_file = (struct s_sft_file *)(file);
	_file->fd = open(filename, mode, permissions);
	if (unlikely(_file->fd < 0))
		return (_register_error(errno), free(_file), NULL);
	_file->path = (char *)(_file + 1);
	_cpy(_file->path, filename, len, 1);
	_file->advance = 0;
	_file->eof = 0;
	_file->closed = 0;
	file->read = sft_read;
	file->write = sft_write;
	file->close = sft_close;
	return (file);
}

__attribute__((used))
ssize_t	sft_read(
	t_file *const file,
	void *buffer,
	size_t size
)
{
	struct s_sft_file	*_file;
	ssize_t				bytes_read;

	if (unlikely(!file || !buffer || !size))
		return (_register_error(EINVAL), -1);
	else if (unlikely(!size))
		return (0);
	_file = (struct s_sft_file *)file->data;
	if (unlikely(_file->eof || _file->closed))
		return (0);
	bytes_read = read(_file->fd, buffer, size);
	if (unlikely(bytes_read < 0))
		return (_register_error(errno), -1);
	else if (bytes_read < (ssize_t)size)
		_file->eof = 1;
	_file->advance += bytes_read;
	return (bytes_read);
}

__attribute__((used))
ssize_t	sft_write(
	t_file *const file,
	const void *const buffer,
	size_t size
)
{
	struct s_sft_file	*_file;
	ssize_t				bytes_written;

	if (unlikely(!file || !buffer || !size))
		return (_register_error(EINVAL), -1);
	else if (unlikely(!size))
		return (0);
	_file = (struct s_sft_file *)file->data;
	if (unlikely(_file->eof || _file->closed))
		return (_register_error(EINVAL), -1);
	bytes_written = write(_file->fd, buffer, size);
	if (unlikely(bytes_written < 0))
		return (_register_error(errno), -1);
	_file->advance += bytes_written;
	return (bytes_written);
}

__attribute__((used))
int	sft_close(
	t_file *file
)
{
	struct s_sft_file	*_file;
	
	if (unlikely(!file))
		return (_register_error(EINVAL), -1);
	_file = (struct s_sft_file *)file->data;
	if (likely(!_file->closed))
	{
		close(_file->fd);
		_file->closed = 1;
	}
	free(file);
	return (0);
}

__attribute__((visibility("hidden"), used))
t_file	**_get_default_io(void)
{
	static t_file	*default_io[3] = {NULL, NULL, NULL};

	// @todo
	return (default_io);
}

#pragma endregion Functions