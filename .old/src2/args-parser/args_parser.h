/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 08:20:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/22 14:38:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_PARSER_H
# define ARGS_H

#pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* Systeme  */
# include <stdlib.h>
# include <errno.h>

/* Global   */
# include "type.h"

/* Modules  */
	//...

/* Internal */
# include "_internal/_args.h"

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

# define PARSER_MAJOR		0
# define PARSER_MINOR		1
# define PARSER_PATCH		0

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef enum e_types		t_types;		/**/
typedef enum e_args_error	t_args_error;	/**/

typedef union u_value		t_value;		/**/

typedef struct s_args		t_args;			/**/
typedef struct s_option		t_option;		/**/
typedef struct s_parser		t_parser;		/**/

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

enum e_args_error
{
	e_no_error,				/**/
	e_invalid_option,		/**/
	e_invalid_argument,		/**/
	e_missing_argument,		/**/
	e_unknown_option,		/**/
	e_too_many_arguments,	/**/
	e_invalid_type			/**/
};

/* ************************************************************************** */
/*                                 Unions                                     */
/* ************************************************************************** */

union u_value
{
	int		i_value;	/**/
	char	*s_value;	/**/
	t_bool	b_value;	/**/
};

/* ************************************************************************** */
/*                                 Struct                                     */
/* ************************************************************************** */

struct s_args
{
	t_types	type;				/**/
	t_value	value;				/**/
	t_bool	mandatory	: 1;	/**/
	t_args	*next;				/**/
	t_bool	parsed	: 1;		/**/
};

struct s_option
{
	char	*name;			/**/
	char	*doc;			/**/
	t_args	*argument;		/**/
	int		id;				/**/
	t_bool	builtin	: 1;	/**/
	t_bool	used	: 1;	/**/
};

struct s_parser
{
	t_option	**options;				/**/
	t_args		**args;					/**/
	int			nb_options;				/**/
	int			nb_args;				/**/
	void		(*destroy)(t_parser *);									/**/
	int			(*parse)(t_parser *, int, const char **);				/**/
	int			(*add_option)(t_parser *, char *, char *, t_types);		/**/
	int			(*add_argument)(t_parser *, char *, char *, t_types);	/**/
	void		*(*get_options)(t_parser *);				/**/
	void		*(*get_arguments)(t_parser *);				/**/
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

/* args_parser.c */

t_parser	*parser_init(void);

void		*parser_destroy(
	t_parser *parser
);

int			add_option(
	t_parser *parser,
	char *name,
	char *doc,
	t_types type
);

void		*get_option(
	t_parser *parser
);

void		*get_arguments(
	t_parser *parser
);

int			parse(
	t_parser *parser,
	int argc,
	const char **argv
);

#endif	/* ARGS_H */