/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:04:27 by tisoya            #+#    #+#             */
/*   Updated: 2022/01/23 01:27:45 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				val;
	size_t			index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_sort
{
	int		*array;
	size_t	size;
}	t_sort;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	t_sort	*sort;
}	t_stacks;

// arg_check.c
int		is_sorted(t_stack *stack);
int		is_digit_str(int as, char *av[]);
int		atoi_and_errcheck(char *str, t_stack *stack, size_t i);
int		is_unique(t_stack *stack);

// base_act.c
void	swap(t_stack *stack, int ab);
void	push(t_stack *stack1, t_stack *stack2, int ab);
void	r_rot(t_stack *stack, int ab);
void	rot(t_stack *stack, int ab);

// few_args.c
void	case_two(t_stack *stack);
void	case_three(t_stack *stack);
void	case_ngt_six(t_stack *stack1, t_stack *stack2);

// free_and_exit.c
void	free_stack(t_stack *stack, int count);
void	free_all(t_stack *stack1, t_stack *stack2, t_sort *sort, char *record);
void	vals_storage(t_stack *stack, t_stacks *stacks,
			t_sort *sort, char **record);
void	shutdown(void);

// init_node.c
t_stack	*init_stack(int args, char *argv[]);
void	re_index(t_stack *stack);

// many_args_atob.c
void	atob(t_stacks *stacks, size_t l, size_t r, int first);

// many_args_btoa.c
void	btoa(t_stacks *stacks, size_t l, size_t r);

// many_args_btoa2.c
int		btoa_push(t_stacks *stacks);
int		btoa_rot(t_stack *stack, int ab);
void	btoa_pushall(t_stacks *stacks, size_t l, size_t r);

// optimizer.c
void	optimizer(char *record);

// pre_sort.c
t_sort	*pre_sort(t_stack *stack);

// recorder.c
char	**record_array(size_t size);
void	recorder(char **record, int act);
void	player(char *record);

// search_val.c
void	set_min(t_stack *stack, int ab);
void	set_max(t_stack *stack, int ab);

#endif
