/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _args-parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:11:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/21 11:30:11 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARGS_PARSER_H
# define _ARGS_PARSER_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* -----| Systems   |----- */
	//...

/* -----| Globals   |----- */
	//...

/* -----| Internals |----- */
	//...

/* -----| Modules   |----- */
# include "args-parser/args-parser.h"

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_sft_args_spec	t_sft_args_spec;
typedef t_sft_args_spec			t_args_spec;
typedef struct s_args_data		t_args_data;

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

enum e_arg_builtin
{
	arg_builtin_not_a_builtin,
	arg_builtin_help,
};

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_args_data
{
	int				argc;
	char			**argv;
	char			*one_string;
	int				nb_parsed;
	unsigned char	error	: 1;
	unsigned char	help	: 1;
	unsigned char	version	: 1;
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

// utils.c

int		_isspace(const char c);
int		_word_size(const char *str);
int		_count_digits(char *n);
char	*_worddup(const char *str);
char	*cat_options(const int argc, const char **argv);

// help.c

int		_show_help(const t_args_spec *specs, t_args_data *args_data);

// builtin.c

t_args_spec	*_get_builtin_args(void);

#endif /* !_ARGS_PARSER_H */