/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:10:53 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/08 21:19:41 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_node *node, int count, int flag)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = node->val;
	if (flag == 0 || flag == 2)
	{
		if (flag == 2)
			printf("front:");
		while(i < (size + 1) * count)
		{
			if(node->index == 0)
				printf("[nil]");
			else
				printf("%d", node->val);
			if (i < (size + 1) * count - 1)
				printf(", ");
			node = node->next;
			i++;
		}
		printf("\n");
		i = 0;
	}
	if (flag == 1 || flag == 2)
	{
		if (flag == 2)
			printf("back :");
		while(i < (size + 1) * count)
		{
			if(node->index == 0)
				printf("[nil]");
			else
				printf("%d", node->val);
			if (i < (size + 1) * count - 1)
				printf(", ");
			node = node->prev;
			i++;
		}
		printf("\n");
	}
}

void	print_intptr(int *sort, int size)
{
	size_t i;

	i = 0;
	while(i < size)
	{
		printf("%d", sort[i++]);
		if (i < size)
			printf(", ");
	}
	printf("\n");
}
