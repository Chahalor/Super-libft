/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:54:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/02 11:58:22 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_libft	*libft(void)
{
	static t_libft	*instance = NULL;

	if (!instance)
	{
		instance = malloc(sizeof(t_libft));
		if (!instance)
			return (NULL);
	}
	return (instance);
}

#define libft	libft()

int main(int argc, char const *argv[])
{

	return (0);
}
