/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:10:53 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/21 16:14:42 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_two(t_stack *stack)
{
	int	a;
	int	b;

	a = stack->next->val;
	b = stack->next->next->val;
	if (a > b)
		swap(stack, 1);
}

void	case_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->next->val;
	b = stack->next->next->val;
	c = stack->next->next->next->val;
	if (b < a && a < c)
		swap(stack, 1);
	else if (a > b && b > c)
	{
		swap(stack, 1);
		r_rot(stack, 1);
	}
	else if (a > c && c > b)
		rot(stack, 1);
	else if (a < c && c < b)
	{
		swap(stack, 1);
		rot(stack, 1);
	}
	else if (c < a && a < b)
		r_rot(stack, 1);
}

void	case_ngt_six(t_stack *stack1, t_stack *stack2)
{
	size_t	size;
	size_t	count;

	size = stack1->val;
	count = 0;
	while (size - count > 3)
	{
		set_min(stack1, 1);
		push(stack1, stack2, 1);
		count++;
	}
	case_three(stack1);
	while (stack2->val > 0)
		push(stack2, stack1, 2);
}
