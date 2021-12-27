/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_arg_act.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:21:53 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/27 16:41:06 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	need_2be_pushed(t_node *node, int p, int left, int right)
{
	t_node	*tmp;

	tmp = node->next;
	while (tmp != node)
	{
		if (node->val < left && node->val > right)
			break;
		if (tmp->val <= p)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	get_pushcount(t_node *node, int p, int left, int right)
{
	t_node	*head;
	int		count;

	count = 0;
	head = node;
	node = node->next;
	while (node != head && node->val >= left && node->val <= right)
	{
		if (node->val <= p)
			count++;
		node = node->next;
	}
	return (count);
}

int	get_pushcount_btoa(t_node *node, int p, int left, int right)
{
	t_node	*head;
	int		count;

	count = 0;
	head = node;
	node = node->next;
	while (node != head && node->val >= left && node->val <= right)
	{
		if (node->val <= p)
			count++;
		node = node->next;
	}
	return (count);
}

void	btoa(t_stacks *stacks, t_sort *sort, int left, int right)
{
	int count;
	int	pcount;
	int	rcount;
	int	p;
	t_node	*node_a;
	t_node	*node_b;

	node_a = stacks->a;
	node_b = stacks->b;
	pcount = 0;
	rcount = 0;

	if (right == left)
		return ;
		// push(node_b, node_a, 2);
	p = (left + right) / 2;
	printf("p:%d\n", p);
	count = get_pushcount_btoa(node_b, sort->ptr[p], sort->ptr[left], sort->ptr[right]);
	printf("%d\n", count);
	while (count > 0)
	{
		if (node_b->next->val <= sort->ptr[p])
		{
			rot(node_b, 1);
			rcount++;
		}
		else if (node_b->next->val > sort->ptr[p])
		{
			push(node_b, node_a, 1);
			pcount++;
			count--;

		}
	}
	while (rcount > 0)
	{
		r_rot(node_b, 1);
		rcount--;
	}
	while (pcount > 0)
	{
		push(node_a, node_b, 1);
		pcount--;
	}
	// btoa(stacks, sort, left, p);
	// btoa(stacks, sort, p+1, right);
}

void	part(t_stacks *stacks, t_sort *sort, int left, int right)
{
	int count;
	int	p;
	t_node	*node_a;
	t_node	*node_b;

	node_a = stacks->a;
	node_b = stacks->b;
	// if (node_a->val == 3)
	// 	case_three(node_a);
	// if (node_a->val == 2)
	// 	case_two(node_a);
	if (right == left)
		return ;
	p = (left + right) / 2;
	// printf("p:%d,val:%d\n", p, sort->ptr[p]);
	count = get_pushcount(node_a, sort->ptr[p], sort->ptr[left], sort->ptr[right]);
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
	// part(stacks, sort, left, p);
	part(stacks, sort, p + 1, right);
	// btoa(stacks, sort, left, p);
	// btoa(stacks, sort, p+1, right);
}

void	case_gt_six(t_node *node_a, t_node *node_b, t_sort *sort)
{
	t_stacks	*stacks;

	print_intptr(sort->ptr, sort->size);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	stacks->a = node_a;
	stacks->b = node_b;
	part(stacks, sort, 0, sort->size - 1);
	print_node(node_a, 1, 0);
	print_node(node_b, 1, 0);
}
