/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:43:10 by nluya             #+#    #+#             */
/*   Updated: 2021/10/02 15:37:04 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_lst(int content)
{
	t_stack	*new_el;

	new_el = (t_stack *)malloc(sizeof (t_stack));
	if (new_el == NULL)
		return (NULL);
	new_el -> digit = content;
	new_el -> next = NULL;
	return (new_el);
}

int	is_not_digit( char *arg)
{
	int		i;
	int		index;
	char	**str;

	i = 0;
	str = ft_split(arg, ' ');
	if (*str == NULL)
		return (0);
	while (str[i])
	{
		index = 0;
		if (str[i][0] == '-' || str[i][0] == '+')
			index++;
		while (str[i][index])
		{
			if (str[i][index] < '0' || str[i][index] > '9')
				return (0);
			index++;
		}
		free(str[i]);
		i++;
	}
	free(str);
	return (1);
}

int	ft_count_elem(t_stack *lst)
{
	t_stack	*tmp;
	int		count;

	count = 0;
	if (!lst)
		return (0);
	tmp = lst;
	while (tmp -> next)
	{
		tmp = tmp -> next;
		count++;
	}	
	return (count);
}
