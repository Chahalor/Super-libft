/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:23:15 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/24 14:37:12 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Configs  |----- */
#include "config.h"

/* -----| Systemes |----- */
//...

/* -----| Libft    |----- */
#ifdef DEFAULT
# include "libft.h"
#else
# include "check.h"
#endif // defined (DEFAULT)

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((always_inline, used)) extern inline int	ft_isalpha(
	const int c
)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/** */
__attribute__((always_inline, used)) extern inline int	ft_isdigit(
	const int c
)
{
	return (c >= '0' && c <= '9');
}

/** */
__attribute__((always_inline, used)) extern inline int	ft_isalnum(
	const int c
)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/** */
__attribute__((always_inline, used)) extern inline int	ft_isprint(
	const int c
)
{
	return (c >= 32 && c <= 126);
}

/** */
__attribute__((always_inline, used)) extern inline int	ft_isascii(
	const int c
)
{
	return (c >= 0 && c <= 127);
}

#pragma endregion Functions