/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:26:34 by iyerin            #+#    #+#             */
/*   Updated: 2018/09/24 19:44:27 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(size_t value, size_t base)
{
	char	*nbr;
	int		i;
	int		neg;
	size_t	tmp;
	char	*bchr;

	tmp = value;
	bchr = "0123456789abcdef";
	i = 1;
	neg = 0;
	while ((tmp /= base) != 0)
		i++;
	nbr = (char*)malloc(sizeof(char) * (i + neg + 1));
	nbr[i + neg] = '\0';
	while (i--)
	{
		nbr[i + neg] = bchr[value % base];
		value = value / base;
	}
	return (nbr);
}
