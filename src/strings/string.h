/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:11:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/16 13:53:23 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H
# define SFT_STRING_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <stddef.h>

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
# include "_internal/_string.h"
# include "_internal/append/_append.h"
# include "_internal/check/_check.h"
# include "_internal/memory/_memory.h"
# include "_internal/change/_change.h"

/* -----| Modules   |----- */
	//...

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_string_append	t_string_append;
typedef struct s_string_check	t_string_check;
typedef struct s_string_memory	t_string_memory;
typedef struct s_string_change	t_string_change;

typedef struct s_string	t_string;	/* String structure type definition */

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_string
{
	char			*str;
	size_t			len;
	t_string_append	append;
	t_string_check	check;
	t_string_memory	memory;
	t_string_change	change;
	void			(*destroy)(t_string *self);
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

t_string	*new_t_string(
				const char *const str
				);


#endif /* !STRING_H */