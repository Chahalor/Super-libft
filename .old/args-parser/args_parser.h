/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 08:20:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/24 08:39:19 by nduvoid          ###   ########.fr       */
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
	//...

/* Modules  */
	//...

/* Internal */
# include "_internal_/_args.h"

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

# define PARSER_MAJOR		0
# define PARSER_MINOR		1
# define PARSER_PATCH		0

# define MAX_ARGS			128		/**/
# define MAX_OPTIONS		64		/**/

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
	char	b_value;	/**/
};

/* ************************************************************************** */
/*                                 Struct                                     */
/* ************************************************************************** */

struct s_arg
{
	const char	*name;				// help
	const char	*help_text;			// Aide pour l'option
	char		*value;				// NULL ou la valeur passée
	char		has_value	: 1;	// 0 = bool flag, 1 = requires value
	char		is_set		: 1;	// 1 si présent dans argv
}

struct s_option
{
	const char	*name;				// Nom de l'option (ex: --help)
	const char	*description;		// Description de l'option
	t_types		type;				// Type de l'option (flag, int, str, etc.)
	char		is_required	: 1;	// Indique si l'option est obligatoire
}

struct s_args
{
	const char	*name;	// Nom de l'argument (ex: --output)
	t_value		value;	// Valeur de l'argument
	t_types		type;	// Type de l'argument (flag, int, str, etc.)
}

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

//...

#endif	/* !ARGS_H */