/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _scan.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:11:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/18 08:59:50 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCAN_H
# define _SCAN_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
# include "../_io.h"
# include "io.h"

/* -----| Modules   |----- */
	//...

/* ************************************************************************** */
/*                                 Macros                                     */
/* ************************************************************************** */

# define NB_CHAR_INT	10	/* Max number of char inside an interger */
# define NB_CHAR_LONG	20
# define NB_CHAR_FLOAT	32
# define NB_CHAR_DOUBLE	64

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_sft_scan	t_sft_scan;	/* Scan structure type definition */

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_sft_scan
{
	va_list			args;			/* Arguments list for the scan */
	char			*format;		/* Format string for the scan */
	int				nb_read;		/* Number of characters read */
	t_file			*file;			/* fd for the scan          */
	unsigned char	error	: 1;	/* Error flag              */
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

int	_read_numbers(
		t_sft_scan *const scan,
		const char format
		);

int	_read_chars(
		t_sft_scan *const scan,
		const char format
		);

#endif /* !_SCAN_H */