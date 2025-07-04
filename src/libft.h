/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:40:03 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/04 08:11:46 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# pragma once

# include <stddef.h>

# include "strings/string.h"

typedef struct s_libft
{
	struct s_sft_memory
	{
		void		*(*alloc)(size_t size);
		void		*(*realloc)(void *ptr, size_t osize, size_t nsize);
		void		(*free)(void *ptr);
		void		*(*duplicate)(const void *ptr, size_t size);
		t_string	*(*new_string)(const char *str);
	}	memory;	// Memory management functions
	
}	t_libft;

#endif