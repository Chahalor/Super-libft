/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _args.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 08:23:29 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/24 08:42:08 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARGS_H
# define _ARGS_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* Systeme  */
	//...

/* Global   */
	//...

/* Modules  */
# include "args_parser.h"

/* Internal */
	//...

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef struct s_args		t_args;			/**/

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

enum e_args_access
{
	e_args_add,
	e_args_get,
	e_args_parse
}

enum e_args_access
{
	e_access_args,
	e_access_options
}

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_access
{
	void	*data;	// Data to be added or retrieved
	char	access;	// Access type ()
}

struct s_parser
{
	t_args		args[MAX_ARGS];
	t_option	options[MAX_OPTIONS];
	int			nb_args;
	int			nb_options;
	int			error_code;
	char		first_access	: 1;
};

#endif	/* !_ARGS_H */