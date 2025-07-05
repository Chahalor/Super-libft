/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _memory_.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:25:23 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/05 10:31:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MEMORY__H
# define _MEMORY__H

# pragma once

#define	_SFT_MM_BUCKET_SIZE	1021	// A prime number to reduce collisions

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

#endif /* !_MEMORY__H */