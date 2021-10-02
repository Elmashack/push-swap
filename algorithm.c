/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:23:32 by nluya             #+#    #+#             */
/*   Updated: 2021/10/02 15:26:42 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_by_greater(t_markup *greater, t_stack *head, t_stack *stack)
{
	t_stack	*tmp;
	int		i;
	int		len;

	i = 0;
	len = ft_count_elem(head) + 1;
	tmp = stack;
	greater->head = tmp->index;
	greater->next_num = tmp->index;
	while (len)
	{
		if (tmp->index > greater->next_num)
		{
			greater->next_num = tmp->index;
			i++;
		}
		if (tmp->next == NULL)
			tmp = head;
		else
			tmp = tmp->next;
		len--;
		tmp->keep_it = 0;
	}
	greater->max_sort = i;
}

void	mark_num(t_stack *stack, t_markup *by_ind)
{
	t_stack	*tmp;
	int		len;
	t_stack	*head;

	len = ft_count_elem(stack) + 1;
	head = stack;
	tmp = stack;
	while (by_ind->max_index != tmp->index)
		tmp = tmp->next;
	by_ind->next_num = tmp->index;
	tmp->keep_it = 1;
	while (len--)
	{
		if (tmp->index > by_ind->next_num)
		{
			by_ind->next_num = tmp->index;
			tmp->keep_it = 1;
		}
		if (tmp->next == NULL)
			tmp = head;
		else
			tmp = tmp->next;
	}
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	int		len;

	tmp_a = *stack_a;
	len = ft_count_elem(tmp_a) + 1;
	while (tmp_a)
	{
		if (tmp_a->keep_it == 0)
			break ;
		tmp_a = tmp_a->next;
	}
	if (tmp_a == NULL)
		return ;
	while (len--)
	{
		if ((*stack_a)->keep_it == 0)
			pb(stack_b, stack_a, 1);
		else
			rotate_a(stack_a, 1);
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	t_markup	by_greater;
	t_stack		*tmp;
	int			tmp_sort;

	tmp_sort = -1;
	tmp = *stack_a;
	while (tmp)
	{
		set_by_greater(&by_greater, *stack_a, tmp);
		if (by_greater.max_sort > tmp_sort)
		{
			tmp_sort = by_greater.max_sort;
			by_greater.max_index = tmp->index;
		}
		tmp = tmp->next;
	}
	mark_num(*stack_a, &by_greater);
	push_to_b(stack_a, stack_b);
	tmp = *stack_a;
}
