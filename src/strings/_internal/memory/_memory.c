/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _memory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/02 08:58:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| System   |-----*/
#include <stdint.h>
#include <stdlib.h>

/* -----| Internal |-----*/
#include "string.h"
#include "_string.h"
#include "_memory.h"

/* -----| Module   |-----*/
	//...

#pragma endregion Header
#pragma region Functions

static inline void	*_memdup(
	const void *const restrict src,
	const size_t size
)
{
	void	*new_mem;

	if (!src || !size)
		return (NULL);
	new_mem = malloc(size);
	if (!new_mem)
		return (NULL);
	register size_t	i;

	i = -1;
	while (++i < size)
		((unsigned char *)new_mem)[i] = ((unsigned char *)src)[i];
	return (new_mem);
}

/** */
__attribute__((visibility("hidden"), used)) t_string	*_sft_string_dup(
	const t_string *const self
)
{
	t_string	*new_string;

	if (!self)
		return (NULL);
	new_string = _memdup(self, sizeof(t_string));
	if (!new_string)
		return (NULL);
	new_string->str = _memdup(self->str, self->len + 1);
	return (new_string);
}

#pragma endregion Functions