/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:01:31 by iyerin            #+#    #+#             */
/*   Updated: 2017/10/26 13:01:32 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dest2;
	const unsigned char	*src2;

	src2 = (unsigned char*)src;
	dest2 = (unsigned char*)dest;
	while (n--)
	{
		*dest2 = *src2;
		if (*src2 == (unsigned char)c)
			return (++dest2);
		dest2++;
		src2++;
	}
	return (NULL);
}
