/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:10:53 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/21 05:40:25 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_branch(t_node *node_a, t_node *node_b, t_sort *sort)
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
		case_gt_six(node_a, node_b, sort);
}

static void	error_exit(void)
{
	write(2, "Error\n", 6);
	shutdown();
}

int	main(int args, char *argv[])
{
	t_node	*node_a;
	t_node	*node_b;
	t_sort	*sort;
	char	**record;

	if (args < 2)
		return (0);
	if (!is_digit_str(args - 1, argv + 1))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	node_a = init_node(args, argv);
	node_b = init_node(0, NULL);
	if (!node_a || !node_b)
		shutdown();
	sort = pre_sort(node_a);
	record = record_array(node_a->val * 1);
	if (!sort || !record || is_sorted(node_a))
		shutdown();
	if (!is_unique(node_a))
		error_exit();
	size_branch(node_a, node_b, sort);
	player(*record);
	return (0);
}
