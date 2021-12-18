/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:14:42 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/19 01:56:00 by tisoya           ###   ########.fr       */
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

int is_digit_str(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '-' && str[1] != '\0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (str[i])
			i++;
	}
	return (1);
}

int	ft_atoi_llong(const char *str)
{
	int			sign;
	long long	ans;
	size_t		i;

	i = 0;
	ans = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		ans = ans * 10 + (str[i++] - '0');
	return (ans * sign);
}
