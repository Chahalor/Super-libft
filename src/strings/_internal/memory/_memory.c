/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _memory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/27 16:29:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| System   |-----*/
#include <stdint.h>

/* -----| Internal |-----*/
#include "/home/nduvoid/Desktop/Super-libft/src/strings/string.h"
#include "_memory.h"
#include "_string.h"

/* -----| Module   |-----*/
	//...

#pragma endregion Header
#pragma region Functions

__attribute__((visibility("hidden"), used)) t_string	*_sft_string_dup(
	const t_string *const self
)
{
	t_string	*new_string;

	if (!self)
		return (NULL);
	new_string = memdup(self, sizeof(t_string));
	if (!new_string)
		return (NULL);
	new_string->str = memdup(self->str, self->len + 1);
	return (new_string);
}

#pragma endregion Functions