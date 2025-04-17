/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 08:20:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/17 12:52:10 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

#pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* Systeme  */
# include <stdlib.h>
# include <errno.h>

/* Global   */
# include "../standare/type.h"

/* Modules  */
	//...

/* Internal */
# include "_args.h"

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

# define PARSER_MAJOR		0
# define PARSER_MINOR		1
# define PARSER_PATCH		0

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef enum e_types	t_types;	/**/

typedef struct s_args	t_args;		/**/
typedef struct s_option	t_option;	/**/
typedef struct s_parser	t_parser;	/**/

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

enum e_types
{
	e_none,	/**/
	e_flag,	/**/
	e_int,	/**/
	e_str,	/**/
};

/* ************************************************************************** */
/*                                 Struct                                     */
/* ************************************************************************** */

struct s_args
{
	t_types	type;				/**/
	union u_value
	{
		int		i_value;
		char	*s_value;
		t_bool	b_value	: 1;
	}		value;				/**/
	t_bool	mandatory	: 1;	/**/
	t_args	*next;				/**/
};

struct s_option
{
	char	*name;			/**/
	char	*short_option;	/**/
	char	*long_option;	/**/
	char	*doc;			/**/
	t_types	type;			/**/
	t_args	*argument;		/**/
	int		id;				/**/
};

struct s_parser
{
	const int	version[3];				/**/
	t_option	**options;				/**/
	int			count;					/**/
	void	(*destroy)(t_parser *);												/**/
	int		(*parse)(t_parser *, int, const char **);	/**/
	int		(*add_option)(t_parser *, char *, char *, t_types, t_args *);	/**/
	t_args	(*get_option)(t_parser *, void *, int);									/**/
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

/* File.c */

#endif	/* ARGS_H */