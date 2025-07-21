/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:02:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/07/21 10:33:00 by nduvoid          ###   ########.fr       */
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

	t_string	*str4 = new_t_string("12345");
	printf("String to int: %d\n", str4->change.atoi(str4));
	printf("String to long: %ld\n", str4->change.atol(str4));
	printf("String to float: %f\n", str4->change.atolf(str4));
	t_string	*str5 = str4->change.itos(12345);

	str5->destroy(str5);
	str4->destroy(str4);
	str3->destroy(str3);
	str2->destroy(str2);
	str1->destroy(str1);
}
*/
/*
#include "error/error.h"
static void	test_error(void)
{
	sft_perror("Test error message");

	printf("Error string: <%s>\n", sft_error_str(SFT_ERR_SUCCESS));
}
*/
/*
#include "_internal_/memory/_memory.h"
static void	test_memory(void)
{
	void	*ptr1 = _alloc(50);
	
	register int i = -1;
	while (++i < 50)
		((char *)ptr1)[i] = i;
	i = -1;
	while (++i < 50)
		printf("%d ", ((char *)ptr1)[i]);
	printf("\n");
}
*/
/*
#include "io/io.h"
#include <fcntl.h>
#include <string.h>
void	test_io(void)
{
	t_file	*file = sft_open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

	if (!file)
	{
		perror("Failed to open file");
		return ;
	}

	const char *data = "Hello, Super-libft!";
	// if (file->print(file, "%s\n", data) < 0)
	// {
	// 	perror("Failed to write to file");
	// 	file->close(file);
	// 	return ;
	// }
	sftout()->print(sftout(), "Data written to file: %s\n", data);
	int	tkt = 0;
	char buffer[100];
	sftin()->scan(sftin(), "%x", &tkt, buffer);
	sftout()->print(sftout(), "Scanned value: %d\n", tkt);
	sftout()->print(sftout(), "Scanned string: <%s>\n", buffer);
	file->close(file);
}*/

/*
#include "math/math.h"
void	test_math(void)
{
	printf("Square root of 16: %zu\n", sft_math_sqrt(16));
	printf("Power of 2^3: %f\n", sft_math_pow(2, 3));
	printf("Absolute value of -42: %f\n", sft_math_abs(-42));
	printf("Max of 5 and 10: %f\n", sft_math_max(5, 10));
	printf("Min of 5 and 10: %f\n", sft_math_min(5, 10));
}*/

#include "args-parser/args-parser.h"
void	test_args(int argc, char **argv)
{
	int		help = 0;
	int		version = 0;
	char	*input_file = NULL;

	t_args_spec spec[] = {
		{ .name = "file", .short_name = 'f', .type = ARG_TYPE_FILE, .help = "Input file", .value_ptr = &input_file, .default_value = NULL, .required = 1, .is_positional = 1 },
		{ .name = "help", .short_name = 'h', .type = ARG_TYPE_BOOL, .help = "Show help message", .value_ptr = &help, .default_value = "0", .required = 0, .is_positional = 0 },
		{ .name = "version", .short_name = 'v', .type = ARG_TYPE_BOOL, .help = "Show version information", .value_ptr = &version, .default_value = "0", .required = 0, .is_positional = 0 },
		{ .name = "input", .short_name = 'i', .type = ARG_TYPE_FILE, .help = "Input file", .value_ptr = &input_file, .default_value = NULL, .required = 1, .is_positional = 0 },
		{ .name = NULL }
	};

	if (args_parser(argc, (const char **)argv, spec) < 0)
	{
		fprintf(stderr, "Error parsing arguments\n");
		return;
	}

	printf("help: %d\n"
		   "version: %d\n"
		   "input_file: <%s>\n", help, version, input_file);
}

int main(int argc, char **argv)
{
	// test_string();
	// test_memory();
	// test_io();
	// test_math();
	// test_simd();
	test_args(argc, argv);
	
	return (0);
}