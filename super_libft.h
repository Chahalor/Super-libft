/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_libft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:27:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/29 13:45:26 by nduvoid          ###   ########.fr       */
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
# include "src/modification/to-func.h"

/* -----| Define |----- */

# define TRUE	1
# define FALSE	0

/* -----| Typedef |----- */

typedef unsigned char		t_uchar;
typedef unsigned short		t_ushort;
typedef unsigned int		t_uint;
typedef unsigned long		t_ulong;
typedef unsigned long long	t_ullong;

/* -----| Enums |----- */
//...

/* -----| Struct |----- */

# pragma pack(push, 1)

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
# pragma pack(pop)

/* -----| Prototypes |----- */

// Allocation

void	*ft_calloc(const size_t count, const size_t size);
void	*ft_realloc(void *ptr, const size_t size);

// Memory

void	ft_bzero(void *ptr, size_t len);
void	*ft_memchr(const void *ptr, int c, size_t len);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *ptr, int value, size_t len);

// Modification

int		ft_atoi(const char *str);
long	ft_atol(const char *str);

#endif	// SUPER_LIBFT_H