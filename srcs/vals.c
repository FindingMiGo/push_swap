/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vals.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:10:53 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/25 04:43:04 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack, int count)
{
	t_stack	*head;
	t_stack	*tmp;

	head = stack;
	stack = stack->next;
	while (stack != head && count)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
		count--;
	}
	free(head);
}

static void	free_stackab(t_stack *stack1, t_stack *stack2)
{
	if (stack1)
		free_stack(stack1, stack1->val);
	if (stack2)
		free_stack(stack2, stack2->val);
}

void	free_all(t_stack *stack1, t_stack *stack2, t_sort *sort, char *record)
{
	free(record);
	if (sort)
	{
		free(sort->array);
		free(sort);
	}
	free_stackab(stack1, stack2);
}

void	vals_storage(t_stack *stack, t_stacks *stacks,
			t_sort *sort, char **record)
{
	static t_stack	*st[2];
	static t_stacks	*sts;
	static t_sort	*s;
	static char		**r;

	if (!stack && !stacks && !sort && !record)
	{
		if (r)
			free_all(st[0], st[1], s, *r);
		else
			free_all(st[0], st[1], s, NULL);
		free(sts);
		free(r);
		return ;
	}
	if (stack && !st[0])
		st[0] = stack;
	else if (stack && !st[1] && st[0] != stack)
		st[1] = stack;
	if (stacks)
		sts = stacks;
	if (sort)
		s = sort;
	if (record)
		r = record;
}
