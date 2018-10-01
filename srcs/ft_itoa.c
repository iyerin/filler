/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:50:02 by iyerin            #+#    #+#             */
/*   Updated: 2017/11/08 15:50:03 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_fig_counter(int n)
{
	int i;

	i = (n < 0) ? 2 : 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char			*s;
	int				i;
	unsigned int	j;

	i = ft_fig_counter(n);
	if (!(s = ft_strnew(i)))
		return (NULL);
	j = n;
	if (n == 0)
		s[0] = '0';
	else if (n < 0)
	{
		s[0] = '-';
		j = -n;
	}
	while (j)
	{
		s[--i] = j % 10 + '0';
		j = j / 10;
	}
	return (s);
}
