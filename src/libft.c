/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:54:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/16 15:38:00 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| System   |-----*/
#include <stdlib.h>

/* -----| Internal |-----*/
	//...

/* -----| Module   |-----*/
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
			.sqrt = NULL,		// Placeholder for square root function
			.pow = NULL,		// Placeholder for power function
			.abs = NULL,		// Placeholder for absolute value function
			.max = NULL,		// Placeholder for max function
			.min = NULL,		// Placeholder for min function
			.constants = {
				.pi = 3.141592653589793,
				.e = 2.718281828459045,
				.two_pi = 6.283185307179586,
				.half_pi = 1.570796326794897,
			}
		},
		.io = {
			.open = NULL,		// Placeholder for file open function
			.read = NULL,		// Placeholder for file read function
			.write = NULL,		// Placeholder for file write function
			.close = NULL,		// Placeholder for file close function
			.defaults = {
				.stdin = NULL,	// Placeholder for stdin
				.stdout = NULL,	// Placeholder for stdout
				.stderr = NULL,	// Placeholder for stderr
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
