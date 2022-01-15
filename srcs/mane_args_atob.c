/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mane_args_atob.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:15:54 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/15 16:17:32 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	under_pivot(t_node *node, int p, int l, int r)
{
	t_node	*head;
	int		count;

	count = 0;
	head = node;
	node = node->next;
	while (node != head && node->val >= l && node->val <= r)
	{
		if (node->val <= p)
			count++;
		node = node->next;
	}
	return (count);
}

void	atob(t_stacks *stacks, t_sort *sort, int l, int r, int fst)
{
	int		count;
	int		p[2];
	int		r_count;
	t_node	*node_a;
	t_node	*node_b;

	r_count = 0;
	node_a = stacks->a;
	node_b = stacks->b;
	if (r - l <= 2)
		return ;
	p[1] = (l + r) / 2;
	p[0] = (l + p[1]) / 2;
	count = under_pivot(node_a, sort->ptr[p[1]], sort->ptr[l], sort->ptr[r]);
	while (count > 0)
	{
		if (node_a->next->val <= sort->ptr[p[0]])
		{
			push(node_a, node_b, 1);
			if (fst == 0)
			{
				rot(node_b, 2);
				r_count++;
			}
			count--;
		}
		else if (node_a->next->val <= sort->ptr[p[1]])
		{
			push(node_a, node_b, 1);
			if (fst == 1)
			{
				rot(node_b, 2);
				r_count++;
			}
			count--;
		}
		else if (node_a->next->val > sort->ptr[p[0]])
			rot(node_a, 1);
	}
	while (r_count > 0 && fst == 1)
	{
		r_rot(node_b, 2);
		r_count--;
	}
	atob(stacks, sort, p[1] + 1, r, 1);
	if (node_a->val == 3)
		case_three(node_a);
	else if (node_a->val == 2)
		case_two(node_a);
	btoa(stacks, sort, p[0] + 1, p[1]);
	btoa(stacks, sort, l, p[0]);
}
