/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/17 08:37:34 by nduvoid          ###   ########.fr       */
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
	int					fd;
	t_file				*file;

	if (unlikely(!filename || !*filename))
		return (_register_error(EINVAL), NULL);
	fd = open(filename, mode, permissions);
	if (unlikely(fd < 0))
		return (_register_error(errno), NULL);
	file = _sft_io_open(fd, filename);
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