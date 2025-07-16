/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:11:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/16 18:40:33 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H
# define SFT_IO_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
# include <stddef.h>
#include <sys/types.h>

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
# include "_internal/_io.h"

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

struct s_file
{
	char		data[sizeof(struct s_sft_file)];
	ssize_t		(*read)(t_file *const file, void *buffer, size_t size);
	ssize_t		(*write)(t_file *const file, const void *buffer, size_t size);
	int			(*close)(t_file *const file);
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

t_file	*sft_open(
			const char *const filename,
			const int mode,
			const int permissions
			);

ssize_t	sft_read(
			t_file *const file,
			void *buffer,
			size_t size
			);

ssize_t	sft_write(
			t_file *const file,
			const void *const buffer,
			size_t size
			);

int	sft_close(
			t_file *const file
			);

#endif /* !IO_H */