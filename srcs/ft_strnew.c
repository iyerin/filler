/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:59:25 by iyerin            #+#    #+#             */
/*   Updated: 2017/11/05 19:59:26 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	s = (char*)malloc(sizeof(char) * (++size));
	if (!s)
		return (NULL);
	while (size--)
		s[size] = 0;
	return (s);
}
