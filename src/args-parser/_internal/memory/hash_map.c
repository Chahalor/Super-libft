/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:43:35 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/22 11:57:33 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| interface |----- */
#include "memory.h"
#include "args_parser.h"

/* -----| Internal  |----- */
// #include "_memory.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((hot)) unsigned int hash(
	const char *str
)
{
	unsigned int	hash;
	int				c;

	hash = 5381;
	c = *str++;
	while (c)
	{
		hash = ((hash << 5) + hash) + c;
		c = *str++;
	}
	return (hash % BUCKET_SIZE);
}

int	option_map_insert(
	t_hmap *map,
	const char *key,
	t_option *opt
)
{
	unsigned int index = map->hash(key);
	t_hmap_node *node = map->bucket[index];

	while (node)
	{
		if (ft_strcmp(node->key, key) == 0)
			return (-1);
		node = node->next;
	}
	node = (t_hmap_node *)malloc(sizeof(t_hmap_node) + sizeof(char) * (ft_strlen(key) + 1));
	node->key = ft_memcpy(node->key, key, ft_strlen(key) + 1);
	node->opt = opt;
	node->next = map->buckets[index];
	map->buckets[index] = node;
	return 0;
}


#pragma endregion Functions