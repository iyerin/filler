/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:33:38 by iyerin            #+#    #+#             */
/*   Updated: 2018/09/24 19:38:50 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_unicode_str(wchar_t *unicode_str)
{
	int i;

	i = 0;
	if (!unicode_str)
		return (i);
	while (*unicode_str)
	{
		i += ft_putchar(*unicode_str);
		unicode_str++;
	}
	return (i);
}

void	ft_unicode_conversion(wchar_t *unicode_str, t_flags *specs,
	ssize_t *bytes_counter)
{
	size_t	i;
	wchar_t	*new_str;

	new_str = NULL;
	i = ft_countchar_unicode_str(unicode_str);
	if (((specs->precision > 0) || (specs->prec_zero))
	&& (size_t)specs->precision < i)
	{
		new_str = ft_unicode_precision(unicode_str, specs);
		ft_memdel((void**)(&unicode_str));
	}
	else
		new_str = unicode_str;
	if (specs->width > (i = ft_countchar_unicode_str(new_str)))
	{
		if (specs->minus)
			*bytes_counter += ft_print_unicode_str(new_str);
		while (specs->width-- > i)
			*bytes_counter += write(1, " ", 1);
		if (!specs->minus)
			*bytes_counter += ft_print_unicode_str(new_str);
	}
	else
		*bytes_counter += ft_print_unicode_str(new_str);
	ft_memdel((void**)(&new_str));
}

int		ft_find_replace_null_decimal(char const *s)
{
	int i;

	i = 0;
	if (!s)
		return (i);
	while (*s)
	{
		if (*s != 2)
			i += write(1, s, 1);
		s++;
	}
	return (i);
}

int		ft_find_replace_null_char(char const *s)
{
	int i;

	i = 0;
	if (!s)
		return (i);
	while (*s)
	{
		if (*s == 2)
			i += write(1, "\0", 1);
		else
			i += write(1, s, 1);
		s++;
	}
	return (i);
}

char	*ft_str_to_upper(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(ft_strlen(str));
	while (*str)
	{
		tmp[i] = ft_toupper(*str);
		i++;
		str++;
	}
	return (tmp);
}
