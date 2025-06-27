/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _append.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/27 16:50:14 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| System   |-----*/
#include <stdlib.h>

/* -----| Internal |-----*/
#include "strings/string.h"
#include "_append.h"
#include "_string.h"

/* -----| Module   |-----*/
	//...

#pragma endregion Header
#pragma region Functions

__attribute__((always_inline, used))
static inline size_t	ft_strlen(
	const char *const restrict str
)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		++len;
	return (len);
}

__attribute__((always_inline, used))
static inline t_string_internal	*_realloc(
	t_string_internal *const internal,
	const size_t new_size
)
{
	t_string		*new_data;
	register size_t	i;

	new_data = (t_string *)malloc(sizeof(t_string) + sizeof(char) * new_size);
	if (!new_data)
		return (NULL);
	i = -1;
	while (++i < internal->data->len)
		new_data->str[i] = internal->data->str[i];
	free(internal->data->str);
	free(internal->data);
	internal->data = new_data;
	internal->alloc_size = new_size;
	return (internal);
}

__attribute__((always_inline, used))
static inline void	_cat(
	const t_string *const self,
	const char *const other,
	const size_t other_len
)
{
	t_string_internal	*internal;
	register int		i;

	i = self->len - 1;
	while (++i < (self->len + other_len))
		self->str[i] = other[i - self->len];
	self->str[self->len + other_len] = '\0';
	internal = (t_string_internal *)(self - offsetof(t_string_internal, data));
	internal->data->len += other_len;
}

__attribute__((visibility("hidden"), used)) t_string	*_sft_string_append(
	const t_string *const self,
	const t_string *const other
)
{
	t_string_internal	*internal;

	if (!self || !other)
		return (NULL);
	internal = (t_string_internal *)(self - offsetof(t_string_internal, data));
	if (self->len + other->len + 1 > internal->alloc_size)
	{
		internal = _realloc(internal, internal->alloc_size + other->len + 1);
		if (!internal)
			return (NULL);
	}
	_cat(self, other->str, other->len);
	return (&internal->data);
}

__attribute__((visibility("hidden"), used)) t_string	*_sft_string_append_chr(
	const t_string *const self,
	const char *const other
)
{
	const int			other_len = ft_strlen(other);
	t_string_internal	*internal;

	if (!self)
		return (NULL);
	internal = (t_string_internal *)(self - offsetof(t_string_internal, data));
	if (self->len + other_len + 1 > internal->alloc_size)
	{
		internal = _realloc(internal, internal->alloc_size + other_len + 1);
		if (!internal)
			return (NULL);
	}
	_cat(self, other, other_len);
	return (&internal->data);
}

#pragma endregion Functions