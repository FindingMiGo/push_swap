/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 02:17:12 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/25 02:37:57 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec(t_stack *stack_a, t_stack *stack_b, char *command)
{
	if (!ft_strncmp(command, "sa\n", 3))
		swap(stack_a, 0);
	else if (!ft_strncmp(command, "sb\n", 3))
		swap(stack_b, 0);
	else if (!ft_strncmp(command, "ss\n", 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(command, "ra\n", 3))
		rot(stack_a, 0);
	else if (!ft_strncmp(command, "rb\n", 3))
		rot(stack_b, 0);
	else if (!ft_strncmp(command, "rr\n", 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(command, "rra\n", 3))
		r_rot(stack_a, 0);
	else if (!ft_strncmp(command, "rrb\n", 3))
		r_rot(stack_b, 0);
	else if (!ft_strncmp(command, "rrr\n", 3))
		rrr(stack_a, stack_b);
	else if (!ft_strncmp(command, "pa\n", 3))
		push(stack_b, stack_a, 0);
	else if (!ft_strncmp(command, "pb\n", 3))
		push(stack_a, stack_b, 0);
	else
		return (-1);
	return (0);
}

void	print_result(t_stack *stack_a, t_stack *stack_b, int err_flag)
{
	if (err_flag == 1)
		write(1, "Error\n", 6);
	else if (is_sorted(stack_a) && stack_b->val == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	next_command(t_stack *stack_a, t_stack *stack_b)
{
	char	*command;
	int		err_flag;

	err_flag = 0;
	while (1)
	{
		command = get_next_line(0);
		if (command == NULL)
			break ;
		if (exec(stack_a, stack_b, command) == -1)
			err_flag = 1;
		free(command);
	}
	print_result(stack_a, stack_b, err_flag);
}

int	main(int args, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

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
	if (!is_unique(stack_a))
		error_exit();
	next_command(stack_a, stack_b);
	vals_storage(NULL, NULL, NULL, NULL);
	return (0);
}
