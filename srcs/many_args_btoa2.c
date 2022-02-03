/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_args_btoa2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:38:38 by user              #+#    #+#             */
/*   Updated: 2022/01/25 00:38:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	btoa_push(t_stacks *stacks)
{
	push(stacks->b, stacks->a, 2);
	return (1);
}

int	btoa_rot(t_stack *stack, int ab)
{
	rot(stack, ab);
	return (1);
}

void	btoa_pushall(t_stacks *stacks, size_t l, size_t r)
{
	int	i;

	i = r - l + 1;
	while (i > 0)
	{
		set_max(stacks->b, 2);
		push(stacks->b, stacks->a, 2);
		i--;
	}
	return ;
}
