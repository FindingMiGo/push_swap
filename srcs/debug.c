/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:10:53 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/16 12:12:32 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_node *node, int count)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	size = node->val;
	while(j < 2)
	{
		i = 0;
		if (j == 0)
			printf("front:");
		else
			printf("back :");
		while(i < (size + 1) * count)
		{
			if(node->index == 0)
				printf("[nil]");
			else
				printf("%d", node->val);
			if (i < (size + 1) * count - 1)
				printf(", ");
			if (j == 0)
				node = node->next;
			else if (j == 1)
				node = node->prev;
			i++;
		}
		printf("\n");
		j++;
	}
}

void	print_intptr(int *sort, int size)
{
	int i;

	i = 0;
	while(i + 1 < size)
	{
		printf("%d", sort[i++]);
		if (i + 1 < size)
			printf(",");
	}
}
