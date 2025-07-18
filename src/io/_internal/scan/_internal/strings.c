/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 08:57:37 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/18 09:03:03 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----|  System  |-----*/
	//...

/* -----| Internal |-----*/
#include "_internal/_scan.h"
#include "io.h"

/* -----|   Core   |-----*/
#include "error/_error.h"
#include "shortcut/_shortcut.h"

/* -----|  Module  |-----*/
	//...

#pragma endregion Header
#pragma region    Functions

__attribute__((always_inline, used))
static inline int	_is_whitespace(
	const char c
)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

__attribute__((always_inline, used))
static inline int	_read_string(
	t_sft_scan *const scan,
	const char format
)
{
	char	*str = va_arg(scan->args, char *);
	char	c;
	int		i;

	(void)format;
	if (unlikely(!str))
		return (_register_error(EINVAL), scan->error = 1, -1);
	i = 0;
	while (scan->file->read(scan->file, &c, 1) > 0 && !_is_whitespace(c))
		str[i++] = c;
	return (1);
}

__attribute__((always_inline, used))
static inline int	_read_char(
	t_sft_scan *const scan,
	const char format
)
{
	char *const	c = va_arg(scan->args, char *);

	(void)format;
	if (unlikely(!c))
		return (_register_error(EINVAL), scan->error = 1, -1);
	if (scan->file->read(scan->file, c, 1) <= 0)
		return (_register_error(EIO), scan->error = 1, -1);
	return (1);
}

__attribute__((always_inline, used))
static inline int	_read_percent(
	t_sft_scan *const scan,
	const char format
)
{
	char *const	c = va_arg(scan->args, char *);

	(void)format;
	if (unlikely(!c))
		return (_register_error(EINVAL), scan->error = 1, -1);
	else if (scan->file->read(scan->file, c, 1) <= 0)
		return (_register_error(EIO), scan->error = 1, -1);
	else if (*c != '%')
		return (_register_error(EINVAL), scan->error = 1, -1);
	else
		return (1);
}

__attribute__((visibility("hidden"), used))
int	_read_chars(
	t_sft_scan *const scan,
	const char format
)
{
	if (format == 'c')
		return (_read_char(scan, format));
	else if (format == 's')
		return (_read_string(scan, format));
	else if (format == '%')
		return (_read_percent(scan, format));
	else
		return (0);
}

#pragma endregion Functions