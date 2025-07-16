/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _error.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 08:14:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/16 09:43:15 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----| System   |-----*/
#include <stdlib.h>
#include <unistd.h>

/* -----| Internal |-----*/
#include "_internal/_error_.h"
#include "error.h"

/* -----| Module   |-----*/
	//...

#pragma endregion Header
#pragma region Functions

/* -----| Internal    |----- */

__attribute__((used)) char	_register_error(
	const int error
)
{
	if (error < 0)
		return (0);
	else
		return (_error_manager(error, err_register) != NULL);
}

__attribute__((used)) int	_get_error(void)
{
	return (*(int *)_error_manager(0, err_get));
}

/* -----| For the lib |----- */

/** */
__attribute__((used))	char	*sft_error_str(
	const int error
)
{
	return ((char *)_error_manager(error, err_str));
}

__attribute__((used, const))	void	sft_perror(
	const char *const restrict message
)
{
	const char	*const restrict error_message = sft_error_str(_get_error());
	register size_t	len;

	if (!message)
		return ;
	len = -1;
	while (message[++len])
		;
	write(STDERR_FILENO, message, len);
	write(STDERR_FILENO, ": ", 2);
	len = -1;
	while (error_message[++len])
		;
	write(STDERR_FILENO, error_message, len);
	write(STDERR_FILENO, "\n", 1);
}

#pragma endregion Functions