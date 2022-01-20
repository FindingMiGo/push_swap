/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:07:46 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/21 05:35:45 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition(int *sort, size_t left, size_t right)
{
	size_t	l;
	size_t	r;
	int		tmp;

	l = left;
	r = right;
	while (l < r)
	{
		while (sort[l] < sort[left] && l < right)
			l++;
		while (sort[r] >= sort[left] && r > left)
			r--;
		if (l >= r)
			break ;
		tmp = sort[l];
		sort[l] = sort[r];
		sort[r] = tmp;
	}
	if (l == left)
		return (l + 1);
	return (l);
}

static void	quick_sort(int *sort, size_t left, size_t right)
{
	size_t	part;

	if (left >= right)
		return ;
	part = partition(sort, left, right);
	quick_sort(sort, left, part - 1);
	quick_sort(sort, part, right);
}

static int	*sorted_array(t_node *node)
{
	int	*a;

	a = (int *)malloc(sizeof(int) * node->val);
	if (!a)
		shutdown();
	node = node->next;
	while (node->index != 0)
	{
		a[node->index - 1] = node->val;
		node = node->next;
	}
	quick_sort(a, 0, node->val - 1);
	return (a);
}

t_sort	*pre_sort(t_node *node)
{
	t_sort	*sort;

	sort = (t_sort *)malloc(sizeof(t_sort));
	if (!sort || !node)
		shutdown();
	sort->ptr = sorted_array(node);
	sort->size = node->val;
	vals_storage(NULL, NULL, sort, NULL);
	return (sort);
}
