/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:23:40 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/21 16:58:31 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*min_addr(t_stack *stack)
{
	t_stack	*ret;
	int		min;

	stack = stack->next;
	min = stack->val;
	ret = stack;
	while (stack->index != 0)
	{
		if (stack->val < min)
		{
			min = stack->val;
			ret = stack;
		}
		stack = stack->next;
	}
	return (ret);
}

static t_stack	*max_addr(t_stack *stack)
{
	t_stack	*ret;
	int		max;

	stack = stack->next;
	max = stack->val;
	ret = stack;
	while (stack->index != 0)
	{
		if (stack->val > max)
		{
			max = stack->val;
			ret = stack;
		}
		stack = stack->next;
	}
	return (ret);
}

void	set_min(t_stack *stack, int ab)
{
	t_stack	*min;
	size_t	size;

	re_index(stack);
	min = min_addr(stack);
	size = stack->val;
	if (min->index - 1 <= (size - min->index + 1))
	{
		while (stack->next != min)
		{
			if (min->index == 2)
				swap(stack, ab);
			else
				rot(stack, ab);
		}
	}
	else
	{
		while (stack->next != min)
			r_rot(stack, ab);
	}
}

void	set_max(t_stack *stack, int ab)
{
	t_stack	*max;
	size_t	size;

	re_index(stack);
	max = max_addr(stack);
	size = stack->val;
	if (max->index - 1 <= (size - max->index + 1))
	{
		while (stack->next != max)
		{
			if (max->index == 2)
				swap(stack, ab);
			else
				rot(stack, ab);
		}
	}
	else
	{
		while (stack->next != max)
			r_rot(stack, ab);
	}
}
