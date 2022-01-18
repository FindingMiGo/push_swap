/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:07:46 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/18 16:40:05 by tisoya           ###   ########.fr       */
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

size_t	offset_papb(char *record, size_t i, size_t j)
{
	if ((record[i] == 4 && record[j] == 5)
		|| (record[i] == 5 && record[j] == 4))
	{
		record[i] = 1;
		record[j] = 1;
		return (0);
	}
	return (i);
}

size_t	integrate_rarb(char *record, size_t i, size_t j)
{
	if ((record[i] == 8 && record[j] == 9)
		|| (record[i] == 9 && record[j] == 8))
	{
		record[i] = 1;
		record[j] = 10;
		return (0);
	}
	return (i);
}

size_t	integrate_rrarrb(char *record, size_t i, size_t j)
{
	if (record[j] == 7)
	{
		record[i] = 11;
		record[j] = 1;
		return (-1);
	}
	return (i);
}

size_t	offset_rrbrb(char *record, size_t i, size_t j)
{
	if ((record[i] == 7 && record[j] == 9)
		|| (record[i] == 9 && record[j] == 7))
	{
		record[i] = 1;
		record[j] = 1;
		return (0);
	}
	return (i);
}

size_t	offset_rrara(char *record, size_t i, size_t j)
{
	if ((record[i] == 6 && record[j] == 8)
		|| (record[i] == 8 && record[j] == 6))
	{
		record[i] = 1;
		record[j] = 1;
		return (0);
	}
	return (i);
}

size_t	integrate_and_offset(char *record, size_t i, size_t j)
{
	if ((record[i] == 4 && record[j] == 5)
		|| (record[i] == 5 && record[j] == 4))
		i = offset_papb(record, i, j);
	else if ((record[i] == 8 && record[j] == 9)
		|| (record[i] == 9 && record[j] == 8))
		i = integrate_rarb(record, i, j);
	else if ((record[i] == 7 && record[j] == 9)
		|| (record[i] == 9 && record[j] == 7))
		i = offset_rrbrb(record, i, j);
	else if ((record[i] == 6 && record[j] == 8)
		|| (record[i] == 8 && record[j] == 6))
		i = offset_rrara(record, i, j);
	else if (record[i] == 6)
	{
		while (record[j] == 6 || record[j] == 11 || record[j] == 1)
			j++;
		integrate_rrarrb(record, i, j);
	}
	return (i);
}

void	optimizer(char *record)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	// while (record[i])
	// 	i++;
	// i--;
	// while (record[i] == 1)
	// {
	// 	record[i] = 0;
	// 	i--;
	// }
	// i = 0;
	while (record[i] != 0 && record[i] != 1)
		i++;
	if (record[i] == 1)
		record[i] = 0;
	i = 0;
	while (record[i + 1])
	{
		while (record[i] == 1)
			i++;
		j = i + 1;
		while (record[j] == 1)
			j++;
		i = integrate_and_offset(record, i, j);
		i++;
	}
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
