/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:02:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/04 09:15:11 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*
#include "strings/string.h"
static void	test_string(void)
{
	t_string	*str1 = new_t_string("Hello, ");
	t_string	*str2 = new_t_string("World!");

	if (!str1 || !str2)
	{
		if (str1)
			str1->destroy(str1);
		if (str2)
			str2->destroy(str2);
		return ;
	}
	str1->append.t_string(str1, str2);
	printf("Appended String: <%s> (%zu)\n", str1->str, str1->len);
	str1->append.str(str1, " How are you?");
	printf("Final String: <%s> (%zu)\n", str1->str, str1->len);
	
	printf("Comparing strings: %d\n", str1->check.cmp(str1, NULL));
	printf("finding strings: %zu\n", str1->check.find(str1, NULL));
	printf("Comparing strings: %d\n", str1->check.ncomp(str1, NULL, 2));

	t_string	*str3 = str1->memory.duplicate(str1);

	printf("Duplicated String: <%s> (%zu)\n", str3->str, str3->len);
	printf("Comparing strings: %d\n", str1->check.cmp(str1, str3));

	str3->destroy(str3);
	str2->destroy(str2);
	str1->destroy(str1);
}
*/

#include "error/error.h"
static void	test_error(void)
{
	sft_perror("Test error message");

	printf("Error string: <%s>\n", sft_error_str(SFT_ERR_SUCCESS));
}

int main(void)
{
	test_error();
	return (0);
}