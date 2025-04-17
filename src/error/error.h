/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:59:48 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/07 08:14:43 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define MAX_ERROR_LEVEL	5

typedef struct s_error_level	t_error_level;

struct s_error_level
{
	char			*message;	/* The error message */
	t_error_level	*next;		/* Pointer to the next error of the level */
	int				level;		/* The error level */
	int				code;		/* The error code */
};

void ft_exit(const int code, const char *msg);
void exiting(const int errno, const char *msg);

#endif