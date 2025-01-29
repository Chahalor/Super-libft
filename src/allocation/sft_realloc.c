/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:25:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/29 13:28:50 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

#if defined(__GNUC__) || defined(__clang__)

/**
 * @brief Reallocate memory to an size bytes area.
 * 
 * @param ptr Pointer to the memory area to reallocate.
 * @param size New size of the memory area.
 * 
 * @return void* A pointer to the reallocated memory area.
 * 
 * @note
 * 
 * - The function is marked as malloc.
 * 
 * - The function uses the builtin memcpy function.
 */
__attribute__((malloc)) void	*ft_realloc(void *ptr, const size_t size)
{
	void	*new_ptr;

	new_ptr = (void *)malloc(size);
	if (new_ptr)
	{
		__builtin_memcpy(new_ptr, ptr, size);
		free(ptr);
		ptr = new_ptr;
	}
	return (new_ptr);
}

#else

/**
 * @brief Reallocate memory to an size bytes area.
 * 
 * @param ptr Pointer to the memory area to reallocate.
 * @param size New size of the memory area.
 * 
 * @return void* A pointer to the reallocated memory area.
 */
void	*ft_realloc(void *ptr, const size_t size)
{
	void	*new_ptr;

	new_ptr = (void *)malloc(size);
	if (new_ptr)
	{
		ft_memcpy(new_ptr, ptr, size);
		free(ptr);
		ptr = new_ptr;
	}
	return (new_ptr);
}

#endif	// __GNUC__ || __clang__