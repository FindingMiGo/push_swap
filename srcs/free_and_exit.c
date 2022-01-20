/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:10:53 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/20 22:19:23 by tisoya           ###   ########.fr       */
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
	free_node(node1, node1->val);
	free_node(node2, node2->val);
}

void	free_sort(t_sort *sort)
{
	free(sort->ptr);
	free(sort);
}

void	free_all(t_node *node1, t_node *node2, t_sort *sort, char *record)
{
	free(record);
	free_sort(sort);
	free_nodes(node1, node2);
}
