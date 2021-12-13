/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:10:53 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/13 17:02:09 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_node *node, int count)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	size = node->val;
	while(j < 2)
	{
		i = 0;
		if (j == 0)
			printf("front:");
		else
			printf("back :");
		while(i < (size + 1) * count)
		{
			if(node->index == 0)
				printf("[nil]");
			else
				printf("%d", node->val);
			if (i < (size + 1) * count - 1)
				printf(", ");
			if (j == 0)
				node = node->next;
			else if (j == 1)
				node = node->prev;
			i++;
		}
		printf("\n");
		j++;
	}
}

t_node	*init_node(int args, char *argv[])
{
	t_node	*sentinel;
	t_node	*tmp;
	size_t	i;

	sentinel = (t_node *)malloc(sizeof(t_node));
	sentinel->index = 0;
	tmp = sentinel;
	i = 0;
	while (i + 1 < args)
	{
		tmp->next = (t_node *)malloc(sizeof(t_node));
		tmp->next->prev = tmp;
		tmp = tmp->next;
		tmp->index = i + 1;
		tmp->val = ft_atoi(argv[1 + i]);
		i++;
	}
	tmp->next = sentinel;
	sentinel->prev = tmp;
	sentinel->val = i;
	return (sentinel);
}

// t_node	*init_empty_node(void)
// {
// 	t_node	*sentinel;

// 	sentinel = (t_node *)malloc(sizeof(t_node));
// 	sentinel->index = 0;
// 	sentinel->val = 0;
// 	sentinel->prev = sentinel;
// 	sentinel->next = sentinel;
// 	return(sentinel);
// }

void	swap(t_node *node, int ab)
{
	t_node	*head;
	t_node	*tmp1;
	t_node	*tmp2;

	if (node->val < 2)
		return ;
	head = node;
	tmp1 = head->next;
	tmp2 = head->next->next;
	tmp1->prev->next = tmp2;
	tmp2->next->prev = tmp1;
	tmp1->next = tmp2->next;
	tmp2->prev = tmp1->prev;
	tmp1->prev = tmp2;
	tmp2->next = tmp1;
	if (ab == 1)
		write(1, "sa\n", 3);
	else if (ab == 2)
		write(1, "sb\n", 3);
}

void	swap_swap(t_node *node1, t_node *node2)
{
	swap(node1, 0);
	swap(node2, 0);
	write(1, "ss\n", 3);
}

void	rot(t_node *node, int ab)
{
	t_node	*head;
	t_node	*tmp1;
	t_node	*tmp2;

	if (node->val < 2)
		return ;
	head = node;
	tmp1 = head->next;
	tmp2 = head->prev;
	head->next = tmp1->next;
	head->prev = tmp1;
	tmp1->next->prev = head;
	tmp1->prev = tmp2;
	tmp1->next = head;
	tmp2->next = tmp1;
	if (ab == 1)
		write(1, "ra\n", 3);
	else if (ab == 2)
		write(1, "rb\n", 3);
}

void	rot_rot(t_node *node1, t_node *node2)
{
	rot(node1, 0);
	rot(node2, 0);
	write(1, "rr\n", 3);
}

void	r_rot(t_node *node, int ab)
{
	t_node	*head;
	t_node	*tmp1;
	t_node	*tmp2;

	if (node->val < 2)
		return ;
	head = node;
	tmp1 = head->next;
	tmp2 = head->prev;
	head->prev = tmp2->prev;
	head->next = tmp2;
	tmp1->prev = tmp2;
	tmp2->prev->next = head;
	tmp2->prev = head;
	tmp2->next = tmp1;
	if (ab == 1)
		write(1, "rra\n", 4);
	else if (ab == 2)
		write(1, "rrb\n", 4);
}

void	rrot_rrot(t_node *node1, t_node *node2)
{
	r_rot(node1, 0);
	r_rot(node2, 0);
	write(1, "rrr\n", 4);
}

void	push(t_node *node1, t_node *node2, int ab)
{
	t_node	*head1;
	t_node	*head2;
	t_node	*tmp1;
	t_node	*tmp2;

	if (node1->val < 1)
		return ;
	head1 = node1;
	tmp1 = node1->next;
	head1->next = tmp1->next;
	tmp1->next->prev = head1;
	head2 = node2;
	tmp2 = node2->next;
	tmp1->prev = head2;
	tmp1->next = tmp2;
	head2->next = tmp1;
	tmp2->prev = tmp1;
	node1->val -= 1;
	node2->val += 1;
	if (ab == 1)
		write(1, "pb\n", 3);
	else if (ab == 2)
		write(1, "pa\n", 3);
}

void	case_two(t_node *node)
{
	int	a;
	int	b;

	a = node->next->val;
	b = node->next->next->val;
	if (a > b)
	 swap(node, 1);
}

void	case_three(t_node *node)
{
	int	a;
	int	b;
	int	c;

	a = node->next->val;
	b = node->next->next->val;
	c = node->next->next->next->val;
	if (b < a && a < c)
		swap(node, 1);
	else if (a > b && b > c)
	{
		swap(node, 1);
		r_rot(node, 1);
	}
	else if (a > c && c > b)
		rot(node, 1);
	else if (a < c && c < b)
	{
		swap(node, 1);
		rot(node, 1);
	}
	else if (c < a && a < b)
		r_rot(node, 1);
}

t_node *min_addr(t_node *node)
{
	t_node *ret;
	int		min;

	node = node->next;
	min = node->val;
	ret = node;
	while (node->index != 0)
	{
		if (node->val < min)
		{
			min = node->val;
			ret = node;
		}
		node = node->next;
	}
	return (ret);
}

void	re_index(t_node *node)
{
	t_node	*tmp;
	int		i;

	tmp = node->next;
	i = 0;
	while (tmp != node)
	{
		tmp->index = i + 1;
		tmp = tmp->next;
		i++;
	}
	node->val = i;
}

void	set_min(t_node *node, int ab)
{
	t_node	*min;
	size_t	size;
	size_t	i;

	re_index(node);
	min = min_addr(node);
	size = node->val;
	i = 0;
	if (min->index - 1 <= (size - min->index + 1))
	{
		while (node->next != min)
		{
			rot(node, ab);
			i++;
		}
	}
	else
	{
		while (node->next != min)
		{
			r_rot(node, ab);
			i++;
		}
	}
}

void	case_ngt_six(t_node *node1, t_node *node2)
{
	size_t	size;
	size_t	count;

	size = node1->val;
	count = 0;
	while (size - count > 3)
	{
		set_min(node1, 1);
		push(node1, node2, 1);
		count++;
	}
	case_three(node1);
	while (node2->val > 0)
		push(node2, node1, 2);
}

int	main(int args, char *argv[])
{
	t_node	*node_a;
	t_node	*node_b;
	t_node	*tmp;
	size_t	size;

	if (args < 2)
		exit(1);
	node_a = init_node(args, argv);
	node_b = init_node(0, NULL);
	size = node_a->val;
	if (size == 2)
		case_two(node_a);
	else if (size == 3)
		case_three(node_a);
	else if (size <= 6)
		case_ngt_six(node_a, node_b);
	return (0);
}
