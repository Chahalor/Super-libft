/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 08:26:19 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/04 08:27:34 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	*__mon_state_location(void)
{
	static int	val = 0;

	return (&val);
}

#define mon_state (*__mon_state_location())

int	main(void)
{
	mon_state = 42;
	printf("mon_state = %d\n", mon_state);
	return 0;
}
