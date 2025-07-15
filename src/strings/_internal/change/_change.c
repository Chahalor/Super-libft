/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _change.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/15 13:46:23 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| System   |-----*/
#include <stddef.h>

/* -----| Internal |-----*/
#include "string.h"
#include "_change.h"
#include "_string.h"

/* -----| Module   |-----*/
	//...

#pragma endregion Header
#pragma region    Statics

static inline int	_is_whitespace(
	const char c
)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f');
}

#pragma endregion Statics
#pragma region    Functions

__attribute__((visibility("hidden"), used)) int	_sft_string_atoi(
	const t_string *const self
)
{
	char	negative;
	int		result;
	size_t	i;

	if (!self || !self->str)
		return (0);
	result = 0;
	i = 0;
	while (i < self->len && _is_whitespace(self->str[i]))
		++i;
	negative = (i < self->len && self->str[i] == '-');
	i += negative;
	while (i < self->len && self->str[i] >= '0' && self->str[i] <= '9')
	{
		result = result * 10 + (self->str[i] - '0');
		++i;
	}
	return (result * (1 - 2 * negative));
}

__attribute__((visibility("hidden"), used)) long	_sft_string_atol(
	const t_string *const self
)
{
	char	negative;
	long	result;
	size_t	i;

	if (!self || !self->str)
		return (0);
	result = 0;
	i = 0;
	while (i < self->len && _is_whitespace(self->str[i]))
		++i;
	negative = (i < self->len && self->str[i] == '-');
	i += negative;
	while (i < self->len && self->str[i] >= '0' && self->str[i] <= '9')
	{
		result = result * 10 + (self->str[i] - '0');
		++i;
	}
	return (result * (1 - 2 * negative));
}

__attribute__((visibility("hidden"), used)) float	_sft_string_atolf(
	const t_string *const self
)
{
	char	negative;
	float	result;
	float	fraction;
	float	divisor;
	size_t	i;

	if (!self || !self->str)
		return (0.0f);
	result = 0.0f;
	i = 0;
	while (i < self->len && _is_whitespace(self->str[i]))
		++i;
	negative = (i < self->len && self->str[i] == '-');
	i += negative;
	while (i < self->len && self->str[i] >= '0' && self->str[i] <= '9')
	{
		result = result * 10.0f + (self->str[i] - '0');
		++i;
	}
	// Gérer la partie fractionnaire après la virgule
	if (i < self->len && (self->str[i] == ',' || self->str[i] == '.'))
	{
		++i;
		fraction = 0.0f;
		divisor = 1.0f;
		while (i < self->len && self->str[i] >= '0' && self->str[i] <= '9')
		{
			fraction = fraction * 10.0f + (self->str[i] - '0');
			divisor *= 10.0f;
			++i;
		}
		result += fraction / divisor;
	}
	return (result * (1.0f - 2.0f * negative));
}

t_string	*_sft_string_itos(
	size_t value
)
{
	const char		negative = (value < 0);
	char			buffer[sizeof(size_t) * 8 + 1];
	register int	i;

	if (value == 0)
		return (new_t_string("0"));
	i = 0;
	if (negative)
	{
		value = -value;
		buffer[i++] = '-';
	}
	while (value != 0)
	{
		buffer[i++] = (value % 10) + '0';
		value /= 10;
	}
	buffer[i] = '\0';
	return (new_t_string(buffer));
}

#pragma endregion Functions