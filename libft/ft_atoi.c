/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:45:42 by nluya             #+#    #+#             */
/*   Updated: 2021/09/20 18:20:30 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	is_max(unsigned long nb, int *err, int neg)
{
	if (nb > 2147483648 && neg < 0)
	{
		*err = 0;
		return (-1);
	}
	if (nb > 2147483647 && neg > 0)
	{
		*err = 0;
		return (0);
	}
	return (1);
}

int	ft_atoi(char *str, int *err)
{
	int				neg;
	unsigned long	nb;

	*err = 1;
	neg = 1;
	nb = 0;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
		neg = neg * -1;
	if (*str == '+' || *str == '-')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		nb = (nb * 10) + (*str - 48);
		str++;
		if ((is_max(nb, err, neg)) == -1)
			return (-1);
		if ((is_max(nb, err, neg)) == 0)
			return (0);
	}
	return (nb * neg);
}
