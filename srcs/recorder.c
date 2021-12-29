/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:07:46 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/29 18:32:25 by tisoya           ###   ########.fr       */
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
	static char		*rec;
	static size_t	size;
	static size_t	index;

	if (record && act == 0)
	{
		rec = *record;
		size = ft_strlen(*record);
		index = 0;
		return ;
	}
	else if (record == NULL)
		rec[index++] = act;
}

void	optimizer(char *record)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (record[i + 1])
	{
		while (record[i] == 1)
			i++;
		j = i + 1;
		while (record[j] == 1)
			j++;
		if ((record[i] == 4 && record[j] == 5)
			 || (record[i] == 5 && record[j] == 4))
		{
			record[i] = 1;
			record[j] = 1;
			i = -1;
		}
		i++;
	}
}

void	player(char *record)
{
	size_t i;

	i = 0;
	while(record[i])
	{
		while (record[i] == 1)
			i++;
		if (record[i] == 2)
			write(1, "sa\n", 3);
		else if (record[i] == 3)
			write(1, "sb\n", 3);
		else if (record[i] == 4)
			write(1, "pb\n", 3);
		else if (record[i] == 5)
			write(1, "pa\n", 3);
		else if (record[i] == 6)
			write(1, "rra\n", 4);
		else if (record[i] == 7)
			write(1, "rrb\n", 4);
		else if (record[i] == 8)
			write(1, "ra\n", 3);
		else if (record[i] == 9)
			write(1, "rb\n", 3);
		i++;
	}
}
