/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sft_memmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:42:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/23 15:40:32 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

/**
 * @brief Copy a block of memory.
 * 
 * @param dest Pointer to the destination block of memory.
 * @param src Pointer to the source block of memory.
 * @param n Number of bytes to copy.
 * 
 * @return void* Pointer to the destination block of memory.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*d = dest;
	const unsigned char	*s = src;

	if (d < s)
		__asm__ (
			"rep movsb"
			: "=D" (d), "=S" (s), "=c" (n)
			: "D" (d), "S" (s), "c" (n)
			: "memory"
			);
	else
	{
		d += n - 1;
		s += n - 1;
		__asm__ (
			"std\n\t"
			"rep movsb\n\t"
			"cld"
			: "=D" (d), "=S" (s), "=c" (n)
			: "D" (d), "S" (s), "c" (n)
			: "memory"
			);
	}
	return (dest);
}
