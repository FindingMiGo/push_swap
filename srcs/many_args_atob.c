/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_args_atob.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:15:54 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/23 00:57:04 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	under_pivot(t_stack *stack, int pv, int lv, int rv)
{
	t_stack	*head;
	int		count;

	count = 0;
	head = stack;
	stack = stack->next;
	while (stack != head && stack->val >= lv && stack->val <= rv)
	{
		if (stack->val <= pv)
			count++;
		stack = stack->next;
	}
	return (count);
}

void	replace_atob(t_stacks *stacks, int r_count, int first)
{
	while (r_count > 0 && first == 0)
	{
		r_rot(stacks->b, 2);
		r_count--;
	}
}

int	atob_push_rot(t_stacks *stacks, int r_count)
{
	push(stacks->a, stacks->b, 1);
	rot(stacks->b, 2);
	r_count++;
	return (r_count);
}

void	divide_atob(t_stacks *stacks, size_t p[], int count, int first)
{
	int	r_count;

	r_count = 0;
	while (count > 0)
	{
		if (stacks->a->next->val <= stacks->sort->array[p[0]])
		{
			if (first == 1)
				r_count = atob_push_rot(stacks, r_count);
			else
				push(stacks->a, stacks->b, 1);
			count--;
		}
		else if (stacks->a->next->val <= stacks->sort->array[p[1]])
		{
			if (first == 0)
				r_count = atob_push_rot(stacks, r_count);
			else
				push(stacks->a, stacks->b, 1);
			count--;
		}
		else if (stacks->a->next->val > stacks->sort->array[p[0]])
			rot(stacks->a, 1);
	}
	replace_atob(stacks, r_count, first);
}

void	atob(t_stacks *stacks, size_t l, size_t r, int first)
{
	int		count;
	size_t	p[2];

	if (r - l <= 2)
	{
		if (stacks->a->val == 3)
			case_three(stacks->a);
		else if (stacks->a->val == 2)
			case_two(stacks->a);
		return ;
	}
	p[1] = (l + r) / 2;
	p[0] = (l + p[1]) / 2;
	count = under_pivot(stacks->a, stacks->sort->array[p[1]],
			stacks->sort->array[l], stacks->sort->array[r]);
	divide_atob(stacks, p, count, first);
	atob(stacks, p[1] + 1, r, 0);
	btoa(stacks, p[0] + 1, p[1]);
	btoa(stacks, l, p[0]);
}
