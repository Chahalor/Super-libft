/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args-parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:11:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/21 10:30:57 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_PARSER_H
# define ARGS_PARSER_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
	//...

/* -----| Globals   |----- */	
	//...

/* -----| Internals |----- */
# include "_internal/_args-parser.h"

/* -----| Modules   |----- */
# include "strings/string.h"

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef unsigned char				t_uchar;

typedef enum e_sft_arg_type			t_sft_arg_type;

typedef struct s_sft_args_config	t_sft_args_config;
typedef struct s_sft_args_spec		t_sft_args_spec;
typedef t_sft_args_spec				t_args_spec;

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

enum e_sft_arg_type
{
	ARG_TYPE_BOOL,
	ARG_TYPE_INT,
	ARG_TYPE_STRING,
	ARG_TYPE_FILE
};

/* ************************************************************************** */
/*                                 Unions                                     */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_sft_args_spec
{
	const char		*name;
	char			short_name;
	t_sft_arg_type	type;
	const char		*help;
	void			*value_ptr;
	const char		*default_value;
	t_uchar			required		: 1;
	t_uchar			is_positional	: 1;
	t_uchar			_is_set			: 1;
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

int	args_parser(
			const int argc,
			const char **argv,
			t_args_spec *specs
			);

#endif /* !ARGS_PARSER_H */