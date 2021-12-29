/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_arg_act.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:10:53 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/23 17:59:13 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_two(t_node *node)
{
	int	a;
	int	b;

	a = node->next->val;
	b = node->next->next->val;
	if (a > b)
	 swap(node, 1);
}

void	case_three(t_node *node)
{
	int	a;
	int	b;
	int	c;

	a = node->next->val;
	b = node->next->next->val;
	c = node->next->next->next->val;
	if (b < a && a < c)
		swap(node, 1);
	else if (a > b && b > c)
	{
		swap(node, 1);
		r_rot(node, 1);
	}
	else if (a > c && c > b)
		rot(node, 1);
	else if (a < c && c < b)
	{
		swap(node, 1);
		rot(node, 1);
	}
	else if (c < a && a < b)
		r_rot(node, 1);
}

void	case_ngt_six(t_node *node1, t_node *node2)
{
	size_t	size;
	size_t	count;

	size = node1->val;
	count = 0;
	while (size - count > 3)
	{
		set_min(node1, 1);
		push(node1, node2, 1);
		count++;
	}
	case_three(node1);
	while (node2->val > 0)
		push(node2, node1, 2);
}
