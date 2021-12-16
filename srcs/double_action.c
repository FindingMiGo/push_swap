/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:59:46 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/16 12:03:25 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_swap(t_node *node1, t_node *node2)
{
	swap(node1, 0);
	swap(node2, 0);
	write(1, "ss\n", 3);
}

void	rrot_rrot(t_node *node1, t_node *node2)
{
	r_rot(node1, 0);
	r_rot(node2, 0);
	write(1, "rrr\n", 4);
}

void	rot_rot(t_node *node1, t_node *node2)
{
	rot(node1, 0);
	rot(node2, 0);
	write(1, "rr\n", 3);
}
