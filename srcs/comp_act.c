/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_act.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:23:40 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/29 21:19:26 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node *min_addr(t_node *node)
{
	t_node *ret;
	int		min;

	node = node->next;
	min = node->val;
	ret = node;
	while (node->index != 0)
	{
		if (node->val < min)
		{
			min = node->val;
			ret = node;
		}
		node = node->next;
	}
	return (ret);
}

void	set_min(t_node *node, int ab)
{
	t_node	*min;
	size_t	size;

	re_index(node);
	min = min_addr(node);
	size = node->val;
	if (min->index - 1 <= (size - min->index + 1))
	{
		while (node->next != min)
		{
			if (min->index == 2)
				swap(node, ab);
			else
				rot(node, ab);
		}
	}
	else
	{
		while (node->next != min)
			r_rot(node, ab);
	}
}
