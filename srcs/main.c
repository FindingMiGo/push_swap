/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:10:53 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/19 01:25:49 by tisoya           ###   ########.fr       */
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

void	arg_check(int args, char *argv[])
{
	size_t	i;

	i = 0;
	while (i < args - 1)
	{
		if (!is_digit_str(argv[i + 1]))
			exit(EXIT_FAILURE);
		i++;
	}
}

int	main(int args, char *argv[])
{
	t_node	*node_a;
	t_node	*node_b;
	int		*sort;

	if (args < 2)
		exit(1);
	arg_check(args, argv);
	node_a = init_node(args, argv);
	node_b = init_node(0, NULL);
	sort = pre_sort(node_a);
	print_intptr(sort, node_a->val);

	free(sort);
	return (0);
}
