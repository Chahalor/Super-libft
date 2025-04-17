/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to-func.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:11:42 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/29 13:13:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TO_FUNC_H
# define TO_FUNC_H

/**
 * @brief Convert a character to lowercase.
 * 
 * @param c Character to convert.
 * 
 * @return int The lowercase character.
 */
__attribute__((always_inline, const, pure)) static inline int	tolower(int c)
{
	return (c | 32);
}

/**
 * @brief Convert a character to uppercase.
 * 
 * @param c Character to convert.
 * 
 * @return int The uppercase character.
 */
__attribute__((always_inline, const, pure)) static inline int	toupper(int c)
{
	return (c & 95);
}

#endif	// TO_FUNC_H