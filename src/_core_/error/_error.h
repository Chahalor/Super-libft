/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _error.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 08:38:21 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/04 10:24:42 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ERROR_H
# define _ERROR_H

# pragma once

#include "./error.h"

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

char	_register_error(
				const int error
				);

int		_get_error(void);

#endif /* !_ERROR_H */