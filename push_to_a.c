/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:17:05 by nluya             #+#    #+#             */
/*   Updated: 2021/10/02 15:33:10 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_fewer(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void	rev_zero(t_stack **stack_a, t_stack **stack_b, t_pair_data *data)
{
	if (data->bool_b == 0)
	{
		while (data->step_b > 0)
		{
			rev_b(stack_b, 1);
			data->step_b--;
		}
	}
	if (data->bool_a == 0)
	{
		while (data->step_a > 0)
		{
			rev_a(stack_a, 1);
			data->step_a--;
		}
	}
}

void	ra_rra(t_stack **stack_a, t_stack **stack_b, t_pair_data *data)
{
	if (data->bool_b == 1)
	{
		while (data->step_b > 0)
		{
			rotate_b(stack_b, 1);
			data->step_b--;
		}
	}
	if (data->bool_a == 1)
	{
		while (data->step_a > 0)
		{
			rotate_a(stack_a, 1);
			data->step_a--;
		}
	}
	if (data->bool_a == 0 || data->bool_b == 0)
		rev_zero(stack_a, stack_b, data);
}

void	rot_rev_both(t_stack **stack_a, t_stack **stack_b, t_pair_data *data)
{
	int	fewer_step;

	fewer_step = find_fewer(data->step_b, data->step_a);
	while (fewer_step > 0 && data->bool_b == 1)
	{
		rotate_both(stack_a, stack_b, 1);
		data->step_b--;
		data->step_a--;
		fewer_step--;
	}
	while (fewer_step > 0 && data->bool_b == 0)
	{
		rev_both(stack_a, stack_b, 1);
		data->step_b--;
		data->step_a--;
		fewer_step--;
	}
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b, t_pair_data *data)
{
	t_stack	*tmp_b;
	t_stack	*tmp_a;
	int		len;

	len = ft_count_elem(*stack_b) + 1;
	tmp_b = *stack_b;
	tmp_a = *stack_a;
	while ((tmp_b)->steps_sum != data->min_sum)
		tmp_b = tmp_b->next;
	while (tmp_a->index != tmp_b->index_pair)
		tmp_a = tmp_a->next;
	data->step_a = tmp_a->steps;
	data->step_b = tmp_b->steps;
	data->step_sum = tmp_b->steps_sum;
	data->bool_a = tmp_a->bool;
	data->bool_b = tmp_b->bool;
	if (tmp_b->bool == tmp_a->bool)
	{
		rot_rev_both(stack_a, stack_b, data);
		ra_rra(stack_a, stack_b, data);
	}
	else
		ra_rra(stack_a, stack_b, data);
	pa(stack_a, stack_b, 1);
}
