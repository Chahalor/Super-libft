/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/27 14:02:46 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| System   |-----*/
#include <stdint.h>

/* -----| Internal |-----*/
#include "/home/nduvoid/Desktop/Super-libft/src/strings/string.h"
#include "_check.h"
#include "_string.h"

/* -----| Module   |-----*/
	//...

#pragma endregion Header
#pragma region Functions

__attribute__((visibility("hidden"), used)) int	_sft_string_cmp(
	const t_string *const self,
	const t_string *const other
)
{
	const size_t	length_min = self->len * (other->len < self->len)
		+ other->len * (self->len < other->len);
	uint64_t		self_chunk;
	uint64_t		other_chunk;
	register size_t	i;

	i = 0;
	while (i + sizeof(uint64_t) <= length_min)
	{
		self_chunk = *(uint64_t *)(self->str + i);
		other_chunk = *(uint64_t *)(other->str + i);
		if (self_chunk != other_chunk)
			return (1);
		i += sizeof(uint64_t);
	}
	while (i < length_min)
	{
		if ((unsigned char)(self->str[i]) != (unsigned char)(other->str[i]))
			return (1);
		++i;
	}
	return (0);
}
// @todo: move this to an other place
static inline int	_min_2(const int a, const int b)
{
	return (a * (b < a) + b * (a < b));
}
static inline int	_min_3(const int a, const int b, const int c)
{
	return (_min_2(_min_2(a, b), c));
}

__attribute__((visibility("hidden"), used)) int	_sft_string_ncmp(
	const t_string *const self,
	const t_string *const other,
	const size_t n
)
{
	const size_t	length_min = _min_3(self->len, other->len, n);
	uint64_t		self_chunk;
	uint64_t		other_chunk;
	register size_t	i;

	i = 0;
	while (i + sizeof(uint64_t) <= length_min)
	{
		self_chunk = *(uint64_t *)(self->str + i);
		other_chunk = *(uint64_t *)(other->str + i);
		if (self_chunk != other_chunk)
			return (1);
		i += sizeof(uint64_t);
	}
	while (i < length_min)
	{
		if ((unsigned char)(self->str[i]) != (unsigned char)(other->str[i]))
			return (1);
		++i;
	}
	return (0);
}

/**
 * returns the index of the first occurrence of the target character in the string,
 */
__attribute__((visibility("hidden"), used)) size_t	_sft_string_char_find(
	const t_string *const self,
	const char *const target
)
{
	register size_t	i;
	register size_t	j;

	if (!self || !target)
		return (-1);
	i = -1;
	while (++i < self->len)
	{
		j = -1;
		while (target[++j] && (self->str[i] == target[j]))
			;
		if (!target[j])
			return (i);
	}
	return (-1);
}

#pragma endregion Functions