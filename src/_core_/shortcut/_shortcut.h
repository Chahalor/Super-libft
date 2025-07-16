/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _shortcut.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 08:38:21 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/16 16:49:20 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SHORTCUT_H
# define _SHORTCUT_H

# pragma once

#include <stddef.h>

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

extern int	likely(const int cond);
extern int	unlikely(const int cond);
extern int	_strlen(const char *const str);
extern void	_cpy(
						char *const dest,
						const char *const src,
						const size_t n,
						const int mode
						);

#endif /* !_SHORTCUT_H */