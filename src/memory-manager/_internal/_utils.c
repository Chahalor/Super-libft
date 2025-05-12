/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:33:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/12 11:06:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Interface |----- */
#include "mmanager.h"

/* -----| Internal  |----- */
#include "_mm.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((always_inline)) inline int _hash(
	const void *restrict ptr
)
{
	size_t x = (size_t)ptr;
	// Mélange les bits pour mieux répartir les valeurs
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = (x >> 16) ^ x;
	return (int)(x % MM_BUCKET_SIZE);
}

#include <string.h>
/** */
__attribute__((always_inline)) inline void	*mm_memcpy(
	void *restrict dst,
	const void *restrict src,
	const register size_t n
)
{
	register size_t	i;

	if (dst == NULL || src == NULL)
		return (NULL);
	if (n == 0)
		return (dst);
	i = -1;
	while (++i < n)
		((char *)dst)[i] = ((char *)src)[i];
	return (dst);
}

#pragma endregion Functions