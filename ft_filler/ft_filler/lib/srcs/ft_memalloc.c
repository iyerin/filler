/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:04:19 by iyerin            #+#    #+#             */
/*   Updated: 2017/11/05 19:04:20 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *s;

	s = (unsigned char*)malloc(sizeof(char) * size);
	if (!s)
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
