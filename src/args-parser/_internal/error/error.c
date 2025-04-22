/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:59:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/22 15:09:56 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| interface |----- */
#include "args_parser.h"
#include "str.h"
#include "formating.h"

/* -----| Internal  |----- */
#include "_args.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((cold)) void show_error(
	const t_error error,
	const int argc,
	const char **argv
)
{
	register int	i;
	static const char	*error_messages[] = {
		[e_no_error] = "",
		[e_invalid_option] = "Invalid option",
		[e_invalid_argument] = "Invalid argument",
		[e_missing_argument] = "an argument is missing",
		[e_unknown_option] = "unknown option",
		[e_too_many_arguments] = "too many arguments",
		[e_invalid_type] = "Invalid type"
	};

	if (error.error == e_no_error)
		return ;
	ft_printf(RED "Error: " RESET "%s\n", error_messages[error.error]);
	ft_prntf(PADD "Here: %s\n\t" PADD "\n", argv[error.index]);
	i = -1;
	while (++i < error.pos)
		write(1, "─", 3);
	write(1, "^\n", 2);
}
#pragma endregion Functions