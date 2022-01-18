/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:07:46 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/18 16:47:14 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	integrate_rarb(char *record, size_t i, size_t j)
{
	record[i] = 1;
	record[j] = 10;
	return (-1);
}

size_t	integrate_rrarrb(char *record, size_t i, size_t j)
{
	record[i] = 11;
	record[j] = 1;
	return (-1);
}

size_t	offset(char *record, size_t i, size_t j)
{
	record[i] = 1;
	record[j] = 1;
	return (-1);
}

static size_t	integrate_and_offset(char *record, size_t i, size_t j)
{
	if ((record[i] == 4 && record[j] == 5)
		|| (record[i] == 5 && record[j] == 4))
		i = offset(record, i, j);
	else if ((record[i] == 8 && record[j] == 9)
		|| (record[i] == 9 && record[j] == 8))
		i = integrate_rarb(record, i, j);
	else if ((record[i] == 7 && record[j] == 9)
		|| (record[i] == 9 && record[j] == 7))
		i = offset(record, i, j);
	else if ((record[i] == 6 && record[j] == 8)
		|| (record[i] == 8 && record[j] == 6))
		i = offset(record, i, j);
	else if (record[i] == 6)
	{
		while (record[j] == 6 || record[j] == 11 || record[j] == 1)
			j++;
		if (record[j] == 7)
			i = integrate_rrarrb(record, i, j);
	}
	return (i);
}

void	optimizer(char *record)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
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
