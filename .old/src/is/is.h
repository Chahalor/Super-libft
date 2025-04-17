/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:05:51 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/29 13:06:47 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_H
# define IS_H

# include "super_libft.h"

/**
 * @brief Check if a character is a space.
 * 
 * @param c Character to check.
 * 
 * @return int 1 if the character is a space, 0 otherwise.
 */
__attribute__((always_inline)) static inline int	ft_isspace(int c)
{
	return (c == ' ' || (unsigned char)c - 9 < 5);
}

/**
 * @brief Check if a character is a lowercase letter.
 * 
 * @param c Character to check.
 * 
 * @return int 1 if the character is a lowercase letter, 0 otherwise.
 */
__attribute__((always_inline)) static inline int	ft_islower(int c)
{
	return ((unsigned char)(c | 32) - 97 < 26);
}

/**
 * @brief Check if a character is an uppercase letter.
 * 
 * @param c Character to check.
 * 
 * @return int 1 if the character is an uppercase letter, 0 otherwise.
 */
__attribute__((always_inline)) static inline int	ft_isupper(int c)
{
	return ((unsigned char)(c & 95) - 65 < 26);
}

/**
 * @brief Check if a character is a letter.
 * 
 * @param c Character to check.
 * 
 * @return int 1 if the character is a letter, 0 otherwise.
 */
__attribute__((always_inline)) static inline int	ft_isalpha(int c)
{
	return ((unsigned char)(c | 32) - 97 < 26);
}

/**
 * @brief Check if a character is a digit.
 * 
 * @param c Character to check.
 * 
 * @return int 1 if the character is a digit, 0 otherwise.
 */
__attribute__((always_inline)) static inline int	ft_isdigit(int c)
{
	return ((unsigned char)c - 48 < 10);
}

#endif	// IS_H