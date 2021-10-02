/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 21:22:36 by nluya             #+#    #+#             */
/*   Updated: 2021/10/02 11:38:26 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_stack	*ft_last_node(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp -> next)
		tmp = tmp -> next;
	return (tmp);
}

void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*begin;

	begin = *stack;
	last = ft_last_node(begin);
	last->next = begin;
	*stack = begin->next;
	begin->next = NULL;
}

void	rotate_a(t_stack **stack_a, int flag)
{
	if (*stack_a)
		rotate(stack_a);
	if (flag)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack_b, int flag)
{
	if (*stack_b)
		rotate(stack_b);
	if (flag)
		write(1, "rb\n", 3);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, int flag)
{
	if (*stack_a)
		rotate(stack_a);
	if (*stack_b)
		rotate(stack_b);
	if (flag)
		write(1, "rr\n", 3);
}
