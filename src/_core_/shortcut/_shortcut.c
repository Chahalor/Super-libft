/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _shortcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/16 18:37:07 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----|  System  |-----*/
#include <stdlib.h>

/* -----| Internal |-----*/
// #include "internal/shortcut.h"
#include "_shortcut.h"

/* -----|   Core   |-----*/
#include "error/_error.h"

/* -----|  Module  |-----*/
	//...

#pragma endregion Header
#pragma region    Functions

__attribute__((always_inline, used))
inline int	likely(
	const int cond
)
{
	return (__builtin_expect(cond, 1));
}

__attribute__((always_inline, used))
inline int	unlikely(
	const int cond
)
{
	return (__builtin_expect(cond, 0));
}

__attribute__((always_inline, used))
inline int	_strlen(
	const char *const str
)
{
	int	len;

	if (unlikely(!str))
		return (0);
	len = -1;
	while (str[++len])
		;
	return (len);
}

__attribute__((always_inline, used))
inline void	_cpy(
	char *const dest,
	const char *const src,
	const size_t n,
	const int mode
)
{
	size_t	i;

	if (unlikely(!dest || !src || !n))
		return ;
	i = -1;
	while (++i < n && src[i])
		dest[i] = src[i];
	if (mode)
		dest[i] = '\0';
}

#pragma endregion Functions