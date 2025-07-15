/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 08:20:10 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/24 08:21:46 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| interface |----- */
#include "args_parser.h"

/* -----| Internal  |----- */
// #include "_args.h"

#pragma endregion Headers
#pragma region Functions

/**
 * adds an argument to the parser (e.g. <filename>, <path>)
 */
int	add_args(
	const char *const restrict name,
	const t_types type,
	const char *const restrict desc
)
{
	//...
}

/**
 * adds an option to the parser (e.g. -h, --help)
 */
int	add_options(
	const char *const restrict lname,
	const t_types type,
	const char *const restrict desc
)
{
	//...
}

/**
 * loads the configuration from a given structure
 * 
 * config -> arrays of t_option and t_args
 * nb_options -> number of options in the config (should be the first one in the void *)
 * nb_args -> number of args in the config (should be the second one in the void *)
 */
int	load_config(
	const void *const restrict config,
	const int nb_options,
	const int nb_args
)
{
	
}

/**
 * returns a NULL terminated array of t_args with args parsed
 */
t_args	*get_args(void)
{
	//...
}

#pragma endregion Functions