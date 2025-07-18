/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _change.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 08:23:37 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/16 13:54:11 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHANGE_H
# define _CHANGE_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

# include "../_string.h"
# include "../../string.h"

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_string_change	t_string_change;

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_string_change
{
	int			(*atoi)(const t_string *const);
	long		(*atol)(const t_string *const);
	float		(*atolf)(const t_string *const);
	t_string	*(*itos)(size_t value);
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

int			_sft_string_atoi(
				const t_string *const self
				);

long		_sft_string_atol(
				const t_string *const self
				);

float		_sft_string_atolf(
				const t_string *const self
				);

t_string	*_sft_string_itos(
				size_t value
				);

#endif /* !_CHANGE_H */