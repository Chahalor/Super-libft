/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _memory_.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:25:23 by nduvoid           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/05 10:31:54 by nduvoid          ###   ########.fr       */
=======
/*   Updated: 2025/07/15 08:53:53 by nduvoid          ###   ########.fr       */
>>>>>>> bb852bf (add: internal memory manager && error manager)
/*                                                                            */
/* ************************************************************************** */

#ifndef _MEMORY__H
# define _MEMORY__H

# pragma once

#define	_SFT_MM_BUCKET_SIZE	1021	// A prime number to reduce collisions @todo: find a better size

enum e_sft_mm_access
{
	sft_mm_register,
	sft_mm_realloc,
	sft_mm_free,
	sft_mm_destroy,
};

typedef struct s_sft_mm_node
{
	size_t					size;
	struct s_sft_mm_node	*next;
	void					*data;
}	t_sft_mm_node;

<<<<<<< HEAD
=======
void	*_sft_memory_manager(
	void *ptr,
	const int access
);

>>>>>>> bb852bf (add: internal memory manager && error manager)
#endif /* !_MEMORY__H */