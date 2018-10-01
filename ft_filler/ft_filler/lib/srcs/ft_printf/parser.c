/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 17:19:46 by iyerin            #+#    #+#             */
/*   Updated: 2018/09/24 15:52:19 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_specifier_is_true(char format)
{
	if (format == 's' || format == 'S' || format == 'p' || format == 'd'
	|| format == 'D' || format == 'i' || format == 'o' || format == 'O'
	|| format == 'u' || format == 'U' || format == 'x' || format == 'X'
	|| format == 'c' || format == 'C')
		return (1);
	return (0);
}

void	ft_precision_flags(const char **format, t_flags **specs)
{
	int		i;
	char	tmp[1024];

	i = 0;
	if (**format == '.')
	{
		(*format)++;
		while (**format >= '0' && **format <= '9')
			tmp[i++] = *(*format)++;
		(*specs)->precision = ft_atoi(tmp);
		if ((*specs)->precision == 0)
			(*specs)->prec_zero = '1';
	}
}

int		ft_print_and_flags(const char **format, t_flags **specs,
	ssize_t *bytes_counter)
{
	while (**format != '%' && **format)
	{
		*bytes_counter += write(1, *format, 1);
		(*format)++;
	}
	if (!**format)
		return (0);
	(*format)++;
	while (**format == '#' || **format == '0' || **format == '-'
	|| **format == '+' || **format == ' ')
	{
		if (**format == '#')
			(*specs)->hash = '1';
		if (**format == '0')
			(*specs)->zero = '1';
		if (**format == '-')
			(*specs)->minus = '1';
		if (**format == '+')
			(*specs)->plus = '1';
		if (**format == ' ')
			(*specs)->space = '1';
		(*format)++;
	}
	return (1);
}

void	ft_flag_length(const char **format, t_flags **specs)
{
	if (**format == 'h')
	{
		if (*((*format) + 1) == 'h')
		{
			(*specs)->length = 'H';
			(*format)++;
		}
		else
			(*specs)->length = 'h';
	}
	else if (**format == 'l')
	{
		if (*((*format) + 1) == 'l')
		{
			(*specs)->length = 'L';
			(*format)++;
		}
		else
			(*specs)->length = 'l';
	}
	else
		(*specs)->length = **format;
	(*format)++;
}

int		ft_parser(const char *format, t_flags **specs, ssize_t *bytes_counter)
{
	char		tmp[1024];
	int			i;
	const char	*tmp2;

	tmp2 = format;
	i = 0;
	*specs = malloc(sizeof(t_flags));
	ft_bzero(*specs, sizeof(t_flags));
	if (!ft_print_and_flags(&format, specs, bytes_counter))
		return (0);
	while ((*format >= '0') && (*format <= '9'))
		tmp[i++] = *format++;
	tmp[i] = 0;
	(*specs)->width = ft_atoi(tmp);
	ft_precision_flags(&format, specs);
	if (*format == 'h' || *format == 'l' || *format == 'j' || *format == 'z')
		ft_flag_length(&format, specs);
	if (ft_specifier_is_true(*format))
		(*specs)->specs = *format;
	else
		(*specs)->antispecs = *format;
	format++;
	return (format - tmp2);
}
