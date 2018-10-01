/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:30:44 by iyerin            #+#    #+#             */
/*   Updated: 2017/11/07 16:30:45 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int i;

	if (!s)
		return (NULL);
	while ((*s) && ((*s == ' ') || (*s == '\n') || (*s == '\t')))
		s++;
	i = ft_strlen(s);
	if (i != 0)
		while ((&s[i - 1] != s) && ((s[i - 1] == ' ') || (s[i - 1] == '\n')
		|| (s[i - 1] == '\t')))
			i--;
	return (ft_strsub(s, 0, i));
}
