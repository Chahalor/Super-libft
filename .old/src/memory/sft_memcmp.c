/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sft_memcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:16:26 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/29 12:23:01 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

#if defined(__GNUC__) || defined(__clang__)

/** */
void	ft_memcmp(const void *ptr1, const void *ptr2, size_t len)
{
	return (__builtin_memcmp(ptr1, ptr2, len));
}

#else

/**
 * @brief Compare two blocks of memory.
 * 
 * @param ptr1 Pointer to the first block of memory.
 * @param ptr2 Pointer to the second block of memory.
 * @param len Number of bytes to compare.
 * 
 * @return int An integer less than, equal to, or greater than zero
 *  if the first `len` bytes of `ptr1` are found, respectively, to
 *  be less than, to match, or be greater than the first `len` bytes
 * of `ptr2`.
 * 
 * @details
 * 	"xor %%rax, %%rax\n"        // rax = 0 (compteur d'index)
 * 	"test %[len], %[len]\n"     // Vérifier si len == 0
 * 	"je .done\n"                // Si len == 0, sauter à la fin
 * 	".loop:\n"
 * 	"movzbl (%[ptr1], %%rax, 1), %%r8d\n"  // Charger octet de ptr1 dans r8d
 * 	"movzbl (%[ptr2], %%rax, 1), %%r9d\n"  // Charger octet de ptr2 dans r9d
 * 	"cmp %%r8d, %%r9d\n"        // Comparer les octets
 * 	"jne .diff\n"               // Si différent, on sort
 * 	"inc %%rax\n"               // Incrémenter index
 * 	"cmp %%rax, %[len]\n"       // Vérifier si on atteint len
 * 	"jne .loop\n"               // Continuer la boucle si non terminé
 * 	"xor %[result], %[result]\n" // result = 0 (égaux)
 * 	"jmp .done\n"
 * 	".diff:\n"
 * 	"mov %%r8d, %[result]\n"    // result = *ptr1
 * 	"sub %%r9d, %[result]\n"    // result -= *ptr2
 * 	".done:\n"
 * 	: [result] "=r" (result)    // Sortie
 * 	: [ptr1] "r" (ptr1), [ptr2] "r" (ptr2), [len] "r" (len) // Entrées
 * 	: "rax", "r8", "r9", "memory"
*/
int	ft_memcmp(const void *ptr1, const void *ptr2, size_t len)
{
	int result;

	__asm__(
		"xor %%rax, %%rax\n"
		"test %[len], %[len]\n"
		"je .done\n"
		".loop:\n"
		"movzbl (%[ptr1], %%rax, 1), %%r8d\n"
		"movzbl (%[ptr2], %%rax, 1), %%r9d\n"
		"cmp %%r8d, %%r9d\n"
		"jne .diff\n"
		"inc %%rax\n"
		"cmp %%rax, %[len]\n"
		"jne .loop\n"
		"xor %[result], %[result]\n"
		"jmp .done\n"
		".diff:\n"
		"mov %%r8d, %[result]\n"
		"sub %%r9d, %[result]\n"
		".done:\n"
		: [result] "=r" (result)
		: [ptr1] "r" (ptr1), [ptr2] "r" (ptr2), [len] "r" (len)
		: "rax", "r8", "r9", "memory"
	);
	return (result);
}

#endif	// __GNUC__ || __clang__