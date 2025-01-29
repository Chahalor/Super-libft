/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sft_memchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:21:56 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/29 12:14:00 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

#if defined(__GNUC__) || defined(__clang__)

/**
 * @brief Locate a character in a block of memory.
 * 
 * @param ptr Pointer to the block of memory to search.
 * @param c Character to search for.
 * @param len Number of bytes to search.
 * 
 * @return void* Pointer to the matching byte or NULL if the character does not
 * occur in the block of memory.
 * 
 * @details Use the built-in function `__builtin_memchr()` to locate the first
 * occurrence of `c` (converted to an unsigned char) in the initial `len` bytes
 * of the memory area pointed to by `ptr`.
 */
void	*ft_memchr(const void *ptr, int c, size_t len)
{
	return (__builtin_memchr(ptr, c, len));
}

#else

/**
 * @brief Locate a character in a block of memory.
 * 
 * @param ptr Pointer to the block of memory to search.
 * @param c Character to search for.
 * @param len Number of bytes to search.
 * 
 * @return void* Pointer to the matching byte or NULL if the character does not
 *  occur in the block of memory.
 * 
 * @details The `ft_memchr()` function locates the first occurrence of `c` 
 *  (converted to an unsigned char) in the initial `len` bytes of the memory
 *  area pointed to by `ptr`.
 * 
 * @example 
 * ft_memchr(ptr, 'a', 10); // Search for the first occurrence of 'a' in the
 *  first 10 bytes of `ptr`.
 */
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

#endif	// __GNUC__ || __clang__