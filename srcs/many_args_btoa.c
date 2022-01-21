/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_args_btoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:21:53 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/21 16:54:25 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	over_pivot(t_stack *stack, int p, int l, int r)
{
	t_stack	*head;
	int		count;

	count = 0;
	head = stack;
	stack = stack->next;
	while (stack != head && stack->val >= l && stack->val <= r)
	{
		if (stack->val > p)
			count++;
		stack = stack->next;
	}
	return (count);
}

void	replace(t_stacks *stacks, int p_count, int r_count, int pr_count)
{
	t_stack	*a;
	t_stack	*b;

	a = stacks->a;
	b = stacks->b;
	while (pr_count > 0)
	{
		r_rot(a, 1);
		pr_count--;
	}
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

void	divide(t_stacks *stacks, int p[], int c)
{
	int		p_count;
	int		r_count;
	int		pr_count;

	p_count = 0;
	r_count = 0;
	pr_count = 0;
	while (c > 0)
	{
		if (stacks->b->next->val > stacks->sort->array[p[1]])
		{
			p_count += btoa_push(stacks);
			c--;
		}
		else if (stacks->b->next->val > stacks->sort->array[p[0]])
		{
			p_count += btoa_push(stacks);
			pr_count += btoa_rot(stacks->a, 1);
			c--;
		}
		else
			r_count += btoa_rot(stacks->b, 2);
	}
	replace(stacks, p_count, r_count, pr_count);
}

void	btoa(t_stacks *stacks, int l, int r)
{
	int		count;
	int		p[2];
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		r_count;

	stack_a = stacks->a;
	stack_b = stacks->b;
	p[0] = (l + r) / 2;
	p[1] = (p[0] + r) / 2;
	count = over_pivot(stack_b, stacks->sort->array[p[0]],
			stacks->sort->array[l], stacks->sort->array[r]);
	if (r - l <= 9 && r >= l)
	{
		btoa_pushall(stacks, l, r);
		return ;
	}
	divide(stacks, p, count);
	btoa(stacks, p[1] + 1, r);
	btoa(stacks, p[0] + 1, p[1]);
	btoa(stacks, l, p[0]);
}

void	case_gt_six(t_stack *stack_a, t_stack *stack_b, t_sort *sort)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		shutdown();
	vals_storage(NULL, stacks, NULL, NULL);
	stacks->a = stack_a;
	stacks->b = stack_b;
	stacks->sort = sort;
	atob(stacks, 0, sort->size - 1, 1);
}
