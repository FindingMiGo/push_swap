/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:14:42 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/23 00:58:48 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	stack = stack->next;
	while (stack->next->index != 0)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_digit_str(int as, char *av[])
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	while (j < as)
	{
		i = 0;
		str = av[j];
		if (str[0] == '-' && str[1] != '\0')
			i++;
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				return (0);
			if (str[i])
				i++;
		}
		j++;
	}
	return (1);
}

int	is_unique(t_stack *stack)
{
	t_stack	*tmp;

	stack = stack->next;
	while (stack->next->index != 0)
	{
		tmp = stack->next;
		while (tmp->index != 0)
		{
			if (stack->val == tmp->val)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	atoi_and_errcheck(char *str, t_stack *stack, size_t count)
{
	int			sign;
	long long	ans;
	size_t		i;

	i = 0;
	ans = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(str[i]))
	{
		if ((sign == 1 && ans > (INT_MAX - (str[i] - '0')) / 10)
			|| (sign == -1 && (-1 * ans) < (INT_MIN + (str[i] - '0')) / 10))
		{
			write(2, "Error\n", 6);
			free_stack(stack, count);
			exit(EXIT_FAILURE);
		}
		ans = ans * 10 + (str[i++] - '0');
	}
	return ((int)(ans * sign));
}
