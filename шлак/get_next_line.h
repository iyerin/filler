/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:43:40 by iyerin            #+#    #+#             */
/*   Updated: 2018/09/27 13:28:28 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft.h"
# include <fcntl.h>
# define BUFF_SIZE 1

typedef struct		s_list2
{
	int				fd;
	char			str[BUFF_SIZE + 1];
	struct s_list2	*next;
}					t_list2;

int					get_next_line(const int fd, char **line);

#endif
