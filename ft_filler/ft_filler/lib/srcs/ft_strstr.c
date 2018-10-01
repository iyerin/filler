/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 17:35:49 by iyerin            #+#    #+#             */
/*   Updated: 2017/09/25 17:35:51 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *tmpstr;
	char *tmpstr2;
	char *tmpfind;

	tmpstr = (char*)haystack;
	if (!*needle)
		return ((char *)tmpstr);
	while (*tmpstr)
	{
		tmpstr2 = tmpstr;
		tmpfind = (char*)needle;
		while (*tmpfind)
		{
			if (*tmpfind != *tmpstr2)
				break ;
			tmpstr2++;
			tmpfind++;
		}
		if (*tmpfind == 0)
			return ((char *)tmpstr);
		tmpstr++;
	}
	return (0);
}
