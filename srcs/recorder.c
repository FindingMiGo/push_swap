/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:07:46 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/18 16:43:53 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*record_array(size_t size)
{
	char		*record;

	record = (char *)malloc(sizeof(char) * size + 1);
	ft_memset(record, 1, size);
	record[size] = '\0';
	return (record);
}

void	recorder(char **record, int act)
{
	static char		*reco;
	static size_t	size;
	static size_t	index;

	if (record && act == 0)
	{
		reco = *record;
		size = ft_strlen(*record);
		index = 0;
		return ;
	}
	else if (record == NULL)
		reco[index++] = act;
}

void	print_command(char c)
{
	if (c == 2)
		write(1, "sa\n", 3);
	else if (c == 3)
		write(1, "sb\n", 3);
	else if (c == 4)
		write(1, "pb\n", 3);
	else if (c == 5)
		write(1, "pa\n", 3);
	else if (c == 6)
		write(1, "rra\n", 4);
	else if (c == 7)
		write(1, "rrb\n", 4);
	else if (c == 8)
		write(1, "ra\n", 3);
	else if (c == 9)
		write(1, "rb\n", 3);
	else if (c == 10)
		write(1, "rr\n", 3);
	else if (c == 11)
		write(1, "rrr\n", 4);
}

void	player(char *record)
{
	size_t	i;

	i = 0;
	optimizer(record);
	while (record[i])
	{
		while (record[i] == 1)
			i++;
		print_command(record[i]);
		i++;
	}
}
