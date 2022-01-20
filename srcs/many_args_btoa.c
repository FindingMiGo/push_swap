/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_args_btoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:21:53 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/21 05:20:23 by tisoya           ###   ########.fr       */
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

void	replace(t_stacks *stacks, int p_count, int r_count, int pr_count)
{
	t_node	*a;
	t_node	*b;

	a = stacks->a;
	b = stacks->b;
	while (pr_count > 0)
	{
		r_rot(a, 1);
		pr_count--;
	}
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

void	divide(t_stacks *stacks, int p[], int c)
{
	int		p_count;
	int		r_count;
	int		pr_count;

	p_count = 0;
	r_count = 0;
	pr_count = 0;
	while (c > 0)
	{
		if (stacks->b->next->val > stacks->sort->ptr[p[1]])
		{
			p_count += btoa_push(stacks);
			c--;
		}
		else if (stacks->b->next->val > stacks->sort->ptr[p[0]])
		{
			p_count += btoa_push(stacks);
			pr_count += btoa_rot(stacks->a, 1);
			c--;
		}
		else
			r_count += btoa_rot(stacks->b, 2);
	}
	replace(stacks, p_count, r_count, pr_count);
}

void	btoa(t_stacks *stacks, int l, int r)
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
	count = over_pivot(node_b, stacks->sort->ptr[p[0]],
			stacks->sort->ptr[l], stacks->sort->ptr[r]);
	if (r - l <= 9 && r >= l)
	{
		btoa_pushall(stacks, l, r);
		return ;
	}
	divide(stacks, p, count);
	btoa(stacks, p[1] + 1, r);
	btoa(stacks, p[0] + 1, p[1]);
	btoa(stacks, l, p[0]);
}

void	case_gt_six(t_node *node_a, t_node *node_b, t_sort *sort, char *record)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
	{
		free_all(node_a, node_b, sort, record);
		exit(EXIT_FAILURE);
	}
	vals_storage(NULL, stacks, NULL, NULL);
	stacks->a = node_a;
	stacks->b = node_b;
	stacks->sort = sort;
	atob(stacks, 0, sort->size - 1, 1);
}
