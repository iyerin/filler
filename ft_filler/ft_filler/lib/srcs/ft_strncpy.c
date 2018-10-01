/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:55:36 by iyerin            #+#    #+#             */
/*   Updated: 2017/09/25 14:55:39 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char			*tempsrc;
	char			*tempdest;
	unsigned int	i;

	i = 1;
	tempsrc = (char*)src;
	tempdest = dest;
	while (i <= n)
	{
		if (*tempsrc)
		{
			*tempdest = *tempsrc;
			tempsrc++;
		}
		else
		{
			while (i++ <= n)
				*tempdest++ = 0;
			return (dest);
		}
		i++;
		tempdest++;
	}
	return (dest);
}
