/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:37:41 by nluya             #+#    #+#             */
/*   Updated: 2021/10/01 21:24:31 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*src_head;

	src_head = *src;
	*src = src_head->next;
	src_head->next = *dst;
	*dst = src_head;
}

void	pa(t_stack **stack_a, t_stack **stack_b, int flag)
{
	if (*stack_b)
		push(stack_b, stack_a);
	if (flag)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_b, t_stack **stack_a, int flag)
{
	if (*stack_a)
		push(stack_a, stack_b);
	if (flag)
		write(1, "pb\n", 3);
}
