/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:40:03 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/16 15:54:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

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
# include "io/io.h"
# include "strings/string.h"

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_libft	t_libft;	/* Libft main structure */

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_sft_memory
{
	void		*(*const alloc)(size_t size);
	void		*(*const realloc)(void *ptr, size_t nsize);
	void		(*const free)(void *ptr);
	void		*(*const duplicate)(const void *ptr, size_t size);
	t_string	*(*const new_string)(const char *str);
};

struct s_sft_check
{
	int	(*const is_number)(const char *str);
	int	(*const is_alpha)(const char *str);
	int	(*const is_ascii)(const char *str);
};

struct s_sft_math
{
	size_t	(*const sqrt)(size_t n);
	size_t	(*const pow)(size_t base, size_t exp);
	size_t	(*const abs)(int n);
	size_t	(*const max)(size_t a, size_t b);
	size_t	(*const min)(size_t a, size_t b);
	struct s_sft_math_constants
	{
		const double	pi;
		const double	e;
		const double	two_pi;
		const double	half_pi;
	}		constants;
};

struct s_sft_io
{
	t_file	*(*const open)(const char *const filename, const int mode);
	int		(*const read)(t_file *file, void *buffer, size_t size);
	int		(*const write)(t_file *file, void *buffer, size_t size);
	int		(*const close)(t_file *file);
	struct s_sft_io_defaults
	{
		t_file	*const stdin;
		t_file	*const stdout;
		t_file	*const stderr;
	}	defaults;
};

struct s_sft_error
{
	char	(*const register_error)(const int error);
	int		(*const get_error)(void);
	char	*(*const strerror)(int error);
};

struct s_sft_log
{
	int	(*const add_log)(const char *message, const int mode);
	int	(*const add_logf)(const char *format, const int mode, ...);
	int	(*const write_log)(const char *message, t_file *file);
	int	(*const write_logf)(const char *format, t_file *file, ...);
	int	(*const store_log)(t_file *file);
};

struct s_libft
{
	struct s_sft_memory	memory;	// all memory management functions
	struct s_sft_check	check;	// all check functions (e.g. is_empty, is_equal)
	struct s_sft_math	math;	// all math functions (e.g. sqrt, pow)
	struct s_sft_io		io;		// all string I/O functions (e.g. read, write)
	struct s_sft_error	error;	// all error handling functions (e.g. register_error, get_error)
	struct s_sft_log	log;	// all logging functions (e.g. log_info, log_error)
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

// ...

#endif