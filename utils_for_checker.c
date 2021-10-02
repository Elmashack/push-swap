/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 11:21:40 by nluya             #+#    #+#             */
/*   Updated: 2021/10/02 12:43:59 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	gnl(char **line)
{
	char	*buf;
	int		i;
	int		res;
	char	ch;

	buf = malloc(sizeof(char) * 1025);
	if (!buf)
		return (-1);
	i = 0;
	ch = '\0';
	*line = buf;
	res = 1;
	while (res > 0 && ch != '\n')
	{
		res = read(0, &ch, 1);
		buf[i++] = ch;
	}
	buf[i] = '\0';
	return (res);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	z;

	z = 0;
	while (s1[z] != '\0' || s2[z] != '\0')
	{
		if (s1[z] != s2[z])
			return ((unsigned char)s1[z] - (unsigned char)s2[z]);
		z++;
	}
	return (0);
}

void	error(void)
{
	write (1, "Error!\n", 7);
	exit (0);
}

void	parse_command(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap_a(a, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		rev_a(a, 0);
	else if (ft_strcmp(line, "ra\n") == 0)
		rotate_a(a, 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(b, a, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap_b(b, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		swap_both(a, b, 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate_b(b, 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rev_b(b, 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		rotate_both(a, b, 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rev_both(a, b, 0);
	else
		error();
}

int	order_check(t_stack **a)
{
	t_stack	*tmp;
	int		num;

	tmp = *a;
	num = tmp->digit;
	while (tmp)
	{
		if (num > tmp->digit)
			break ;
		num = tmp->digit;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (0);
	return (1);
}
