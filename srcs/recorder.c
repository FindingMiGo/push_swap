/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:07:46 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/16 23:24:09 by tisoya           ###   ########.fr       */
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

void	optimizer(char *record)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (record[i])
		i++;
	i--;
	while (record[i] == 1)
	{
		record[i] = 0;
		i--;
	}
	i = 0;
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
		else if ((record[i] == 8 && record[j] == 9)
			|| (record[i] == 9 && record[j] == 8))
		{
			record[i] = 1;
			record[j] = 10;
			i = -1;
		}
		else if ((record[i] == 7 && record[j] == 9)
			|| (record[i] == 9 && record[j] == 7))
		{
			record[i] = 1;
			record[j] = 1;
			i = -1;
		}
		else if ((record[i] == 6 && record[j] == 8)
			|| (record[i] == 8 && record[j] == 6))
		{
			record[i] = 1;
			record[j] = 1;
			i = -1;
		}
		else if (record[i] == 6)
		{
			while (record[j] == 6 || record[j] == 11 || record[j] == 1)
				j++;
			if (record[j] == 7)
			{
				record[i] = 11;
				record[j] = 1;
				i = -1;
			}
		}
		i++;
	}
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
		else if (record[i] == 10)
			write(1, "rr\n", 3);
		else if (record[i] == 11)
			write(1, "rrr\n", 4);
		i++;
	}
}
