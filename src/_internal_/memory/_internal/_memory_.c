/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _memory_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/15 09:41:01 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region    Header

/* -----| System   |-----*/
#include <stdlib.h>
#include <stdio.h> //rm

/* -----| Internal |-----*/
#include "_memory_.h"
#include "_memory.h"

/* -----| _Internal_   |-----*/
#include "error/_error.h"

#pragma endregion Header
#pragma region    Debug

/*
static inline void	_show_(
	t_sft_mm_node *bucket[]
)
{
	t_sft_mm_node	*current;
	int				i;
	int				depth;

	for (i = 0; i < _SFT_MM_BUCKET_SIZE; ++i)
	{
		if (!bucket[i])
			continue;
		printf("Bucket[%-4d]:", i);
		current = bucket[i];
		depth = 0;
		while (current)
		{
			printf(" -> [depth %-3d] data: %p, size: %-4zu", depth, current->data, current->size);
			current = current->next;
			depth++;
		}
		printf("\n");
	}
}

*/
#pragma endregion Debug
#pragma region    Functions

/**
 * @todo: find a better hasing
 */
static inline int	_hash_(
	const void *ptr
)
{
	return ((unsigned long)ptr % _SFT_MM_BUCKET_SIZE);
}

static inline void	*_register_(
	void *ptr,
	t_sft_mm_node *bucket[]
)
{
	const int		hash = _hash_(ptr);
	t_sft_mm_node	*current = bucket[hash];

	if (!current)
	{
		bucket[hash] = (t_sft_mm_node *)ptr;
		((t_sft_mm_node *)ptr)->next = NULL;
	}
	else
	{
		while (current->next)
			current = current->next;
		current->next = (t_sft_mm_node *)ptr;
		((t_sft_mm_node *)ptr)->next = NULL;
	}
	return (((t_sft_mm_node *)ptr)->data);
}

static inline void	_frpushee_(
	void *ptr,
	t_sft_mm_node *bucket[]
)
{
	const int		hash = _hash_(ptr);
	t_sft_mm_node	*current;
	t_sft_mm_node	*prev;

	if (!bucket[hash])
		return ;
	current = bucket[hash];
	prev = NULL;
	while (current && current->data != ptr)
	{
		prev = current;
		current = current->next;
	}
	if (!current)
		return ;
	if (prev)
		prev->next = current->next;
	else
		bucket[hash] = current->next;
	free(current);
}

static inline void	_destroy_(
	t_sft_mm_node *bucket[]
)
{
	t_sft_mm_node	*current;
	t_sft_mm_node	*next;
	register int	i;

	i = -1;
	while (++i < _SFT_MM_BUCKET_SIZE)
	{
		current = bucket[i];
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		bucket[i] = NULL;
	}
}

__attribute__((visibility("hidden"), used)) void	*_sft_memory_manager(
	void *ptr,
	const int access
)
{
	static t_sft_mm_node	*bucket[_SFT_MM_BUCKET_SIZE] = {0};

	if (access == sft_mm_register)
		return (_register_(ptr, bucket));
	else if (access == sft_mm_free)
		_free_(ptr, bucket);
	else if (access == sft_mm_destroy)
		_destroy_(bucket);
	return (NULL);
}

#pragma endregion Functions