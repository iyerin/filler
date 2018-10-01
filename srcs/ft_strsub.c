/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 22:19:44 by iyerin            #+#    #+#             */
/*   Updated: 2017/11/05 22:19:44 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *s2;

	if (!s)
		return (NULL);
	if (!(s2 = ft_strnew(len)))
		return (NULL);
	ft_strncpy(s2, s + start, len);
	return (s2);
}
