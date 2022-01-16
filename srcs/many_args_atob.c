/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_args_atob.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:15:54 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/16 19:21:33 by tisoya           ###   ########.fr       */
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

void	replace_atob(t_stacks *stacks, int r_count, int first)
{
	while (r_count > 0 && first == 0)
	{
		r_rot(stacks->b, 2);
		r_count--;
	}
}

int	atob_push_rot(t_stacks *stacks, int r_count)
{
	push(stacks->a, stacks->b, 1);
	rot(stacks->b, 2);
	r_count++;
	return (r_count);
}

void	divide_atob(t_stacks *stacks, int p[], int count, int first)
{
	int	r_count;

	r_count = 0;
	while (count > 0)
	{
		if (stacks->a->next->val <= stacks->sort->ptr[p[0]])
		{
			if (first == 1)
				r_count = atob_push_rot(stacks, r_count);
			else
				push(stacks->a, stacks->b, 1);
			count--;
		}
		else if (stacks->a->next->val <= stacks->sort->ptr[p[1]])
		{
			if (first == 0)
				r_count = atob_push_rot(stacks, r_count);
			else
				push(stacks->a, stacks->b, 1);
			count--;
		}
		else if (stacks->a->next->val > stacks->sort->ptr[p[0]])
			rot(stacks->a, 1);
	}
	replace_atob(stacks, r_count, first);
}

void	atob(t_stacks *stacks, int l, int r, int first)
{
	int		count;
	int		p[2];
	int		r_count;
	t_node	*node_a;
	t_node	*node_b;

	node_a = stacks->a;
	node_b = stacks->b;
	if (r - l <= 2)
		return ;
	p[1] = (l + r) / 2;
	p[0] = (l + p[1]) / 2;
	count = under_pivot(node_a, stacks->sort->ptr[p[1]],
			stacks->sort->ptr[l], stacks->sort->ptr[r]);
	divide_atob(stacks, p, count, first);
	atob(stacks, p[1] + 1, r, 0);
	if (node_a->val == 3)
		case_three(node_a);
	else if (node_a->val == 2)
		case_two(node_a);
	btoa(stacks, p[0] + 1, p[1]);
	btoa(stacks, l, p[0]);
}
