/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:14:42 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/16 12:14:50 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *node)
{
	node = node->next;
	while (node->next->index != 0)
	{
		if (node->val > node->next->val)
			return (0);
		node = node->next;
	}
	return (1);
}
