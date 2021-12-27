/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_arg_act.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:21:53 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/27 23:28:53 by tisoya           ###   ########.fr       */
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
		if (node->val > p)
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

	p = (left + right) / 2;
	count = get_pushcount_btoa(node_b, sort->ptr[p], sort->ptr[left], sort->ptr[right]);
	// printf("left:%d right:%d\n",left,right);
	if (right == left){
		push(node_b, node_a, 2);
		return ;
	}
	if (right - left == 1)
	{
		if (node_b->next->val < node_b->next->next->val)
			swap(node_b, 2);
		push(node_b, node_a, 2);
		push(node_b, node_a, 2);
		return ;
	}
	// printf("p:%d count:%d\n", p, count);
	// if (p == 2)
	// {
	// 	printf("pval:%d\n", sort->ptr[p]);
	// 	print_node(node_b, 1, 0);
	// 	exit(1);
	// }
	while (count>0)
	{
		if (node_b->next->val > sort->ptr[p])
		{
			push(node_b, node_a, 2);
			pcount++;
			count--;
		}
		else
		{
			// printf("left:%d right:%d\n",left,right);
			// printf("p:%d count:%d\n", p, count);
			// print_node(node_b, 1, 0);
			rot(node_b, 2);
			rcount++;
		}
	}
	while (rcount>0)
	{

		r_rot(node_b, 2);
		rcount--;
	}
	while (pcount>0)
	{
		push(node_a, node_b, 1);
		pcount--;
	}
	btoa(stacks, sort, p+1, right);
	btoa(stacks, sort, left, p);
}

void	part(t_stacks *stacks, t_sort *sort, int left, int right)
{
	int count;
	int	p;
	t_node	*node_a;
	t_node	*node_b;


	node_a = stacks->a;
	node_b = stacks->b;
	if (right <= left)
		return ;
	p = (left + right) / 2;
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
	part(stacks, sort, p + 1, right);
	btoa(stacks, sort, left, p);
}

void	case_gt_six(t_node *node_a, t_node *node_b, t_sort *sort)
{
	t_stacks	*stacks;


	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	stacks->a = node_a;
	stacks->b = node_b;
	part(stacks, sort, 0, sort->size - 1);
	// print_node(node_a, 1, 0);
	// print_node(node_b, 1, 0);
	// print_intptr(sort->ptr, sort->size);
}
