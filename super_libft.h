/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_libft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:27:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/23 15:28:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_LIBFT_H
# define SUPER_LIBFT_H

/* -----| Header |----- */
// Global
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

// Local
# include "src/is/is.h"
# include "src/is/is2.h"

/* -----| Define |----- */

# ifndef ALLOW_ASM
#  define ALLOW_ASM 1
# endif

/* -----| Typedef |----- */

typedef unsigned char		t_uchar;
typedef unsigned short		t_ushort;
typedef unsigned int		t_uint;
typedef unsigned long		t_ulong;
typedef unsigned long long	t_ullong;

/* -----| Enums |----- */
//...

/* -----| Struct |----- */
//...

/* -----| Prototypes |----- */

// Memory
void	*ft_memset(void *ptr, int value, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_bzero(void *ptr, size_t len);
void	*ft_memchr(const void *ptr, int c, size_t len);

#endif	// SUPER_LIBFT_H