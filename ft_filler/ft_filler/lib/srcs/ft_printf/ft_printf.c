/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:37:25 by iyerin            #+#    #+#             */
/*   Updated: 2018/09/24 19:38:07 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_print(t_flags *specs, char **str, wchar_t unicode_char)
{
	ssize_t init_str_len;

	init_str_len = ft_strlen(*str);
	if (specs->unicode != '2')
	{
		if (*str[0] == '-')
			specs->negative = '1';
		if (*str[0] == '0')
			specs->zero_octal_hex = '1';
		ft_precision_conv(str, specs, init_str_len);
		ft_flag_conversion(str, specs);
		ft_width_conversion(str, specs);
	}
	if (specs->unicode == '1')
		return (ft_find_replace_unicode(*str, unicode_char));
	else if ((specs->prec_zero == '1') && (!specs->charzero))
		return (ft_find_replace_null_decimal(*str));
	else if (specs->charzero == '1')
		return (ft_find_replace_null_char(*str));
	else
		return (ft_putstr(*str));
}

int		ft_free_all(char **str, t_flags *specs)
{
	ft_strdel(str);
	free(specs);
	return (1);
}

int		ft_one_arg(va_list arg_list, t_flags *specs, ssize_t *bytes_counter)
{
	char	*str;
	wchar_t	unicode_char;
	wchar_t	*unicode_str;

	str = NULL;
	unicode_str = NULL;
	if ((specs->specs == 'd') || (specs->specs == 'i') || (specs->specs == 'D'))
		ft_arg_d(arg_list, specs, &str);
	if ((specs->specs == 's') || (specs->specs == 'S'))
		ft_arg_s(arg_list, specs, &str, &unicode_str);
	if ((specs->specs == 'c') || (specs->specs == 'C'))
		ft_arg_c(arg_list, specs, &str, &unicode_char);
	if ((specs->specs == 'p') || (specs->specs == 'o') ||
		(specs->specs == 'u') || (specs->specs == 'x'))
		ft_arg_poxu(arg_list, specs, &str);
	if ((specs->specs == 'X') || (specs->specs == 'U') ||
		(specs->specs == 'O') || (specs->antispecs))
		ft_arg_xuoanti(arg_list, specs, &str);
	if ((!str) && (!unicode_str))
		return (ft_free_all(&str, specs));
	if (specs->unicode == '2')
		ft_unicode_conversion(unicode_str, specs, bytes_counter);
	*bytes_counter += ft_print(specs, &str, unicode_char);
	ft_strdel(&str);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg_list;
	t_flags	*specs;
	int		j;
	ssize_t	bytes_counter;

	bytes_counter = 0;
	va_start(arg_list, format);
	while ((j = ft_parser(format, &specs, &bytes_counter)))
	{
		if (ft_one_arg(arg_list, specs, &bytes_counter))
			return (bytes_counter);
		free(specs);
		format += j;
	}
	va_end(arg_list);
	free(specs);
	return (bytes_counter);
}
