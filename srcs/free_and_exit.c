/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:10:53 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/21 16:56:07 by tisoya           ###   ########.fr       */
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

void	free_stackab(t_stack *stack1, t_stack *stack2)
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
	static t_stack	*n[2];
	static t_stacks	*st;
	static t_sort	*s;
	static char		**r;

	if (!stack && !stacks && !sort && !record)
	{
		if (r)
			free_all(n[0], n[1], s, *r);
		else
			free_all(n[0], n[1], s, NULL);
		free(st);
		free(r);
		return ;
	}
	if (stack && !n[0])
		n[0] = stack;
	else if (stack && !n[1] && n[0] != stack)
		n[1] = stack;
	if (stacks)
		st = stacks;
	if (sort)
		s = sort;
	if (record)
		r = record;
}

void	shutdown(void)
{
	vals_storage(NULL, NULL, NULL, NULL);
	exit(EXIT_FAILURE);
}
