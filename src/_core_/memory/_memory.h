/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _memory.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:30:15 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/15 13:06:28 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MEMORY_H
# define _MEMORY_H

# undef _MEMORY_H
# pragma once

# include <stddef.h>

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

void	*_mem_alloc(
			const size_t size
			);

void	*_mem_realloc(
			void **ptr,
			const size_t new_size
			);

void	_mem_free(
			void *const ptr
			);

void	_mem_destroy(void);

#endif /* !_MEMORY_H */