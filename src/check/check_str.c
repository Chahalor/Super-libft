/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:27:26 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/24 14:41:24 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Configs  |----- */
#include "config.h"

/* -----| Systemes |----- */
#include <stddef.h>	// size_t

/* -----| Libft    |----- */
#ifdef DEFAULT
# include "libft.h"
#else
# include "check.h"
#endif // defined (DEFAULT)

#pragma endregion Headers
#pragma region Functions

/** */
#ifdef DEFAULT

__attribute__((always_inline, used)) extern inline int	ft_isnumber(
	const char *const str
)
#else

__attribute__((always_inline, used)) extern inline int	ft_isnumber(
	const char *const restrict str
)
#endif // defined (DEFAULT)

{
	size_t i;

	i = -1;
	while (str[++i])
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
	return (1);
}

#pragma endregion Functions