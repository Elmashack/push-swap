/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:47:57 by nluya             #+#    #+#             */
/*   Updated: 2021/10/02 15:36:35 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack, long max, int count)
{
	int	cur_max;

	cur_max = -2147483648;
	while (stack)
	{
		if (stack->digit >= cur_max && stack->digit < max)
		{
			cur_max = stack->digit;
			stack->index = count;
		}
		stack = stack->next;
	}
	return (cur_max);
}

void	set_index(t_stack *stack)
{
	int	max;
	int	count;

	count = ft_count_elem(stack);
	max = find_max(stack, 2147483648, count);
	while (count)
	{
		count--;
		max = find_max(stack, max, count);
	}
}
