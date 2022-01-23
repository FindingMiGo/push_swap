/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 03:57:38 by tisoya            #+#    #+#             */
/*   Updated: 2021/10/21 03:57:38 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	char	*space;

	space = "\t\n\v\f\r ";
	while (*space)
	{
		if (*space == c)
			return (1);
		space++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	ans;
	size_t		i;

	i = 0;
	ans = 0;
	sign = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (sign == 1 && ans > (LONG_MAX - (str[i] - '0')) / 10)
			return ((int)LONG_MAX);
		else if (sign == -1 && (-1 * ans) < (LONG_MIN + (str[i] - '0')) / 10)
			return ((int)LONG_MIN);
		ans = ans * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(ans * sign));
}
