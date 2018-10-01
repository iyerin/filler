/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:04:51 by iyerin            #+#    #+#             */
/*   Updated: 2017/10/25 17:04:52 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;

	if ((!dest) && (!src))
		return (NULL);
	dest2 = (unsigned char*)dest;
	while (n--)
		*dest2++ = *(unsigned char*)src++;
	return (dest);
}
