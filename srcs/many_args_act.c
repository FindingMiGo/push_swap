/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_args_act.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:21:53 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/29 22:20:42 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	numof_under_pivot(t_node *node, int p, int l, int r)
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

int	numof_over_pivot(t_node *node, int p, int l, int r)
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

void	divide(t_stacks *stacks, t_sort *sort, int p, int c)
{
	t_node	*a;
	t_node	*b;
	int		p_count;
	int		r_count;
	int		s_count;

	a = stacks->a;
	b = stacks->b;
	p_count = 0;
	r_count = 0;
	s_count = 0;
	while (c > 0)
	{
		// if (b->next->val == sort->ptr[sort->cr_max])
		// {
		// 	push(b, a, 2);
		// 	rot(a, 1);
		// 	s_count++;
		// 	c--;
		// }
		if (b->next->val == sort->ptr[sort->cr_max])
		{

			sort->cr_max -= 1;
		}
		if (b->next->val > sort->ptr[p])
		{
			push(b, a, 2);
			p_count++;
			c--;
		}
		else
		{
			rot(b, 2);
			r_count++;
		}

	}
	// while (s_count > 0)
	// {
	// 	r_rot(a, 1);
	// 	s_count--;
	// }
	// print_node(a, 1, 0);
	replace(stacks, p_count, r_count);
}

void	btoa(t_stacks *stacks, t_sort *sort, int l, int r)
{
	int		count;
	int		p;
	t_node	*node_a;
	t_node	*node_b;

	node_a = stacks->a;
	node_b = stacks->b;
	p = (l + r) / 2;
	count = numof_over_pivot(node_b, sort->ptr[p], sort->ptr[l], sort->ptr[r]);
	if (r == l)
	{
		push(node_b, node_a, 2);
		return ;
	}
	else if (r - l == 1)
	{
		if (node_b->next->val < node_b->next->next->val)
			swap(node_b, 2);
		push(node_b, node_a, 2);
		push(node_b, node_a, 2);
		return ;
	}
	divide(stacks, sort, p, count);
	btoa(stacks, sort, p + 1, r);
	btoa(stacks, sort, l, p);
}

void	atob(t_stacks *stacks, t_sort *sort, int l, int r)
{
	int		count;
	int		p;
	t_node	*node_a;
	t_node	*node_b;


	node_a = stacks->a;
	node_b = stacks->b;
	if (r - l <= 2)
		return ;
	p = (l + r) / 2;
	count = numof_under_pivot(node_a, sort->ptr[p], sort->ptr[l], sort->ptr[r]);
	while (count > 0)
	{
		if (node_a->next->val <= sort->ptr[p])
		{
			push(node_a, node_b, 1);
			count--;
		}
		else if (node_a->next->val > sort->ptr[p])
			rot(node_a, 1);
	}
	atob(stacks, sort, p + 1, r);
	// printf("%d\n", sort->ptr[sort->cr_max]);
	if (node_a->val == 3)
	{
		case_three(node_a);
		sort->cr_max -= 3;
	}
	else if (node_a->val == 2)
	{
		case_two(node_a);
		sort->cr_max -= 2;
	}
	// printf("%d\n", sort->ptr[sort->cr_max]);
	btoa(stacks, sort, l, p);
}

void	case_gt_six(t_node *node_a, t_node *node_b, t_sort *sort)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	stacks->a = node_a;
	stacks->b = node_b;
	atob(stacks, sort, 0, sort->size - 1);
	free(stacks);
	// print_node(node_a, 1, 0);
	// print_node(node_b, 1, 0);
}
