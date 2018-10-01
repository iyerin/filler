/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:42:36 by iyerin            #+#    #+#             */
/*   Updated: 2018/09/27 15:23:47 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list2	*check_fd(t_list2 **begin, int fd)
{
	t_list2 *tmp;
	t_list2 *new;

	tmp = *begin;
	while (tmp)
	{
		if (fd == tmp->fd)
			return (tmp);
		tmp = tmp->next;
	}
	new = ft_memalloc(sizeof(t_list2));
	if (*begin)
		new->next = *begin;
	*begin = new;
	new->fd = fd;
	return (new);
}

int		close_line(t_list2 *buf, char **line)
{
	char			*tmp;
	size_t			j;
	char			*buf2;
	ssize_t			count;

	count = 0;
	j = -1;
	while (buf->str[++j])
		if (buf->str[j] == '\n')
		{
			tmp = *line;
			buf2 = ft_strsub(buf->str, 0, j);
			*line = ft_strjoin(*line, buf2);
			free(tmp);
			free(buf2);
			while (buf->str[++j])
				buf->str[count++] = buf->str[j];
			while (count <= BUFF_SIZE)
				buf->str[count++] = 0;
			return (1);
		}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list2	*begin = NULL;
	t_list2			*buf;
	char			*tmp;
	ssize_t			count;

	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	buf = check_fd(&begin, fd);
	buf->str[BUFF_SIZE] = 0;
	if (!buf->str[0] && read(fd, buf->str, BUFF_SIZE) < 0)
		return (-1);
	*line = ft_strnew(0);
	while (!ft_strchr(buf->str, '\n'))
	{
		tmp = *line;
		*line = ft_strjoin(*line, buf->str);
		free(tmp);
		count = read(fd, buf->str, BUFF_SIZE);
		buf->str[count] = (count >= 0) ? 0 : buf->str[count];
		if (count <= 0)
			return (*line[0]) ? (1) : (0);
	}
	return (close_line(buf, line));
	if (*line != NULL)
		free(*line);
}
