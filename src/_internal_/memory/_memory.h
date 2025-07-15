/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _memory.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/07/05 10:30:15 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/05 10:37:13 by nduvoid          ###   ########.fr       */
=======
/*   Created: 2025/07/15 08:45:54 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/15 09:03:37 by nduvoid          ###   ########.fr       */
>>>>>>> bb852bf (add: internal memory manager && error manager)
/*                                                                            */
/* ************************************************************************** */

#ifndef _MEMORY_H
# define _MEMORY_H

<<<<<<< HEAD
# undef _MEMORY_H
# pragma once

# include <stddef.h>


/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

void	_free(
			void *const ptr
			);

void	*_alloc(
			const size_t size
			);

void	*_realloc(
			void **ptr,
			const size_t new_size
			);

=======
# pragma once

# undef _MEMORY_H

#include <stddef.h>

void	*_mem_alloc(const size_t size);
void	*_mem_realloc(void **ptr, const size_t new_size);
void	_mem_free(void *const ptr);
void	_mem_destroy(void);
>>>>>>> bb852bf (add: internal memory manager && error manager)

#endif /* !_MEMORY_H */