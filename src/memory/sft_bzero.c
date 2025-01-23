/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sft_bzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:28:29 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/23 15:13:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

/**
 * @brief Set a block of memory with 0.
 * 
 * @param ptr Pointer to the block of memory to fill.
 * @param len Number of bytes to set.
 * 
 * @return void* Pointer to the memory block.
 * 
 * @details The `ft_bzero()` function sets the first `len` bytes of the memory
 * area pointed to by `ptr` to zero.
 */
void	ft_bzero(void *ptr, size_t len)
{
	ft_memset(ptr, 0, len);
}
