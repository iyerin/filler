/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 15:34:15 by iyerin            #+#    #+#             */
/*   Updated: 2018/09/24 14:47:19 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hash(char **str, t_flags *specs)
{
	char *tmp;

	if (!specs->zero_octal_hex)
	{
		if (specs->specs == 'x')
		{
			tmp = *str;
			*str = ft_strjoin("0x", *str);
			ft_strdel(&tmp);
		}
		if (specs->specs == 'X')
		{
			tmp = *str;
			*str = ft_strjoin("0X", *str);
			ft_strdel(&tmp);
		}
	}
	if (((specs->specs == 'o') || (specs->specs == 'O')) && (*str[0] != '0'))
	{
		tmp = *str;
		*str = ft_strjoin("0", *str);
		ft_strdel(&tmp);
	}
}

void	ft_zero_1(char **str, t_flags *specs)
{
	char	*tmp;
	ssize_t	i;

	i = specs->width - ft_strlen(*str);
	if (specs->negative)
	{
		tmp = *str;
		*str = ft_strsub(*str, 1, ft_strlen(*str) - 1);
		ft_strdel(&tmp);
	}
	if ((specs->hash) && ((specs->specs == 'o') || (specs->specs == 'O')
	|| (specs->specs == 'x') || (specs->specs == 'X')))
	{
		tmp = *str;
		*str = ft_strsub(*str, 2, ft_strlen(*str) - 2);
		ft_strdel(&tmp);
	}
	if (specs->space == '1')
		i--;
	while (i-- > 0)
	{
		tmp = *str;
		*str = ft_strjoin("0", *str);
		ft_strdel(&tmp);
	}
}

void	ft_zero_2(char **str, t_flags *specs)
{
	char *tmp;

	if ((specs->hash) && ((specs->specs == 'o') || (specs->specs == 'O')
	|| (specs->specs == 'x') || (specs->specs == 'X')))
	{
		if ((specs->specs == 'o') || (specs->specs == 'O'))
		{
			tmp = *str;
			*str = ft_strjoin("0", *str);
			ft_strdel(&tmp);
		}
		if (specs->specs == 'x')
		{
			tmp = *str;
			*str = ft_strjoin("0x", *str);
			ft_strdel(&tmp);
		}
		if (specs->specs == 'X')
		{
			tmp = *str;
			*str = ft_strjoin("0X", *str);
			ft_strdel(&tmp);
		}
	}
}

void	ft_plus_minus(char **str, t_flags *specs)
{
	char	*tmp;
	ssize_t	i;

	if ((specs->plus == '1') && ((specs->specs == 'd' ||
		specs->specs == 'D' || specs->specs == 'i')))
	{
		if ((*str[0] != '-') && (ft_strlen(*str) == specs->width))
			*str[0] = '+';
		else if (*str[0] != '-')
		{
			tmp = *str;
			*str = ft_strjoin("+", *str);
			ft_strdel(&tmp);
		}
	}
	if (specs->minus == '1')
	{
		i = specs->width - ft_strlen(*str);
		while (i-- > 0)
		{
			tmp = *str;
			*str = ft_strjoin(*str, " ");
			ft_strdel(&tmp);
		}
	}
}

void	ft_flag_conversion(char **str, t_flags *specs)
{
	char *tmp;

	if (specs->hash == '1')
		ft_hash(str, specs);
	if ((specs->zero == '1') && (specs->minus != '1')
		&& (specs->precision == 0))
	{
		ft_zero_1(str, specs);
		ft_zero_2(str, specs);
		if (specs->negative)
		{
			tmp = *str;
			*str = ft_strjoin("-", *str);
			ft_strdel(&tmp);
		}
	}
	ft_plus_minus(str, specs);
	if ((specs->space == '1') && (specs->plus != '1') &&
	((specs->specs == 'd' || specs->specs == 'D' || specs->specs == 'i'))
	&& (!specs->negative))
	{
		tmp = *str;
		*str = ft_strjoin(" ", *str);
		ft_strdel(&tmp);
	}
}
