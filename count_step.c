/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:57:40 by nluya             #+#    #+#             */
/*   Updated: 2021/10/02 15:36:18 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nearest_index(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*tmp_a;
	t_stack		*tmp_b;

	tmp_b = *stack_b;
	while (tmp_b)
	{
		tmp_a = *stack_a;
		tmp_b->index_pair = 2147483647;
		while (tmp_a)
		{
			if (tmp_a->index > tmp_b->index
				&& tmp_a->index < tmp_b->index_pair)
			{
				tmp_b->index_pair = tmp_a->index;
			}
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
}

void	one_stack_steps(t_stack **stack)
{
	int		len;
	int		i;
	t_stack	*tmp;
	int		half;

	tmp = *stack;
	i = 0;
	len = ft_count_elem(*stack) + 1;
	half = len / 2 + 1;
	while (i < half)
	{
		tmp->bool = 1;
		tmp->steps = i;
		tmp = tmp->next;
		i++;
	}
	if (len % 2 == 0)
		i--;
	while (tmp)
	{
		i--;
		tmp->bool = 0;
		tmp->steps = i;
		tmp = tmp->next;
	}	
}

int	eql(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (a->steps > i && b->steps > i)
		i++;
	return (i);
}

void	sum_steps(t_stack **stack_a, t_stack **stack_b, t_pair_data *data)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		len;

	len = (ft_count_elem(*stack_a) + 1);
	data->min_sum = 2147483647;
	tmp_b = *stack_b;
	while (tmp_b)
	{
		tmp_a = *stack_a;
		while (tmp_a->index != tmp_b->index_pair)
		{
			tmp_a = tmp_a->next;
		}
		if (tmp_a->bool == tmp_b->bool)
			tmp_b->steps_sum = tmp_a->steps + tmp_b->steps - eql(tmp_b, tmp_a);
		else
			tmp_b->steps_sum = tmp_a->steps + tmp_b->steps;
		if (tmp_b->steps_sum < data->min_sum)
			data->min_sum = tmp_b->steps_sum;
		tmp_b = tmp_b->next;
	}
}

void	count_step(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*tmp;
	t_pair_data	data;

	while (*stack_b)
	{
		one_stack_steps(stack_a);
		one_stack_steps(stack_b);
		nearest_index(stack_a, stack_b);
		sum_steps(stack_a, stack_b, &data);
		push_to_a(stack_a, stack_b, &data);
	}
	one_stack_steps(stack_a);
	tmp = *stack_a;
	while (tmp->index != 0)
		tmp = tmp->next;
	data.bool_a = tmp->bool;
	if (data.bool_a == 1)
		while ((*stack_a)->index != 0)
			rotate_a(stack_a, 1);
	else
		while ((*stack_a)->index != 0)
			rev_a(stack_a, 1);
}
