/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _memory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:40:28 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/22 11:08:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Includes"

/* Systeme */

/* Global */
	//...

/* Modules */
#include "args_parser.h"
#include "_args.h"

#pragma endregion Includes
#pragma region Functions

/** */
__attribute__((cold, visibility("hidden"))) void	_destroy_args(
	t_args *args
)
{
	t_args	*tmp;
	t_args	*current;

	tmp = args->next;
	current = args;
	while (current)
	{
		if (tmp->type == e_str)
			free(tmp->value.s_value);
		free(current);
		current = tmp;
		if (tmp)
			tmp = tmp->next;
	}
	free(current);
	free(tmp);
	free(args);
}

/** */
__attribute__((cold, visibility("hidden"))) void	_destroy_options(
	t_option *options
)
{
	if (options->builtin)
		return ;
	else
	{
		if (options->name)
			free(options->name);
		if (options->doc)
			free(options->doc);
		if (options->argument)
			destroy_args(options->argument);
		free(options);
	}
}

/** */
__attribute__((cold, visibility("hidden"))) void	*_destroy_parser(
	t_parser *parser
)
{
	register int	i;
	
	if (!parser)
		return ;
	i = -1;
	while (++i < parser->nb_options)
		if (parser->options[i] && !parser->options[i]->builtin)
			destroy_options(parser->options[i]);
	i = -1;
	while (++i < parser->nb_args)
		if (parser->args[i])
			destroy_args(parser->args[i]);
	free(parser->options);
}

#pragma endregion Functions