/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_act.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:38:38 by user              #+#    #+#             */
/*   Updated: 2022/01/25 00:38:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, int ab)
{
	t_stack	*head;
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (stack->val < 2)
		return ;
	head = stack;
	tmp1 = head->next;
	tmp2 = head->next->next;
	tmp1->prev->next = tmp2;
	tmp2->next->prev = tmp1;
	tmp1->next = tmp2->next;
	tmp2->prev = tmp1->prev;
	tmp1->prev = tmp2;
	tmp2->next = tmp1;
	if (ab == 1)
		recorder(NULL, 2);
	else if (ab == 2)
		recorder(NULL, 3);
}

void	push(t_stack *stack1, t_stack *stack2, int ab)
{
	t_stack	*head1;
	t_stack	*head2;
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (stack1->val < 1)
		return ;
	head1 = stack1;
	tmp1 = stack1->next;
	head1->next = tmp1->next;
	tmp1->next->prev = head1;
	head2 = stack2;
	tmp2 = stack2->next;
	tmp1->prev = head2;
	tmp1->next = tmp2;
	head2->next = tmp1;
	tmp2->prev = tmp1;
	head1->val--;
	head2->val++;
	if (ab == 1)
		recorder(NULL, 4);
	else if (ab == 2)
		recorder(NULL, 5);
}

void	r_rot(t_stack *stack, int ab)
{
	t_stack	*head;
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (stack->val < 2)
		return ;
	head = stack;
	tmp1 = head->next;
	tmp2 = head->prev;
	head->prev = tmp2->prev;
	head->next = tmp2;
	tmp1->prev = tmp2;
	tmp2->prev->next = head;
	tmp2->prev = head;
	tmp2->next = tmp1;
	if (ab == 1)
		recorder(NULL, 6);
	else if (ab == 2)
		recorder(NULL, 7);
}

void	rot(t_stack *stack, int ab)
{
	t_stack	*head;
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (stack->val < 2)
		return ;
	head = stack;
	tmp1 = head->next;
	tmp2 = head->prev;
	head->next = tmp1->next;
	head->prev = tmp1;
	tmp1->next->prev = head;
	tmp1->prev = tmp2;
	tmp1->next = head;
	tmp2->next = tmp1;
	if (ab == 1)
		recorder(NULL, 8);
	else if (ab == 2)
		recorder(NULL, 9);
}
