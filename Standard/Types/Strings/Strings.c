/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:08:10 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/26 20:30:02 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| Internals |----- */
#include "_internal/_string.h"

/* -----| Modules   |----- */
#include "Strings.h"

#pragma endregion Header
#pragma region Fonctions

t_string *_append(
	t_string *const restrict str1,
	t_string *const restrict str2
)
{
	// @todo
	return (NULL);
}

size_t _find(
	const t_string *const restrict str,
	const char *const restrict substr
)
{
	// @todo
	return (0);
}

void	_clear(
	t_string *const restrict str
)
{
	t_string_	*_string;

	if (!str)
		return;
	_string = (t_string_ *)(str - offsetof(t_string_, strings));
	if (_string->strings)
	{
		if (_string->strings->str)
			free(_string->strings->str);
		free(_string->strings);
	}
	free(_string);
}

/**
 * @brief	Create a new string with the given char * as content.
 * 
 * @param	str		The char * to use as content.
 * 
 * @return	t_string A new string
 * @retval		NULL If the allocation fails.
 * @retval		An empty string if str is NULL.
 * 
 * @version 1.0
 */
t_string	*new_string(
	const char *const restrict str
)
{
	const size_t	len = ft_strlen(str);
	const size_t	total_size = sizeof(t_string_) + sizeof(t_string)
		+ ((len / STRING_ALLOC_SIZE + 1) * STRING_ALLOC_SIZE) * sizeof(char);
	t_string_		*_string;
	char			*_str;
	char			*base;

	base = (char *)malloc(total_size);
	if (!base)
		return (NULL);
	_string = (t_string_ *)base;
	_string->strings = (t_string *)(base + sizeof(t_string_));
	_string->alloc_size = (len / STRING_ALLOC_SIZE + 1) * STRING_ALLOC_SIZE;
	_str = (char *)(base + sizeof(t_string_) + sizeof(t_string));
	_memcpy(_str, str, len);
	_str[len] = '\0';
	*_string->strings = (t_string){
		.str = _str,
		.len = len,
		.append = _append,
		.find = _find,
		.clear = _clear
	};
	return (_string->strings);
}

#pragma endregion Fonctions