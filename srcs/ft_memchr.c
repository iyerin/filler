/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:32:34 by iyerin            #+#    #+#             */
/*   Updated: 2017/11/05 16:32:35 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s2;

	s2 = (unsigned char*)s;
	while (n--)
	{
		if (*s2 == (unsigned char)c)
			return (s2);
		s2++;
	}
	return (NULL);
}
