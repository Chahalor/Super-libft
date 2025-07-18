/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _io.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:11:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/18 08:20:19 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _IO_H
# define _IO_H

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

typedef struct s_file	t_file;	/* File structure type definition */

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_sft_file
{
	char			*path;			/* File path                               */
	int				fd;				/* File descriptor                        */
	size_t			advance;		/* how much we have advanced in the file */
	unsigned char	eof		: 1;	/* End of file reached                  */
	unsigned char	closed	: 1;	/* File is closed                      */
	unsigned char	std		: 1;	/* Is a standard file                 */
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

t_file	*_sft_io_open(
			const int fd,
			const char *const filename
			);

int		sft_printf(
			t_file *const file,
			const char *const restrict format,
			...);

int		sft_scan(
			t_file *const file,
			const char *const restrict format,
			...);

#endif /* !_IO_H */