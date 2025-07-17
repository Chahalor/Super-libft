/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/17 15:31:13 by nduvoid          ###   ########.fr       */
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

static inline int	_is_whitespace(
	const char c
)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

__attribute__((visibility("hidden"), used))
int	_read_number(
	t_sft_scan *const scan,
	const char format
)
{
	int *const	nbr = va_arg(scan->args, int *);
	char		nergative;
	char		c;

	(void)format;
	if (unlikely(!nbr))
		return (_register_error(EINVAL), scan->error = 1, -1);
	nergative = 1;
	while (scan->file->read(scan->file, &c, 1) > 0 && _is_whitespace(c))
		*nbr = *nbr * 10 + (c - '0');
	*nbr *= nergative;
	return (1);
}

__attribute__((visibility("hidden"), used))
int	_read_hex(
	t_sft_scan *const scan,
	const char format
)
{
	int *const	nbr = va_arg(scan->args, int *);
	char		c;
	int			value;

	(void)format;
	if (unlikely(!nbr))
		return (_register_error(EINVAL), scan->error = 1, -1);
	*nbr = 0;
	while (scan->file->read(scan->file, &c, 1) > 0 && !_is_whitespace(c))
	{
		value = (c & 0xF) + 9 * ((('9' - c) >> 7) & 1) + 10 * (((((c | 0x20) - 'a') >> 7) ^ 1) & 1);
		if (!(
			(c >= '0' && c <= '9') ||
			(c >= 'a' && c <= 'f') ||
			(c >= 'A' && c <= 'F')
		))
			break ;
		*nbr = (*nbr << 4) | value;
		++scan->nb_read;
	}
	return (1);
}

__attribute__((visibility("hidden"), used))
int	_read_string(
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

__attribute__((visibility("hidden"), used))
int	_skip(
	t_sft_scan *const scan,
	const char format
)
{
	(void)scan;
	(void)format;
	return (1);
}

static inline char	_get_flag(
	t_sft_scan *const scan,
	const int flag
)
{
	static int (*const funcs[])(t_sft_scan *const, const char) = {
		['d'] = _read_number,
		['i'] = _read_number,
		['u'] = _skip,
		['x'] = _read_hex,
		['X'] = _read_hex,
		['f'] = _skip,
		['c'] = _skip,
		['s'] = _read_string,
		['p'] = _skip,
		['%'] = _skip,
	};

	return (funcs[flag](scan, flag));
}

static inline void	_scaning(
	t_sft_scan *const scan
)
{
	int		i;
	char	c;

	i = -1;
	while (scan->format[++i] && !scan->error)
	{
		c = scan->format[i];
		if (c == '%')
		{
			i += _get_flag(scan, scan->format[i + 1]);
		}
		else
			++scan->error;
	}
}

int	sft_scan(
	t_file *const file,
	const char *const restrict format,
	...
)
{
	t_sft_scan	scan;

	if (unlikely(!file || !format))
		return (_register_error(EINVAL), -1);
	scan.file = file;
	if (unlikely(scan.file < 0))
		return (_register_error(EINVAL), -1);
	va_start(scan.args, format);
	scan.format = (char *)format;
	scan.nb_read = 0;
	scan.error = 0;
	_scaning(&scan);
	return (scan.nb_read);
}

#pragma endregion Functions