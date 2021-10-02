/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:02:00 by nluya             #+#    #+#             */
/*   Updated: 2021/10/02 11:40:21 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*penultimate_node(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp -> next->next)
		tmp = tmp -> next;
	return (tmp);
}

void	reverse(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*begin;

	begin = *stack;
	tmp = penultimate_node(*stack);
	tmp->next->next = begin;
	*stack = tmp->next;
	tmp->next = NULL;
}

void	rev_a(t_stack **stack_a, int flag)
{
	if (*stack_a && (*stack_a)->next)
		reverse(stack_a);
	if (flag)
		write(1, "rra\n", 4);
}

void	rev_b(t_stack **stack_b, int flag)
{
	if (*stack_b && (*stack_b)->next)
		reverse(stack_b);
	if (flag)
		write(1, "rrb\n", 4);
}

void	rev_both(t_stack **stack_a, t_stack **stack_b, int flag)
{
	reverse(stack_b);
	reverse(stack_a);
	if (flag)
		write(1, "rrr\n", 4);
}
