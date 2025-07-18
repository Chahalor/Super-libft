/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _memory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/16 09:43:48 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region    Header

/* -----| System   |-----*/
#include <stdlib.h>

/* -----| Internal |-----*/
#include "_internal/_memory_.h"
#include "_memory.h"

/* -----| _Internal_   |-----*/
#include "error/_error.h"

#pragma endregion Header
#pragma region    Functions

__attribute__((visibility("hidden"), used)) void	_mem_free(
	void *const ptr
)
{
	t_sft_mm_node	*node;

	if (!ptr)
		return ;
	node = (t_sft_mm_node *)((char *)ptr - sizeof(t_sft_mm_node));
	_sft_memory_manager(node, sft_mm_free);
}

__attribute__((visibility("hidden"), used)) void	*_mem_alloc(
	const size_t size
)
{
	t_sft_mm_node	*new_node;

	if (size == 0)
		return (NULL);
	new_node = (t_sft_mm_node *)malloc(sizeof(t_sft_mm_node) + size);
	if (!new_node)
		return (_register_error(SFT_ERR_NOMEM), NULL);
	new_node->size = size;
	new_node->next = NULL;
	new_node->data = (void *)(new_node + 1);
	_sft_memory_manager(new_node, sft_mm_register);
	return (new_node->data);
}

__attribute__((visibility("hidden"), used)) void	*_mem_realloc(
	void **ptr,
	const size_t new_size
)
{
	t_sft_mm_node	*node;
	void			*new_data;
	register size_t	i;
	
	if (!ptr || !*ptr)
		return (_mem_alloc(new_size));
	else if (new_size == 0)
		return (_mem_free(ptr), NULL);
	node = (t_sft_mm_node *)((char *)*ptr - sizeof(t_sft_mm_node));
	new_data = _mem_alloc(new_size);
	if (!new_data)
		return (NULL);
	i = -1;
	while (++i < node->size && i < new_size)
		((char *)new_data)[i] = ((char *)node->data)[i];
	_mem_free(*ptr);
	*ptr = new_data;
	return (new_data);
}

__attribute__((visibility("hidden"), used))	void	_mem_destroy(void)
{
	_sft_memory_manager(NULL, sft_mm_destroy);
}

#pragma endregion Functions