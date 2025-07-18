/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/18 09:05:01 by nduvoid          ###   ########.fr       */
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
	if (flag == 'd' || flag == 'i' || flag == 'u' || flag == 'x' || flag == 'X')
		return (_read_numbers(scan, (char)flag));
	else if (flag == 'c' || flag == 's' || flag == '%')
		return (_read_chars(scan, (char)flag));
	else
		return (_skip(scan, (char)flag));
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
		if (c == '%' && !_is_whitespace(scan->format[i + 1]))
			scan->nb_read += _get_flag(scan, scan->format[++i]);
		else
			scan->error = 1;
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