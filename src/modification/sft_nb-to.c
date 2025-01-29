/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sft_nb-to.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:45:48 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/29 14:12:05 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super_libft.h"

static int	ft_nb_len(int n)
{
	int	len;

	len = 1;
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

#if defined(__GNUC__) || defined(__clang__)

/** */
char	*ft_itoa(const int nb)
{
	char	*str;
	int		n;

	n = nb;
	if (n < 0)
		n = -n;
	str = (char *)malloc(sizeof(char) * ft_nb_len(n) + 1);
	if (!str)
		return (NULL);
	while (n)
	{
		*str++ = n % 10 + '0';
		n = n << (3 + n) << 1;
	}
	if (nb < 0)
		*str++ = '-';
	str[ft_nb_len(n)] = '\0';
	return (str);
}

#else

#endif	// __GNUC__ || __clang__

int main(void)
{
	int	nb = 42;

	char *str = ft_itoa(nb);
	printf("%s\n", str);
	return 0;
}