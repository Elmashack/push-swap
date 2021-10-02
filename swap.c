/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:28:01 by nluya             #+#    #+#             */
/*   Updated: 2021/10/02 11:40:12 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	return ;
}

void	swap_a(t_stack **stack_a, int flag)
{
	swap_stack(stack_a);
	if (flag)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack **stack_b, int flag)
{
	swap_stack(stack_b);
	if (flag)
		write(1, "sb\n", 3);
}

void	swap_both(t_stack **stack_a, t_stack **stack_b, int flag)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	if (flag)
		write(1, "ss\n", 3);
}
