/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:14:42 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/20 16:43:58 by tisoya           ###   ########.fr       */
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

int	is_digit_str(int as, char *av[])
{
	size_t	i;
	size_t	j;
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
			// printf("%c(%d) is str?\n", str[i],str[i]);
			if (!ft_isdigit(str[i]))
				return (0);
			if (str[i])
				i++;
		}
		j++;
	}
	return (1);
}

int	is_unique(t_node *node)
{
	t_node	*tmp;

	node = node->next;
	while (node->next->index != 0)
	{
		tmp = node->next;
		while (tmp->index != 0)
		{
			// printf("%d <==> %d\n", node->val, tmp->val);
			if (node->val == tmp->val)
				return 0;
			tmp = tmp->next;
		}
		node = node->next;
	}
	return (1);
}

int	atoi_and_errcheck(char *str, t_node *node, size_t count)
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
			free_node(node, count);
			exit(EXIT_FAILURE);
		}
		ans = ans * 10 + (str[i++] - '0');
	}
	return ((int)(ans * sign));
}
