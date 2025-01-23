/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sft_memcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:29:06 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/23 15:13:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

/**
 * @brief Copy a block of memory.
 * 
 * @param dest Pointer to the destination block of memory.
 * @param src Pointer to the source block of memory.
 * @param len Number of bytes to copy.
 * 
 * @return void* Pointer to the destination block of memory.
 * 
 * @details The `ft_memcpy()` function copies `len` bytes from memory area `src`
 * to memory area `dest`. The memory areas must not overlap.
 */
void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	__asm__ (
		"1:"
		"movb (%%rsi), %%al;"
		"movb %%al, (%%rdi);"
		"inc %%rsi;"
		"inc %%rdi;"
		"dec %%rcx;"
		"jnz 1b;"
		:
		: "S" (src), "D" (dest), "c" (len)
		: "rax", "memory"
		);
	return (dest);
}
