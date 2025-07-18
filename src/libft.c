/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:54:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/18 09:31:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| System   |-----*/
#include <stdlib.h>

/* -----| Internal |-----*/
	//...

/* -----| Module   |-----*/
#include "io/io.h"
#include "math/math.h"
#include "strings/string.h"
#include "libft.h"

t_libft	*libft(void)
{
	const static t_libft	libft_instance = {
		.memory = {
			.alloc = malloc,	// @todo: replace by our mem manager
			.realloc = realloc,	// @todo: replace by our realloc
			.free = free,		// @todo: same here
			.duplicate = NULL, // Placeholder for duplication function
			.new_string = new_t_string,
		},
		.check = {
			.is_number = NULL,	// Placeholder for number check function
			.is_alpha = NULL,	// Placeholder for alpha check function
			.is_ascii = NULL,	// Placeholder for ASCII check function
		},
		.math = {
			.sqrt = sft_math_sqrt,
			.pow = sft_math_pow,
			.abs = sft_math_abs,
			.max = sft_math_max,
			.min = sft_math_min,
			.constants = {
				.pi = 3.14,
				.e = 2.71,
				.two_pi = 6.28,
				.half_pi = 1.57,
			}
		},
		.io = {
			.open = sft_open,
			.read = sft_read,
			.write = sft_write,
			.close = sft_close,
			.defaults = {
				.stdin = sftin,
				.stdout = sftout,
				.stderr = sfterr,
			}
		},
		.error = {
			.register_error = NULL, // Placeholder for error registration function
			.get_error = NULL,      // Placeholder for getting error function
			.strerror = NULL,       // Placeholder for error string function
		},
		.log = {
			.add_log = NULL,       // Placeholder for adding log function
			.add_logf = NULL,      // Placeholder for formatted log function
			.write_log = NULL,     // Placeholder for writing log to file
			.write_logf = NULL,    // Placeholder for formatted log to file
			.store_log = NULL,     // Placeholder for storing log
		}
	};
	return ((t_libft *)&libft_instance);
}

#define libft	libft()

int main(int argc, char const *argv[])
{

	return (0);
}
