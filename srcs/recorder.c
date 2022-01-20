/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:07:46 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/21 05:37:42 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**record_array(size_t size)
{
	char		*record;
	char		**ret;

	record = (char *)malloc(sizeof(char) * size + 1);
	ret = (char **)malloc(sizeof(char *));
	if (!record || !ret)
		return (NULL);
	ft_memset(record, 1, size);
	record[size] = '\0';
	*ret = record;
	vals_storage(NULL, NULL, NULL, ret);
	recorder(ret, 0);
	return (ret);
}

static char	*sham_realloc(char **reco, size_t size)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (size * 2) + 1);
	if (!tmp)
		shutdown();
	ft_memset(tmp, 1, size * 2);
	tmp[size * 2] = '\0';
	ft_memcpy(tmp, *reco, size);
	free(*reco);
	return (tmp);
}

void	recorder(char **record, int act)
{
	static char		**reco;
	char			*tmp;
	static size_t	size;
	static size_t	index;

	if (record && act == 0)
	{
		reco = record;
		size = ft_strlen(*record);
		index = 0;
	}
	else if (record == NULL)
	{
		if (size == index)
		{
			*reco = sham_realloc(reco, size);
			size = size * 2;
		}
		(*reco)[index++] = act;
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
	vals_storage(NULL, NULL, NULL, NULL);
}
