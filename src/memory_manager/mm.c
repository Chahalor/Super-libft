/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:11:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/03 16:18:27 by nduvoid          ###   ########.fr       */
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
__attribute__((malloc)) void	*mm_alloc(
	const size_t size
)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		perror("mm_alloc: malloc failed");
	_mm_store(ptr, mm_add);
	return (ptr);
}

/** */
__attribute__(()) void	mm_free(
	void *restrict ptr
)
{
	if (ptr == NULL)
		return ;
	_mm_store(ptr, mm_free);
}

/** */
__attribute__(()) void	mm_destroy(void)
{
	_mm_store(NULL, mm_free_all);
}

#pragma endregion Functions