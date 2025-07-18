/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/18 09:02:13 by nduvoid          ###   ########.fr       */
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
static inline int	_is_hexa(
	const char c
)
{
	return (c >= '0' && c <= '9') || ((c | 0x20) >= 'a' && (c | 0x20) <= 'f');
}

__attribute__((always_inline, used))
static inline int	_read_number(
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
	scan->file->read(scan->file, &c, 1);
	nergative = 1 + -2 * (c == '-');
	while (scan->file->read(scan->file, &c, 1) > 0 && (c >= '0' && c <= '9'))
		*nbr = *nbr * 10 + (c - '0');
	*nbr *= nergative;
	return (1);
}

__attribute__((always_inline, used))
static inline int	_read_uint(
	t_sft_scan *const scan,
	const char format
)
{
	unsigned int *const	nbr = va_arg(scan->args, unsigned int *);
	char				c;

	(void)format;
	if (unlikely(!nbr))
		return (_register_error(EINVAL), scan->error = 1, -1);
	*nbr = 0;
	while (scan->file->read(scan->file, &c, 1) > 0 && (c >= '0' && c <= '9'))
		*nbr = *nbr * 10 + (c - '0');
	return (1);
}

__attribute__((always_inline, used))
static inline int	_read_hex(
	t_sft_scan *const scan,
	const char format
)
{
	int *const		nbr = va_arg(scan->args, int *);
	char			c;
	unsigned char	uc;
	int				digit;

	(void)format;
	if (unlikely(!nbr))
		return (_register_error(EINVAL), scan->error = 1, -1);
	*nbr = 0;
	while (scan->file->read(scan->file, &c, 1) > 0 && _is_hexa(c))
	{
		uc = (unsigned char)c;
		digit = (uc & 0xF) + 9 * ((uc & 0x40) >> 6);
		*nbr = *nbr * 16 + digit;
	}
	return (1);
}

__attribute__((visibility("hidden"), used))
int	_read_numbers(
	t_sft_scan *const scan,
	const char format
)
{
	if (format == 'd' || format == 'i')
		return (_read_number(scan, format));
	else if (format == 'u')
		return (_read_uint(scan, format));
	else if (format == 'x' || format == 'X')
		return (_read_hex(scan, format));
	else
		return (0);
}
#pragma endregion Functions