/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sft_ato.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:31:47 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/29 13:42:15 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

#if defined(__GNUC__) || defined(__clang__)

/** */
int	ft_atoi(const char *str)
{
	t_uint	nb;
	int		sign;

	nb = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (__builtin_expect(ft_isdigit(*str), 1)
		&& __builtin_popcount(nb) < 32)
	{
		nb = (nb << 3) + (nb << 1) + (*str - '0');
		++str;
	}
	return (nb * sign);
}

/**
 * @brief Convert a string to a long integer.
 * 
 * @param str The string to convert.
 * 
 * @return The long integer value.
 * 
 * @note
 * 
 * - The function handles leading whitespaces and signs.
 * 
 * - The function does not handle overflow.
 */
long	ft_atol(const char *str)
{
	long	nb;
	int		sign;

	nb = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (__builtin_expect(ft_isdigit(*str), 1)
		&& __builtin_popcountl(nb) < 64)
	{
		nb = (nb << 3) + (nb << 1) + (*str - '0');
		++str;
	}
	return (nb * sign);
}

#else

/**
 * @brief Convert a string to an integer.
 * 
 * @param str The string to convert.
 * 
 * @return The integer value.
 * 
 * @note
 * 
 * - The function handles leading whitespaces and signs.
 * 
 * - The function does not handle overflow.
 */
int	ft_atoi(const char *str)
{
	int		nb;
	int		sign;

	nb = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (__builtin_expect(ft_isdigit(*str), 1))
	{
		nb = (nb << 3) + (nb << 1) + (*str - '0');
		++str;
	}
	return (nb * sign);
}

/**
 * @brief Convert a string to a long integer.
 * 
 * @param str The string to convert.
 * 
 * @return The long integer value.
 * 
 * @note
 * 
 * - The function handles leading whitespaces and signs.
 * 
 * - The function does not handle overflow.
 */
long	ft_atol(const char *str)
{
	long	nb;
	int		sign;

	nb = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (__builtin_expect(ft_isdigit(*str), 1))
	{
		nb = (nb << 3) + (nb << 1) + (*str - '0');
		++str;
	}
	return (nb * sign);
}

#endif	// __GNUC__ || __clang__