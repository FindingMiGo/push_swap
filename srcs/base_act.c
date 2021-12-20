/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:59:46 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/16 12:03:31 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *node, int ab)
{
	t_node	*head;
	t_node	*tmp1;
	t_node	*tmp2;

	if (node->val < 2)
		return ;
	head = node;
	tmp1 = head->next;
	tmp2 = head->next->next;
	tmp1->prev->next = tmp2;
	tmp2->next->prev = tmp1;
	tmp1->next = tmp2->next;
	tmp2->prev = tmp1->prev;
	tmp1->prev = tmp2;
	tmp2->next = tmp1;
	if (ab == 1)
		write(1, "sa\n", 3);
	else if (ab == 2)
		write(1, "sb\n", 3);
}

void	push(t_node *node1, t_node *node2, int ab)
{
	t_node	*head1;
	t_node	*head2;
	t_node	*tmp1;
	t_node	*tmp2;

	if (node1->val < 1)
		return ;
	head1 = node1;
	tmp1 = node1->next;
	head1->next = tmp1->next;
	tmp1->next->prev = head1;
	head2 = node2;
	tmp2 = node2->next;
	tmp1->prev = head2;
	tmp1->next = tmp2;
	head2->next = tmp1;
	tmp2->prev = tmp1;
	node1->val -= 1;
	node2->val += 1;
	if (ab == 1)
		write(1, "pb\n", 3);
	else if (ab == 2)
		write(1, "pa\n", 3);
}

void	r_rot(t_node *node, int ab)
{
	t_node	*head;
	t_node	*tmp1;
	t_node	*tmp2;

	if (node->val < 2)
		return ;
	head = node;
	tmp1 = head->next;
	tmp2 = head->prev;
	head->prev = tmp2->prev;
	head->next = tmp2;
	tmp1->prev = tmp2;
	tmp2->prev->next = head;
	tmp2->prev = head;
	tmp2->next = tmp1;
	if (ab == 1)
		write(1, "rra\n", 4);
	else if (ab == 2)
		write(1, "rrb\n", 4);
}

void	rot(t_node *node, int ab)
{
	t_node	*head;
	t_node	*tmp1;
	t_node	*tmp2;

	if (node->val < 2)
		return ;
	head = node;
	tmp1 = head->next;
	tmp2 = head->prev;
	head->next = tmp1->next;
	head->prev = tmp1;
	tmp1->next->prev = head;
	tmp1->prev = tmp2;
	tmp1->next = head;
	tmp2->next = tmp1;
	if (ab == 1)
		write(1, "ra\n", 3);
	else if (ab == 2)
		write(1, "rb\n", 3);
}

