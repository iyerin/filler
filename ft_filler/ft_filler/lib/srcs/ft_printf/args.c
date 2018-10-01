/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:32:07 by iyerin            #+#    #+#             */
/*   Updated: 2018/09/24 19:39:11 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arg_s(va_list arg_list, t_flags *specs,
	char **str, wchar_t **unicode_str)
{
	wchar_t *tmp2;

	if ((specs->specs == 's') && (specs->length != 'l'))
	{
		*str = va_arg(arg_list, char*);
		*str = (!(*str)) ? ft_strdup("(null)") : ft_strdup(*str);
	}
	if (((specs->specs == 's') && (specs->length == 'l'))
	|| (specs->specs == 'S'))
	{
		*unicode_str = va_arg(arg_list, wchar_t*);
		if (!*unicode_str)
		{
			specs->unicode = 0;
			specs->specs = 's';
			*str = ft_strdup("(null)");
		}
		else
		{
			tmp2 = ft_memalloc(sizeof(wchar_t) * (ft_uslen(*unicode_str) + 1));
			*unicode_str = ft_memcpy(tmp2, *unicode_str,
			ft_uslen(*unicode_str));
			specs->unicode = '2';
		}
	}
}

void	ft_arg_c(va_list arg_list, t_flags *specs,
	char **str, wchar_t *unicode_char)
{
	*str = ft_strnew(1);
	if ((specs->specs == 'c') && (specs->length != 'l'))
	{
		*str[0] = va_arg(arg_list, int);
		if (!*str[0])
		{
			specs->charzero = '1';
			*str[0] = 2;
		}
	}
	else if ((specs->length == 'l') || specs->specs == 'C')
	{
		specs->specs = 'c';
		*unicode_char = va_arg(arg_list, wint_t);
		specs->unicode = '1';
		*str[0] = 2;
		if (!*unicode_char)
		{
			specs->unicode = 0;
			specs->charzero = '1';
			specs->specs = 'c';
		}
	}
}

void	ft_arg_d(va_list arg_list, t_flags *specs, char **str)
{
	size_t universal_var;

	universal_var = va_arg(arg_list, size_t);
	if (specs->specs == 'D')
	{
		specs->length = 'l';
		specs->specs = 'd';
	}
	ft_l_s_conv(str, specs, 10, universal_var);
}

void	ft_arg_poxu(va_list arg_list, t_flags *specs, char **str)
{
	char	*tmp;
	size_t	universal_var;

	if (specs->specs == 'p')
	{
		*str = ft_itoa_base(va_arg(arg_list, ssize_t), 16);
		tmp = *str;
		*str = ft_strjoin("0x", *str);
		ft_strdel(&tmp);
	}
	if (specs->specs == 'o')
	{
		universal_var = va_arg(arg_list, size_t);
		ft_l_u_conv(str, specs, 8, universal_var);
	}
	if (specs->specs == 'x')
	{
		universal_var = va_arg(arg_list, size_t);
		ft_l_u_conv(str, specs, 16, universal_var);
	}
	if (specs->specs == 'u')
	{
		universal_var = va_arg(arg_list, size_t);
		ft_l_u_conv(str, specs, 10, universal_var);
	}
}

void	ft_arg_xuoanti(va_list arg_list, t_flags *specs, char **str)
{
	char	*tmp;
	size_t	universal_var;

	if (specs->specs == 'X')
	{
		universal_var = va_arg(arg_list, size_t);
		ft_l_u_conv(str, specs, 16, universal_var);
		tmp = *str;
		*str = ft_str_to_upper(*str);
		ft_strdel(&tmp);
	}
	if (specs->specs == 'U')
		*str = ft_itoa_base(va_arg(arg_list, unsigned long int), 10);
	if (specs->specs == 'O')
		*str = ft_itoa_base(va_arg(arg_list, unsigned long int), 8);
	if (specs->antispecs)
	{
		*str = ft_strnew(1);
		*str[0] = specs->antispecs;
		specs->specs = 'c';
	}
}
