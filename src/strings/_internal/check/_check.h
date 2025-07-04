/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 08:23:37 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/02 09:01:37 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHECK_H
# define _CHECK_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

# include "_string.h"
# include "../../string.h"

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_string_check	t_string_check;

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_string_check
{
	int		(*cmp)(const t_string *const, const t_string *const);
	int		(*ncomp)(const t_string *const, const t_string *const, const size_t);
	size_t	(*find)(const t_string *const, const char *const);
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

size_t	_sft_string_char_find(
				const t_string *const self,
				const char *const target
				);

int	_sft_string_cmp(
				const t_string *const self,
				const t_string *const other
				);

int	_sft_string_ncmp(
				const t_string *const self,
				const t_string *const other,
				const size_t n
				);

#endif /* !_CHECK_H */