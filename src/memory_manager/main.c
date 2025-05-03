/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:15:41 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/03 17:15:53 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>

#include "mm.h"

int main(void)
{
	void	*ptr;

	ptr = mm_alloc(42);
	if (ptr == NULL)
	{
		perror("mm_alloc: malloc failed");
		return (EXIT_FAILURE);
	}
	printf("Allocated memory at %p\n", ptr);

	mm_free(ptr);
	printf("Freed memory at %p\n", ptr);

	mm_destroy();
	printf("Destroyed memory manager\n");

	return (EXIT_SUCCESS);
}