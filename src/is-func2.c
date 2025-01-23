/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is-func2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:35:01 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/23 08:35:36 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super-libft.h"

int	isspace(int c)
{
	return (c == ' ' || (unsigned char)c - 9 < 5);
}

int	islower(int c)
{
	return ((unsigned char)(c | 32) - 97 < 26);
}

int	isupper(int c)
{
	return ((unsigned char)(c & 95) - 65 < 26);
}
