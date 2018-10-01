/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:41:03 by iyerin            #+#    #+#             */
/*   Updated: 2017/10/27 14:41:03 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_rev_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char*)dest + n;
	src2 = (unsigned char*)src + n;
	while (n--)
		*(--dest2) = *(--src2);
	return (dest);
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src < dest)
		ft_rev_memcpy(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
