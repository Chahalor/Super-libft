/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:11:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/27 16:43:54 by nduvoid          ###   ########.fr       */
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
	//...

/* -----| Modules   |----- */
	//...

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_string_internal	t_string_internal;	/* String internal structure type definition */

typedef struct s_string_append	t_string_append;	/* String append structure type definition */
typedef t_string_append			t_append;

typedef struct s_string_check	t_string_check;		/* String check structure type definition */
typedef t_string_check			t_check;

typedef struct s_string			t_string;			/* String structure type definition */

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_string_internal
{
	size_t		alloc_size;
	t_string	*data;
}

struct s_string_append
{
	t_string	*(*t_string)(const t_string *const self, const t_string *const other);
	t_string	*(*str)(const t_string *const self, const char *const other);
};

struct s_string_check
{
	int		(*cmp)(const t_string *const self, const t_string *const other);	/* Function to compare two strings */
	int		(*ncomp)(const t_string *const self, const char *const other, const size_t n); /* Function to compare a string with a C string up to n characters */
	size_t	(*find)(const t_string *const self, const char *const other);	/* Function to find a substring in the string */
};

struct s_string_memory
{
	t_string	*(*duplicate)(const t_string *const self);	/* Function to duplicate the string */
};

struct s_string
{
	char		*str;						/* Pointer to the string data */
	size_t		len;						/* Length of the string      */
	t_append	append;						/* Function pointers for appending strings */
	t_check		check;						/* Function pointers for comparing strings */
	void		(*destroy)(t_string *self);	/* Pointer to a function to destroy the string */
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

//...


#endif /* !STRING_H */