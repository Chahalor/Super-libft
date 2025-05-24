/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:13:55 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/24 14:26:35 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# pragma once

/* ************************************************************************** */
/*                                 Config                                     */
/* ************************************************************************** */

# if !defined (DEBUG)
#  define DEBUG 0	/* 0: disable the debug, 1 enable it */
# endif // !defined (DEBUG)

# if defined (DEFAULT)	// compile the default version of the libft
#  define LIBFT_VERSION "2.0"
# endif // defined (DEFAULT)

# if defined (MANAGER)	// compile the manager version of the libft
// think do define for the manager
# endif // defined (MANAGER)

# if defined (ARGS) // compile the args parser
// think do define for the args parser
# endif // defined (ARGS)

# if defined (ADVANCED) // compile the advanced version of the libft
// set to true all think before
# endif // defined (ADVANCED)

#endif // CONFIG_H