/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:25:36 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/24 14:27:08 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# undef CHECK_H

# ifndef LIBFT_CHECK_H
#  define LIBFT_CHECK_H

#  pragma once

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

extern inline int	ft_isalpha(const int c);
extern inline int	ft_isdigit(const int c);
extern inline int	ft_isalnum(const int c);
extern inline int	ft_isprint(const int c);
extern inline int	ft_isascii(const int c);

# endif // LIBFT_CHECK_H
#endif // CHECK_H