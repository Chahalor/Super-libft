/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _append.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/02 13:31:21 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| System   |-----*/
#include <stdlib.h>

/* -----| Internal |-----*/
#include "../../string.h"
#include "_append.h"
#include "_string.h"

/* -----| Module   |-----*/
	//...

#pragma endregion Header
#pragma region Functions

static inline size_t	_strlen(
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

static inline void	_cat(
	const char *const restrict str1,
	const char *const restrict str2,
	char *const restrict dst
)
{
	register size_t	i;
	register size_t	j;

	i = -1;
	while (str1[++i])
		dst[i] = str1[i];
	j = -1;
	while (str2[++j])
		dst[i + j] = str2[j];
	dst[i + j] = '\0';
}

/** */
__attribute__((visibility("hidden"), used)) t_string	*_sft_string_append(
	t_string *self,
	const t_string *const other
)
{
	const size_t		total = self->len + other->len + 1;
	char				*tmp;

	tmp = (char *)malloc(sizeof(char) * total);
	if (!tmp)
		return (NULL);
	_cat(self->str, other->str, tmp);
	free(self->str);
	self->str = tmp;
	self->len = total - 1;
	return (self);
}

/** */
__attribute__((visibility("hidden"), used)) t_string	*_sft_string_append_chr(
	t_string *self,
	const char *const other
)
{
	const size_t		total = self->len + _strlen(other) + 1;
	char				*tmp;

	tmp = (char *)malloc(sizeof(char) * total);
	if (!tmp)
		return (NULL);
	_cat(self->str, other, tmp);
	free(self->str);
	self->str = tmp;
	self->len = total - 1;
	return (self);
}

#pragma endregion Functions