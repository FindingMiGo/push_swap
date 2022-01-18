/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:04:27 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/18 03:24:17 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_node
{
	int				val;
	size_t			index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_sort
{
	int		*ptr;
	size_t	size;
}	t_sort;

typedef struct s_stacks
{
	t_node	*a;
	t_node	*b;
	t_sort	*sort;
}	t_stacks;

//
void	free_sort(t_sort *sort);
void	free_node(t_node *node, int count);
void	free_nodes(t_node *node1, t_node *node2);
void	free_all(t_node *node1, t_node *node2, t_sort *sort, char *record);

// base_action.c
void	swap(t_node *node, int ab);
void	push(t_node *node1, t_node *node2, int ab);
void	r_rot(t_node *node, int ab);
void	rot(t_node *node, int ab);

// composite_action.c
void	set_min(t_node *node, int ab);
void	set_max(t_node *node, int ab);

// small_arg_action.c
void	case_two(t_node *node);
void	case_three(t_node *node);
void	case_ngt_six(t_node *node1, t_node *node2);

// init_node.c
t_node	*init_node(int args, char *argv[]);
void	re_index(t_node *node);

// pre_sort.c
t_sort	*pre_sort(t_node *node);

// arg_check.c
int		is_sorted(t_node *node);
int		is_digit_str(int as, char *av[]);
int		atoi_and_errcheck(char *str, t_node *node, size_t i);

// large_arg_act.c
void	case_gt_six(t_node *node_a, t_node *node_b, t_sort *sort, char *record);

void	free_node(t_node *node, int count);
int		is_unique(t_node *node);

// recorder.c
char	*record_array(size_t size);
void	recorder(char **record, int act);
void	player(char *record);
void	optimizer(char *record);

// many_args_atob.c
int		under_pivot(t_node *node, int p, int l, int r);
void	atob(t_stacks *stacks, int l, int r, int fst);

void	btoa(t_stacks *stacks, int l, int r);

int		btoa_push(t_stacks *stacks);
int		btoa_rot(t_node *node, int ab);
void	btoa_pushall(t_stacks *stacks, int l, int r);

#endif
