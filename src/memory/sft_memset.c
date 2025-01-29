/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sft_memset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:16:04 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/29 12:10:08 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

#if defined(__GNUC__) || defined(__clang__)

/**
 * @brief Set a block of memory with a specific val.
 * 
 * @param ptr Pointer to the block of memory to fill.
 * @param val val to set.
 * @param len Number of bytes to set.
 * 
 * @return void* Pointer to the memory block.
 * 
 * @details Use the built-in function `__builtin_memset()` to fill the first `len`
 * 
 * @example 
 * 	ft_memset(ptr, 0, 10); // Fill the first 10 bytes of `ptr` with 0.
 */
void	*ft_memset(void *ptr, int val, size_t len)
{
	return (__builtin_memset(ptr, val, len));
}

#else

/**
 * @brief Set a block of memory with a specific val.
 * 
 * @param ptr Pointer to the block of memory to fill.
 * @param val val to set.
 * @param len Number of bytes to set.
 * 
 * @return void* Pointer to the memory block.
 * 
 * @details The `ft_memset()` function fills the first `len` bytes of the
 * memory area pointed to by `ptr` with the constant byte `(t_uchar)val`.
		"movb %b0, %%al;"        // Mettre la valeur dans le registre al
		"1:"
		"movb %%al, (%%rdi);"    // Mettre le byte pointé par rdi à la valeur
		"inc %%rdi;"             // Incrémenter le pointeur rdi
		"dec %%rcx;"             // Décrémenter le compteur rcx
		"jnz 1b;"                // Si rcx n'est pas zéro, sauter à l'étiquette 1
		:
		: "r" (val), "D" (ptr), "c" (len)  // Entrées : val dans un registre
											général, ptr dans rdi size dans rcx
		: "eax", "memory"        // Registres modifiés : eax, mémoire
 * 
 * @example 
 * 	ft_memset(ptr, 0, 10); // Fill the first 10 bytes of `ptr` with 0.
 */
void	*ft_memset(void *ptr, int val, size_t len)
{
	__asm__ (
		"movb %b0, %%al;"
		"1:"
		"movb %%al, (%%rdi);"
		"inc %%rdi;"
		"dec %%rcx;"
		"jnz 1b;"
		:
		: "r" (val), "D" (ptr), "c" (len)
		: "eax", "memory"
		);
	return (ptr);
}

#endif	// __GCC__ || __clang__