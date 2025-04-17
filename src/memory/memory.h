/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:53:50 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/04 09:53:40 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# pragma once

# pragma region "Includes"
/* Systeme */
# include <stdlib.h>
# include <errno.h>

/* Global */
	//...

/* Modules */
	//...

# pragma endregion	/* Includes */
# pragma region "Macros"
//...

# pragma endregion	/* Macros */
# pragma region "Typedefs"
//...

# pragma endregion	/* Typedefs */
# pragma region "Enums"
//...

# pragma endregion	/* Enums */
# pragma region "Structs"
//...

# pragma endregion	/* Structs */
# pragma region "Prototypes"
/* Extern */
	//...

/* Global */
	// allocing.c

void	*ft_calloc(const size_t nmemb, const size_t size);
void	*safe_alloc(const size_t size);
void	*ft_realloc(const size_t old, const size_t new, void *ptr);
void	ft_free(void **ptr);

	// compare.c
void	*ft_memchr(const void *s, int c, unsigned long int n);
int		ft_memcmp(const void *s1, const void *s2, unsigned long int n);

	// managing.c
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memdup(const void *src, const size_t n);
void	ft_bzero(void *s, unsigned long int n);

/* Static */
	//...

# pragma endregion	/* Prototypes */

#endif	/* MEMORY_H */
