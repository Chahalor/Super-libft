/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _error.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 08:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/04 09:18:09 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region    Header

/* -----| System   |-----*/
#include <stdlib.h>
#include <unistd.h>

/* -----| Internal |-----*/
#include "_error_.h"
#include "../error.h"

/* -----| Module   |-----*/
	//...

#pragma endregion Header
#pragma region    Defines

#define STF_MAX_ERRCODES	2

#pragma endregion Defines
#pragma region    Functions

static inline char	*_str(
	const int error
)
{
	static const char	*const error_strings[STF_MAX_ERRCODES] = {
		[SFT_ERR_SUCCESS] = "Success",
		[SFT_ERR_NOMEM] = "Memory allocation failed"
	};
	const int	index = error * (error >= 0 && error < STF_MAX_ERRCODES);

	return ((char *)error_strings[index]);
}

__attribute__((visibility("hidden"), used)) void	*_error_manager(
	const int error,
	const int access
)
{
	static int	_error = 0;

	if (access == err_register)
	{
		_error = error;
		return (&_error);
	}
	else if (access == err_get)
		return (&_error);
	else if (access == err_str)
		return (_str(error));
	else
		return (NULL);
}

#pragma endregion Functions