/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:10:53 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/24 02:07:43 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_gt_six(t_stack *stack_a, t_stack *stack_b, t_sort *sort)
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

void	size_branch(t_stack *stack_a, t_stack *stack_b, t_sort *sort)
{
	size_t	size;

	size = stack_a->val;
	if (is_sorted(stack_a))
		return ;
	if (size == 2)
		case_two(stack_a);
	else if (size == 3)
		case_three(stack_a);
	else if (size <= 6)
		case_ngt_six(stack_a, stack_b);
	else
		case_gt_six(stack_a, stack_b, sort);
}

static void	error_exit(void)
{
	write(2, "Error\n", 6);
	shutdown();
}

int	main(int args, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_sort	*sort;
	char	**record;

	if (args < 2)
		return (0);
	if (!is_digit_str(args - 1, argv + 1))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack_a = init_stack(args, argv);
	stack_b = init_stack(0, NULL);
	if (!stack_a || !stack_b)
		shutdown();
	sort = pre_sort(stack_a);
	record = record_array(stack_a->val * 1);
	if (!sort || !record || is_sorted(stack_a))
		shutdown();
	if (!is_unique(stack_a))
		error_exit();
	size_branch(stack_a, stack_b, sort);
	player(*record);
	return (0);
}
