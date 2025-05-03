/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:20:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/03 16:14:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#pragma region Headers

/* -----| Interface |----- */
#include "mm.h"

/* -----| Internal  |----- */
#include "_mm.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((always_inline)) static inline void	_add_to_bucket(
	t_mm_node *bucket,
	const int index,
	void *ptr
)
{
	t_mm_node		*node;

	node = &bucket[index].next;
	while (node)
		node = node->next;
	node->ptr = ptr;
	node->next = NULL;
}

/** */
__attribute__((always_inline)) static inline void	_free_one(
	t_mm_node *bucket,
	void *ptr
)
{
	const int	index = (size_t)ptr % MM_BUCKET_SIZE;
	t_mm_node	*node;

	node = &bucket[index];
	while (node)
	{
		if (node->ptr == ptr)
		{
			free(node->ptr);
			node->ptr = NULL;
			break ;
		}
		node = node->next;
	}
}

/** */
__attribute__((always_inline)) static inline void	_free_all_bucket(
	t_mm_node *bucket
)
{
	register int	i;
	t_mm_node		*node;

	i = -1;
	while (++i < MM_BUCKET_SIZE)
	{
		node = &bucket[i];
		while (node)
		{
			if (node->ptr)
			{
				free(node->ptr);
				node->ptr = NULL;
			}
			node = node->next;
		}
	}
}

/** */
__attribute__((visibility("hidden"))) void	*_mm_store(
	void *ptr,
	const int access
)
{
	static t_mm_node	bucket[MM_BUCKET_SIZE] = {0};
	const int			index = (size_t)ptr % MM_BUCKET_SIZE;

	if (access == mm_add)
		_add_to_bucket(bucket, index, ptr);
	else if (access == mm_free)
		_free_one(bucket, ptr);
	else if (access == mm_free_all)
		_free_all_bucket(bucket);
}

#pragma endregion Functions