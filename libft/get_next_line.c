/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 20:43:28 by elman             #+#    #+#             */
/*   Updated: 2021/09/08 18:38:43 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_clean_and_join(char **line, char *buf)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, buf);
	free(tmp);
}

char	*ft_check_remain(char **p_n, char **remain, char **line)
{
	char	*tmp;

	*p_n = NULL;
	if (*remain)
	{
		*p_n = ft_strchr(*remain, '\n');
		if (*p_n)
		{
			**p_n = '\0';
			tmp = *remain;
			*line = ft_strdup(*remain);
			*remain = ft_strdup(++(*p_n));
			free(tmp);
		}
		else
		{
			tmp = *remain;
			*line = ft_strdup(*remain);
			free(tmp);
			*remain = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (*p_n);
}

char	*ft_result(char *p_end, char *line, int flag)
{
	if (flag == 1)
	{
		if (p_end)
		{
			ft_clean_and_join(&line, "\n");
			return (line);
		}
		else
			return (line);
	}
	else
	{
		free(line);
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			num_read;
	char		*p_end;
	static char	*remain;
	char		*line;

	if (fd < 0 || read(fd, buf, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	p_end = ft_check_remain(&p_end, &remain, &line);
	num_read = 1;
	while (!p_end && num_read)
	{
		num_read = read(fd, buf, BUFFER_SIZE);
		if (num_read <= 0 && !ft_strlen(line))
			return (ft_result(p_end, line, 0));
		buf[num_read] = '\0';
		p_end = ft_strchr(buf, '\n');
		if (p_end)
		{
			*p_end = '\0';
			remain = ft_strdup(++p_end);
		}
		ft_clean_and_join(&line, buf);
	}
	return (ft_result(p_end, line, 1));
}
