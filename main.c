/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:09:41 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/23 10:10:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super-libft.h"

int main(void)
{
	char	str[10] = "Hello";
	ft_memset(str, 'a', 5);
	printf("%s\n", str);
	return (0);
}