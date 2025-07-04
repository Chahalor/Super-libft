/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/02 13:34:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| System   |-----*/
#include <stdlib.h>
#include <stdio.h> //rm

/* -----| Internal |-----*/
#include "_string.h"
#include "./string.h"

/* -----| Module   |-----*/
	//...

#pragma endregion Header
#pragma region Functions

__attribute__((visibility("hidden"), used)) void	_destroyer(
	t_string *self
)
{
	free(self->str);
	free(self);
}

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

static inline void	_strlencpy(
	char *const restrict dst,
	const char *const restrict src,
	const size_t len
)
{
	register size_t	i;

	if (!dst || !src || !len)
		return ;
	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
}

__attribute__((always_inline, used))
static inline t_string	*_string_init(
	t_string *const new_string,
	const size_t str_len
)
{
	new_string->str = (char *)malloc(sizeof(char) * (str_len + 1));
	new_string->len = str_len;
	new_string->append = (t_string_append){
		.t_string = _sft_string_append,
		.str = _sft_string_append_chr
	};
	new_string->check = (t_string_check){
		.cmp = _sft_string_cmp,
		.ncomp = _sft_string_ncmp,
		.find = _sft_string_char_find
	};
	new_string->memory = (t_string_memory){
		.duplicate = _sft_string_dup
	};
	new_string->destroy = _destroyer;
	return (new_string);
}

t_string	*new_t_string(
	const char *const restrict str
)
{
	const size_t	str_len = _strlen(str);
	const size_t	alloc_size = 0
		+ sizeof(t_string)
		+ sizeof(t_string_append)
		+ sizeof(t_string_check)
		+ sizeof(t_string_memory);
	t_string		*new_string;

	if (!str)
		return (NULL);
	new_string = (t_string *)malloc(alloc_size);
	if (!new_string)
		return (NULL);
	new_string = _string_init(new_string, str_len);
	if (!new_string->str)
		return (free(new_string), NULL);
	_strlencpy(new_string->str, str, str_len);
	return (new_string);
}

#pragma endregion Functions