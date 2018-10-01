/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 19:52:46 by iyerin            #+#    #+#             */
/*   Updated: 2017/09/25 19:52:47 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int dif;

	while ((*s1 || *s2) && (n-- > 0))
	{
		dif = (unsigned char)*s1 - (unsigned char)*s2;
		if (dif != 0)
			return (dif);
		s1++;
		s2++;
	}
	return (0);
}
