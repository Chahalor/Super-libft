/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/21 10:45:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----|  System  |-----*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* -----| Internal |-----*/
#include "_internal/_args-parser.h"
#include "args-parser.h"

/* -----|   Core   |-----*/
#include "_core_/config.h"
#include "_core_/memory/_memory.h"
#include "_core_/error/_error.h"
#include "_core_/shortcut/_shortcut.h"

/* -----|  Module  |-----*/
	//...

#pragma endregion Header
#pragma region    Functions

inline int	_isspace(
	const char c
)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

/** */
__attribute__((always_inline, used, const, pure))
inline int	_word_size(
	const char *str
)
{
	int	size;

	if (unlikely(!str))
		return (0);
	while (*str && _isspace(*str))
		++str;
	size = 0;
	while (str[size] && !_isspace(str[size]))
		++size;
	return (size);
}

/** */
__attribute__((always_inline, used, const, pure))
inline int	_count_digits(
	char *n
)
{
	int	count;

	if (unlikely(!n))
		return (0);
	count = 0;
	while (*n)
	{
		if (*n >= '0' && *n <= '9')
			++count;
		++n;
	}
	return (count);
}

/** */
__attribute__((always_inline, used, malloc))
inline char	*_worddup(
	const char *s
)
{
	register size_t	i;
	char			*dup;
	size_t			len;

	if (unlikely(!s))
		return (NULL);
	while (*s && _isspace(*s))
		++s;
	len = _word_size(s);
	dup = (char *)_mem_alloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < len)
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}

__attribute__((always_inline, malloc, used))
inline char	*cat_options(
	const int argc,
	const char **argv
)
{
	char	*result;
	int		i;
	int		total_length;

	total_length = 0;
	i = 0;
	while (++i < argc)
		total_length += _strlen(argv[i]) + 1;
	result = (char *)_mem_alloc((total_length + 1) * sizeof(char));
	if (unlikely(!result))
		return (NULL);
	i = 0;
	while (++i < argc - 1)
	{
		strcat(result, argv[i]);
		strcat(result, " ");
	}
	strcat(result, argv[argc - 1]);
	return (result);
}

#pragma endregion Functions