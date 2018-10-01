/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision_conversion.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 15:22:57 by iyerin            #+#    #+#             */
/*   Updated: 2018/09/24 14:08:41 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_arg_is_numeric(char format)
{
	if (format == 'd' || format == 'D' || format == 'i' || format == 'o'
		|| format == 'O' || format == 'u' || format == 'U'
		|| format == 'x' || format == 'X')
		return (1);
	return (0);
}

void	ft_width_conversion(char **str, t_flags *specs)
{
	ssize_t	j;
	char	*tmp;

	j = specs->width - ft_strlen(*str);
	if ((specs->prec_zero == '1') && (specs->specs != 'c'))
		j = specs->width;
	if (specs->specs != 'S')
	{
		if (j > 0)
			while (j-- > 0)
			{
				tmp = *str;
				*str = ft_strjoin(" ", *str);
				ft_strdel(&tmp);
			}
	}
}

void	ft_prec_numeric(t_flags *specs, char **str, ssize_t i)
{
	char *tmp;

	if (specs->negative)
	{
		tmp = *str;
		*str = ft_strsub(*str, 1, ft_strlen(*str) - 1);
		ft_strdel(&tmp);
	}
	while (i-- > 0)
	{
		tmp = *str;
		*str = ft_strjoin("0", *str);
		ft_strdel(&tmp);
	}
	if (specs->negative)
	{
		tmp = *str;
		*str = ft_strjoin("-", *str);
		ft_strdel(&tmp);
	}
}

void	ft_precision_conv(char **str, t_flags *specs, ssize_t init_str_len)
{
	ssize_t	i;
	char	*tmp;

	i = specs->precision - init_str_len;
	if ((specs->prec_zero == '1') && (specs->zero_octal_hex)
	&& (ft_arg_is_numeric(specs->specs)))
		*str[0] = 2;
	if (((specs->specs == 's') || (specs->specs == 's')) &&
	(i < 0) && ((specs->precision > 0) || (specs->prec_zero)))
	{
		tmp = *str;
		*str = ft_strsub(*str, 0, specs->precision);
		ft_strdel(&tmp);
	}
	if (specs->precision > 0)
	{
		if (specs->negative)
			i++;
		if (ft_arg_is_numeric(specs->specs) && (i > 0))
			ft_prec_numeric(specs, str, i);
	}
}
