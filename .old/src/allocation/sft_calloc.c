/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:15:31 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/29 13:24:58 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

#if defined(__GNUC__) || defined(__clang__)

/**
 * @brief Allocate and zero-initialize memory.
 * 
 * @param count Number of elements.
 * @param size Size of each element.
 * 
 * @return void* A pointer to the allocated memory.
*/
__attribute__((malloc)) void	*ft_calloc(const size_t count,
	const size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr)
		__builtin_memset(ptr, 0, count * size);
	return (ptr);
}

#else

/**
 * @brief Allocate and zero-initialize memory.
 * 
 * @param count Number of elements.
 * @param size Size of each element.
 * 
 * @return void* A pointer to the allocated memory.
 */
void	*ft_calloc(const size_t count, const size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}

#endif	// __GNUC__ || __clang__