/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:06:19 by nluya             #+#    #+#             */
/*   Updated: 2021/10/02 15:44:09 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (!*lst)
		(*lst) = new;
	else
	{
		while (1)
		{	
			if (new->digit == tmp->digit)
			{
				write (1, "Error!", 7);
				exit (0);
			}
			if (tmp -> next == NULL)
				break ;
			tmp = tmp -> next;
		}
		tmp -> next = new;
	}
}

void	check_sorting(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = NULL;
	while (gnl(&line))
	{
		parse_command(stack_a, stack_b, line);
		free(line);
	}
	free(line);
	if (!order_check(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	arg_parser(char *argv, t_stack **stack_a)
{
	char	**str;
	int		i;
	int		num;
	int		err;

	i = 0;
	str = ft_split(argv, ' ');
	while (str[i] != NULL)
	{
		num = ft_atoi(str[i], &err);
		if (!err)
			error();
		ft_lst_back(stack_a, ft_create_lst(num));
		free(str[i]);
		i++;
	}
	free(str);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = 1;
	if (argc < 2)
		return (0);
	while (argc > i)
	{
		if (!(is_not_digit(argv[i])))
			error();
		arg_parser(argv[i], &stack_a);
		i++;
	}
	set_index(stack_a);
	check_sorting(&stack_a, &stack_b);
	return (0);
}
