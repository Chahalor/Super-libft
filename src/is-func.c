/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is-func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:27:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/23 08:34:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super-libft.h"

int	isalpha(int c)
{
	return ((unsigned char)(c | 32) - 97 < 26);
}

int	isdigit(int c)
{
	return ((unsigned char)c - 48 < 10);
}

int	isalnum(int c)
{
	return (isalpha(c) || isdigit(c));
}

int	isascii(int c)
{
	return ((unsigned char)c < 128);
}

int	isprint(int c)
{
	return ((unsigned char)c - 32 < 95);
}
