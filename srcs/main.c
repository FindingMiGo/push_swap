/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:10:53 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/18 03:21:22 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_branch(t_node *node_a, t_node *node_b, t_sort *sort, char *record)
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
	else
		case_gt_six(node_a, node_b, sort, record);
}

void	error_exit(t_node *node1, t_node *node2, t_sort *sort, char *record)
{
	write(2, "Error\n", 6);
	free_all(node1, node2, sort, record);
	exit(EXIT_FAILURE);
}

int	main(int args, char *argv[])
{
	t_node	*node_a;
	t_node	*node_b;
	t_sort	*sort;
	char	*record;

	if (args < 2)
		exit(1);
	if (!is_digit_str(args - 1, argv + 1))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	node_a = init_node(args, argv);
	node_b = init_node(0, NULL);
	sort = pre_sort(node_a);
	record = record_array(node_a->val * 12);
	recorder(&record, 0);
	if (!is_unique(node_a))
		error_exit(node_a, node_b, sort, record);
	size_branch(node_a, node_b, sort, record);
	player(record);
	free_all(node_a, node_b, sort, record);
	return (0);
}
