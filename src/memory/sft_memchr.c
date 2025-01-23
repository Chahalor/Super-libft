/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sft_memchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:21:56 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/23 15:40:43 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

void	*ft_memchr(const void *ptr, int c, size_t len)
{
	const unsigned char	*p = ptr;
	unsigned char		ch;

	ch = (unsigned char)c;
	__asm__ (
		"repne scasb"
		: "=D" (p), "=c" (len)
		: "D" (p), "a" (ch), "c" (len)
		: "memory"
		);
	if (len == 0)
		return (NULL);
	return ((void *)(p - 1));
}
