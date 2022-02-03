/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_act.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:38:38 by user              #+#    #+#             */
/*   Updated: 2022/01/25 00:38:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rot(stack_a, 0);
	rot(stack_b, 0);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	r_rot(stack_a, 0);
	r_rot(stack_b, 0);
}
