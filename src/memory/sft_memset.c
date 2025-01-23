/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sft_memset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:16:04 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/23 10:09:58 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.(t_uchar)value                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:38:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/23 08:47:47 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super-libft.h"

/**
 * @brief Set a block of memory with a specific value.
 * 
 * @param ptr Pointer to the block of memory to fill.
 * @param value Value to set.
 * @param len Number of bytes to set.
 * 
 * @return void* Pointer to the memory block.
 * 
 * @details The `ft_memset()` function fills the first `len` bytes of the
 * memory area pointed to by `ptr` with the constant byte `(t_uchar)value`.
 * 
 * @example 
 * 	ft_memset(ptr, 0, 10); // Fill the first 10 bytes of `ptr` with 0.
 */
void	*ft_memset(void *ptr, int value, size_t len)
{
	t_ullong	pattern64;
	t_uint		pattern32;

	pattern64 = (t_ullong)(t_uchar)value * 0x0101010101010101ULL;
	pattern32 = (t_uint)(t_uchar)value * 0x01010101U;
	while (len-- > 0 && ((uintptr_t)(t_uchar *)ptr % sizeof(t_ullong)) != 0)
		*(t_uchar *)ptr++ = (t_uchar)value;
	while (len >= sizeof(t_ullong))
	{
		*(t_ullong *)(t_uchar *)ptr = pattern64;
		*(t_uchar *)ptr += sizeof(t_ullong);
		len -= sizeof(t_ullong);
	}
	while (len >= sizeof(t_uint))
	{
		*(t_uint *)(t_uchar *)ptr = pattern32;
		*(t_uchar *)ptr += sizeof(t_uint);
		len -= sizeof(t_uint);
	}
	while (len-- > 0)
		*(t_uchar *)ptr++ = (t_uchar)value;
	return (ptr);
}
