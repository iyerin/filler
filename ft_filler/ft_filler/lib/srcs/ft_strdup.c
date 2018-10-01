/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:38:40 by iyerin            #+#    #+#             */
/*   Updated: 2017/10/27 16:38:41 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strdup(const char *src)
{
	int			len;
	const char	*tmp;
	char		*otdat;

	tmp = src;
	while (*tmp)
		tmp++;
	len = tmp - src;
	otdat = (char *)malloc(sizeof(char) * (len + 1));
	if (!otdat)
		return (0);
	while (*src)
		*otdat++ = *src++;
	*otdat = '\0';
	return (otdat - len);
}
