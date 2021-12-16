/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:07:46 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/16 12:07:55 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *sort, int left, int right)
{
	int	l;
	int	r;
	int	tmp;

	l = left;
	r = right;
	while (l <= r)
	{
		while (l <= right && sort[l] < sort[left])
			l++;
		while (r >= left && sort[r] >= sort[left])
			r--;
		if (l > r)
			break;
		tmp = sort[l];
		sort[l] = sort[r];
		sort[r] = tmp;
		l++;
		r--;
	}
	return (l);
}

void	quick_sort(int *sort, int left, int right)
{
	int part;

	if (left == right)
		return ;
	part = partition(sort, left, right);
	printf("part: %d right: %d\n", part, right);
	quick_sort(sort, left, part - 1);
	printf("part: %d right: %d\n", part, right);
	// quick_sort(sort, part, right);
}

void	pre_sort(t_node *node, int **sort)
{
	int	tmp;

	*sort = (int *)malloc(sizeof(int) * node->val);
	node = node->next;
	while (node->index != 0)
	{
		// printf("%ld:", node->index);
		// printf("%d\n", node->val);
		(*sort)[node->index - 1] = node->val;
		node = node->next;
	}
	quick_sort(*sort, 0, node->val - 1);
}
