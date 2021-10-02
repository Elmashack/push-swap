/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:58:04 by nluya             #+#    #+#             */
/*   Updated: 2021/10/02 12:01:42 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack {
	int				digit;
	int				steps;
	int				index_pair;
	int				bool;
	int				steps_sum;
	struct s_stack	*next;
	int				index;
	int				keep_it;
}				t_stack;

typedef struct s_markup
{
	int			head;
	int			next_num;
	int			max_sort;
	int			max_index;
}		t_markup;

typedef struct s_pair_data
{
	int		bool_a;
	int		bool_b;
	int		step_a;
	int		step_b;
	int		step_sum;
	int		min_sum;
	int		index_a;
	int		index_b;
}				t_pair_data;

// utils
t_stack	*ft_create_lst(int content);
int		is_not_digit( char *arg);
int		ft_count_elem(t_stack *lst);
void	print_stack(t_stack *stack_a, t_stack *stack_b);

//utils for checker
void	error(void);
void	parse_command(t_stack **a, t_stack **b, char *line);
int		gnl(char **line);
int		ft_strcmp(const char *s1, const char *s2);
int		order_check(t_stack **a);

//	command
void	swap_stack(t_stack **stack);
void	swap_a(t_stack **stack_a, int flag);
void	swap_b(t_stack **stack_b, int flag);
void	swap_both(t_stack **stack_a, t_stack **stack_b, int flag);
void	pa(t_stack **stack_a, t_stack **stack_b, int flag);
void	pb(t_stack **stack_b, t_stack **stack_a, int flag);
void	rotate_a(t_stack **stack_a, int flag);
void	rotate_b(t_stack **stack_b, int flag);
void	rotate_both(t_stack **stack_a, t_stack **stack_b, int flag);
void	rev_a(t_stack **stack_a, int flag);
void	rev_b(t_stack **stack_b, int flag);
void	rev_both(t_stack **stack_a, t_stack **stack_b, int flag);

// algorithm

void	set_index(t_stack *stack);
void	sort_less_five(t_stack **stack_a);
void	sort(t_stack **stack_a, t_stack **stack_b);
void	count_step(t_stack **stack_a, t_stack **stack_b);
void	push_to_a(t_stack **stack_a, t_stack **stack_b, t_pair_data *data);

#endif