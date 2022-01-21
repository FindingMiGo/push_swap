/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:19:21 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/21 15:36:44 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*alloc_node(t_node *sentinel, size_t i)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
	{
		free_node(sentinel, i);
		shutdown();
	}
	return (node);
}

t_node	*init_node(int args, char *argv[])
{
	t_node	*sentinel;
	t_node	*tmp;
	size_t	i;

	sentinel = (t_node *)malloc(sizeof(t_node));
	if (!sentinel)
		shutdown();
	sentinel->index = 0;
	tmp = sentinel;
	i = 0;
	while (i + 1 < args)
	{
		tmp->next = alloc_node(sentinel, i);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		tmp->index = i + 1;
		tmp->next = NULL;
		tmp->val = atoi_and_errcheck(argv[i + 1], sentinel, i + 1);
		i++;
	}
	tmp->next = sentinel;
	sentinel->prev = tmp;
	sentinel->val = i;
	vals_storage(sentinel, NULL, NULL, NULL);
	return (sentinel);
}

void	re_index(t_node *node)
{
	t_node	*tmp;
	int		i;

	tmp = node->next;
	i = 0;
	while (tmp != node)
	{
		tmp->index = i + 1;
		tmp = tmp->next;
		i++;
	}
	node->val = i;
}
