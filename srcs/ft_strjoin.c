/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:07:53 by iyerin            #+#    #+#             */
/*   Updated: 2017/11/07 14:07:54 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *s3;
	char *s4;

	if ((!s1) || (!s2))
		return (NULL);
	if (!(s3 = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	s4 = s3;
	while (*s1)
	{
		*s3 = *(char*)s1;
		s3++;
		s1++;
	}
	while (*s2)
	{
		*s3 = *(char*)s2;
		s3++;
		s2++;
	}
	return (s4);
}
