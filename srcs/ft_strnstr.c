/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:25:59 by iyerin            #+#    #+#             */
/*   Updated: 2017/11/02 21:25:59 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char *tmpstr;
	char *tmpstr2;
	char *tmpfind;

	tmpstr = (char*)haystack;
	if (!*needle)
		return ((char *)tmpstr);
	while ((*tmpstr) && (len))
	{
		tmpstr2 = tmpstr;
		tmpfind = (char*)needle;
		while ((*tmpfind) && (len--))
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
