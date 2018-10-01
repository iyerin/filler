/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:35:45 by iyerin            #+#    #+#             */
/*   Updated: 2017/09/26 00:35:46 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	char	*tmp;

	tmp = dest;
	while (*tmp)
		tmp++;
	while (*src)
	{
		if (nb <= 0)
			break ;
		*tmp = *src;
		src++;
		tmp++;
		nb--;
	}
	*tmp = 0;
	return (dest);
}
