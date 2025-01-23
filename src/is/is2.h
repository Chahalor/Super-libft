/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is2.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:08:59 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/23 15:41:30 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS2_H
# define IS2_H

# include "super_libft.h"

/**
 * @brief Check if a character is a digit.
 * 
 * @param c Character to check.
 * 
 * @return int 1 if the character is a digit, 0 otherwise.
 */
static inline int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/**
 * @brief Check if a character is a digit.
 * 
 * @param c Character to check.
 * 
 * @return int 1 if the character is a digit, 0 otherwise.
 */
static inline int	ft_isascii(int c)
{
	return ((unsigned char)c < 128);
}

/**
 * @brief Check if a character is a digit.
 * 
 * @param c Character to check.
 * 
 * @return int 1 if the character is a digit, 0 otherwise.
 */
static inline int	ft_isprint(int c)
{
	return ((unsigned char)c - 32 < 95);
}

#endif	// IS2_H