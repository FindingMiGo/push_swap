/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:10:53 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/21 05:09:40 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_node(t_node *node, int count)
{
	t_node	*head;
	t_node	*tmp;

	head = node;
	node = node->next;
	while (node != head && count)
	{
		tmp = node->next;
		free(node);
		node = tmp;
		count--;
	}
	free(head);
}

void	free_nodes(t_node *node1, t_node *node2)
{
	if (node1)
		free_node(node1, node1->val);
	if (node2)
		free_node(node2, node2->val);
}

void	free_all(t_node *node1, t_node *node2, t_sort *sort, char *record)
{
	free(record);
	if (sort)
	{
		free(sort->ptr);
		free(sort);
	}
	free_nodes(node1, node2);
}

void	vals_storage(t_node *node, t_stacks *stacks,
			t_sort *sort, char **record)
{
	static t_node	*n[2];
	static t_stacks	*st;
	static t_sort	*s;
	static char		**r;

	if (!node && !stacks && !sort && !record)
	{
		if (r)
			free_all(n[0], n[1], s, *r);
		else
			free_all(n[0], n[1], s, NULL);
		free(st);
		free(r);
		return ;
	}
	if (node && !n[0])
		n[0] = node;
	else if (node && !n[1] && n[0] != node)
		n[1] = node;
	if (stacks)
		st = stacks;
	if (sort)
		s = sort;
	if (record)
		r = record;
}

void	shutdown(void)
{
	vals_storage(NULL, NULL, NULL, NULL);
	exit(EXIT_FAILURE);
}
