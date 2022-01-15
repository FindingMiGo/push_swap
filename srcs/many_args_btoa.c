/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_args_btoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:21:53 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/15 16:32:32 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	over_pivot(t_node *node, int p, int l, int r)
{
	t_node	*head;
	int		count;

	count = 0;
	head = node;
	node = node->next;
	while (node != head && node->val >= l && node->val <= r)
	{
		if (node->val > p)
			count++;
		node = node->next;
	}
	return (count);
}

void	replace(t_stacks *stacks, int p_count, int r_count)
{
	t_node	*a;
	t_node	*b;

	a = stacks->a;
	b = stacks->b;
	while (r_count > 0)
	{
		r_rot(b, 2);
		r_count--;
	}
	while (p_count > 0)
	{
		push(a, b, 1);
		p_count--;
	}
}

void	divide(t_stacks *stacks, t_sort *sort, int p[], int c)
{
	t_node	*a;
	t_node	*b;
	int		p_count;
	int		r_count;
	int		pr_count;

	a = stacks->a;
	b = stacks->b;
	p_count = 0;
	r_count = 0;
	pr_count = 0;
	while (c > 0)
	{
		if (b->next->val > sort->ptr[p[1]])
		{
			push(b, a, 2);
			p_count++;
			c--;
		}
		else if (b->next->val > sort->ptr[p[0]])
		{
			push(b, a, 2);
			rot(a, 1);
			p_count++;
			pr_count++;
			c--;
		}
		else
		{
			rot(b, 2);
			r_count++;
		}
	}
	while (pr_count > 0)
	{
		r_rot(a, 1);
		pr_count--;
	}
	replace(stacks, p_count, r_count);
}

void	btoa(t_stacks *stacks, t_sort *sort, int l, int r)
{
	int		count;
	int		p[2];
	t_node	*node_a;
	t_node	*node_b;
	int		r_count;

	node_a = stacks->a;
	node_b = stacks->b;
	p[0] = (l + r) / 2;
	p[1] = (p[0] + r) / 2;
	count = over_pivot(node_b, sort->ptr[p[0]], sort->ptr[l], sort->ptr[r]);
	if (r - l <= 9 && r >= l)
	{
		int i = r - l + 1;
		while (i > 0)
		{
			set_max(node_b, 2);
			push(node_b, node_a, 2);
			i--;
		}
		i = 0;
		return ;
	}
	divide(stacks, sort, p, count);
	btoa(stacks, sort, p[1] + 1, r);
	btoa(stacks, sort, p[0] + 1, p[1]);
	btoa(stacks, sort, l, p[0]);
}

void	case_gt_six(t_node *node_a, t_node *node_b, t_sort *sort)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	stacks->a = node_a;
	stacks->b = node_b;
	stacks->sort = sort;
	atob(stacks, sort, 0, sort->size - 1, 0);
	free(stacks);
}
