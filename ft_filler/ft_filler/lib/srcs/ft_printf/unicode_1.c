/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:31:56 by iyerin            #+#    #+#             */
/*   Updated: 2018/09/24 19:32:48 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_countchar(int value)
{
	if (value < 128)
		return (1);
	else if (value < 2048)
		return (2);
	else if (value < 65536)
		return (3);
	else if (value <= 1114111)
		return (4);
	else
		return (0);
}

int			ft_countchar_unicode_str(wchar_t *unicode_str)
{
	int i;

	i = 0;
	while (*unicode_str)
	{
		i += ft_countchar(*unicode_str);
		unicode_str++;
	}
	return (i);
}

size_t		ft_uslen(wchar_t *unicode_str)
{
	size_t i;

	i = 0;
	while (*unicode_str)
	{
		i += 4;
		unicode_str++;
	}
	return (i);
}

int			ft_find_replace_unicode(char const *s, wchar_t unicode_char)
{
	int i;

	i = 0;
	if (!s)
		return (i);
	while (*s)
	{
		if ((*s == 2) && (unicode_char) && MB_CUR_MAX > 1)
			i += ft_putchar(unicode_char);
		else if ((*s == 2) && (unicode_char))
			i += write(1, &unicode_char, 1);
		else
			write(1, s, 1);
		s++;
	}
	return (i);
}

wchar_t		*ft_unicode_precision(wchar_t *unicode_str, t_flags *specs)
{
	wchar_t	*new_str;
	int		i;
	int		j;
	int		k;

	k = 0;
	j = specs->precision;
	i = 0;
	new_str = ft_memalloc(sizeof(wchar_t) * (specs->precision + 1));
	while (j > 0)
	{
		k = ft_countchar(*unicode_str);
		if (j >= k)
		{
			new_str[i] = unicode_str[i];
			i++;
		}
		j -= k;
	}
	return (new_str);
}
