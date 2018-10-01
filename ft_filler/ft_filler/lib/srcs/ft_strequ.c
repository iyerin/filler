/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 22:01:01 by iyerin            #+#    #+#             */
/*   Updated: 2017/11/05 22:01:01 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	size_t i;

	if ((s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL))
		return (0);
	if (s1 == NULL && s2 == NULL)
		return (1);
	if (ft_strlen(s1) >= ft_strlen(s2))
		i = ft_strlen(s1);
	else
		i = ft_strlen(s2);
	if (ft_memcmp(s1, s2, i) != 0)
		return (0);
	return (1);
}
