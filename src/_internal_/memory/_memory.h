/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _memory.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:30:15 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/05 10:37:13 by nduvoid          ###   ########.fr       */
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


#endif /* !_MEMORY_H */