/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 22:13:58 by iyerin            #+#    #+#             */
/*   Updated: 2017/11/05 22:13:59 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if ((s1 == NULL && s2 != NULL) || (s1 != NULL && s2 == NULL))
		return (0);
	if (s1 == NULL && s2 == NULL)
		return (1);
	if (ft_memcmp(s1, s2, n) != 0)
		return (0);
	return (1);
}
