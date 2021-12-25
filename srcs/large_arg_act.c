/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_arg_act.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:21:53 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/24 16:12:48 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*btoa(t_node *node_a, t_node *node_b)
{
	int		count;
	t_node	*tmp;

	count = 0;
	while (node_b->val > 0)
	{
		set_min(node_b, 2);
		push(node_b, node_a, 2);
		rot(node_a, 1);
		count++;
	}
	tmp = node_a;
	while (count > 0)
	{
		tmp = tmp->prev;
		count--;
	}
	return (tmp);
}

void	three_div(t_node *node_a, t_node *node_b, t_sort *sort)
{
	t_node	*tmp;
	int		pivot1;
	int		pivot2;
	size_t	i;

	pivot1 = sort->ptr[sort->size / 3 - 1];
	pivot2 = sort->ptr[(sort->size * 2) / 3 - 1];

	tmp = node_a->prev;
	i = node_a->val;
	// printf("%ld\n", i);
	while (i > 0)
	{
		// printf("val:%d\n", node_a->next->val);
		if (node_a->next->val <= pivot1)
			push(node_a, node_b, 1);
		else if (node_a->next->val <= pivot2)
		{
			push(node_a, node_b, 1);
			rot(node_b, 2);
		}
		else if (node_a->next->val > pivot2 && node_a->next != tmp)
			rot(node_a, 1);
		i--;
	}
	tmp = btoa(node_a, node_b);
	print_node(node_a, 1);
	print_node(node_b, 1);
	printf("stopper? %d\n", tmp->val);
}

void	case_gt_six(t_node *node_a, t_node *node_b, t_sort *sort)
{
	three_div(node_a, node_b, sort);
}
