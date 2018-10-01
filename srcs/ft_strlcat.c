/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:08:25 by iyerin            #+#    #+#             */
/*   Updated: 2017/10/26 13:09:10 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t ret;
	size_t k;

	ret = (ft_strlen(dest) + ft_strlen(src));
	if (ft_strlen(dest) >= size)
		return (size + ft_strlen(src));
	k = size - ft_strlen(dest);
	j = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while ((src[j] != 0) && (k - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
		k--;
	}
	dest[i] = '\0';
	return (ret);
}
