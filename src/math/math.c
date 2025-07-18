/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:08:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/18 09:29:35 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Header

/* -----|  System  |-----*/
	//...

/* -----| Internal |-----*/
// #include "_internal/_math.h"
#include "math.h"

/* -----|   Core   |-----*/
#include "error/_error.h"
#include "shortcut/_shortcut.h"

/* -----|  Module  |-----*/
	//...

#pragma endregion Header
#pragma region    Functions

double	sft_math_abs(
	double value
)
{
	return (__builtin_fabs(value));
}

size_t	sft_math_sqrt(
	double value
)
{
	const double	epsilon = 1e-10;
	double			x;
	double			last;

	if (value <= 0.0)
		return (0);
	x = value;
	last = 0.0;
	while (x != last)
	{
		last = x;
		x = 0.5 * (x + value / x);
		if (sft_math_abs(x - last) < epsilon)
			break;
	}
	return (x);
}

double	sft_math_pow(
	double base,
	double exponent
)
{
	register double	result;

	result = 1.0;
	while (exponent)
	{
		result *= base;
		--exponent;
	}
	return (result);
}

double	sft_math_max(
	double a,
	double b
)
{
	return (a * (a >= b) + b * (b > a));
}

double	sft_math_min(
	double a,
	double b
)
{
	return (a * (a <= b) + b * (b < a));
}
#pragma endregion Functions