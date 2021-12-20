/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:04:27 by tisoya            #+#    #+#             */
/*   Updated: 2021/12/20 16:37:38 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include<stdio.h>

typedef struct s_node
{
	int				val;
	size_t			index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_sort
{
	int				val;
	t_node			*node;
	struct s_node	*prev;
	struct s_node	*next;
}	t_sort;

// base_action.c
void	swap(t_node *node, int ab);
void	push(t_node *node1, t_node *node2, int ab);
void	r_rot(t_node *node, int ab);
void	rot(t_node *node, int ab);

// double_action.c
void	swap_swap(t_node *node1, t_node *node2);
void	rrot_rrot(t_node *node1, t_node *node2);
void	rot_rot(t_node *node1, t_node *node2);

// composite_action.c
void	set_min(t_node *node, int ab);

// small_arg_action.c
void	case_two(t_node *node);
void	case_three(t_node *node);
void	case_ngt_six(t_node *node1, t_node *node2);

// init_node.c
t_node	*init_node(int args, char *argv[]);
void	re_index(t_node *node);

// pre_sort.c
int	*pre_sort(t_node *node);

// arg_check.c
int		is_sorted(t_node *node);
int		is_digit_str(int as, char *av[]);
int		atoi_and_errcheck(char *str, t_node *node, size_t i);

// debug.c
void	print_node(t_node *node, int count);
void	print_intptr(int *sort, int size);

void	free_node(t_node *node, int count);
int		is_unique(t_node *node);

#endif
