/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:16:21 by nluya             #+#    #+#             */
/*   Updated: 2021/10/02 14:28:39 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->digit;
	second = (*stack)->next->digit;
	third = (*stack)->next->next->digit;
	if (first < second && second < third)
		return ;
	else if (first > second && second > third)
	{
		swap_a(stack, 1);
		rev_a(stack, 1);
	}
	else if (first < second && first < third)
	{
		rev_a(stack, 1);
		swap_a(stack, 1);
	}
	else if (first > second && first < third)
		swap_a(stack, 1);
	else if (first < second && first > third)
		rev_a(stack, 1);
	else if (first > second && second < third)
		rotate_a(stack, 1);
}

void	sort_less_five(t_stack **stack_a)
{
	int	len;

	len = ft_count_elem(*stack_a) + 1;
	if (len == 1)
		return ;
	else if (len == 2)
	{
		if ((*stack_a)->digit < (*stack_a)->next->digit)
			return ;
		else
			swap_a(stack_a, 1);
	}
	else
		sort_three(stack_a);
}
