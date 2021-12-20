/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:10:53 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/20 16:45:14 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_branch(t_node *node_a, t_node *node_b)
{
	size_t	size;

	size = node_a->val;
	if (is_sorted(node_a))
		return ;
	if (size == 2)
		case_two(node_a);
	else if (size == 3)
		case_three(node_a);
	else if (size <= 6)
		case_ngt_six(node_a, node_b);
}

void	free_node(t_node *node, int count)
{
	t_node	*head;
	t_node	*tmp;

	head = node;
	node = node->next;
	while (node != head && count)
	{
		tmp = node->next;
		free(node);
		node = tmp;
		count--;
	}
	free(head);
}

int	main(int args, char *argv[])
{
	t_node	*node_a;
	t_node	*node_b;
	int		*sort;

	if (args < 2)
		exit(1);
	if (!is_digit_str(args - 1, argv + 1))
	{
		write(2, "Error\n", 6);
		write(2, "not digit str\n", 14);
		return 0;
	}
	node_a = init_node(args, argv);
	node_b = init_node(0, NULL);
	sort = pre_sort(node_a);
	if (!is_unique(node_a))
	{
		write(2, "Error\n", 6);
		write(2, "not unique\n", 11);
		free(sort);
		free_node(node_a, node_a->val);
		free_node(node_b, node_b->val);
		return 0;
	}
	print_intptr(sort, node_a->val);
	// printf("%d\n", node_a->val);
	// printf("1:%d %d\n", node_a->val / 3, sort[node_a->val / 3]);
	// printf("1:%d %d\n", node_a->val * 2 / 3, sort[node_a->val * 2 / 3]);
	free_node(node_a, node_a->val);
	free_node(node_b, node_b->val);
	free(sort);
	return (0);
}
