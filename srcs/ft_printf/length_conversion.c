/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:26:06 by iyerin            #+#    #+#             */
/*   Updated: 2018/09/24 13:03:52 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_l_s_conv(char **str, t_flags *specs, size_t base, size_t uni_var)
{
	ssize_t	signed_var;
	char	*tmp;

	if (specs->length == 'H')
		signed_var = (signed char)uni_var;
	else if (specs->length == 'h')
		signed_var = (short int)uni_var;
	else if (specs->length == 'l')
		signed_var = (long int)uni_var;
	else if (specs->length == 'L')
		signed_var = (long long int)uni_var;
	else if (specs->length == 'j')
		signed_var = (intmax_t)uni_var;
	else if (specs->length == 'z')
		signed_var = (ssize_t)uni_var;
	else
		signed_var = (int)uni_var;
	if (signed_var < 0)
	{
		tmp = ft_itoa_base((signed_var * -1), base);
		*str = ft_strjoin("-", tmp);
		ft_strdel(&tmp);
	}
	else
		*str = ft_itoa_base(signed_var, base);
}

void	ft_l_u_conv(char **str, t_flags *specs, size_t base, size_t uni_var)
{
	size_t	unsigned_var;

	if (specs->length == 'H')
		unsigned_var = (unsigned char)uni_var;
	else if (specs->length == 'h')
		unsigned_var = (unsigned short int)uni_var;
	else if (specs->length == 'l')
		unsigned_var = (unsigned long int)uni_var;
	else if (specs->length == 'L')
		unsigned_var = (unsigned long long int)uni_var;
	else if (specs->length == 'j')
		unsigned_var = (uintmax_t)uni_var;
	else if (specs->length == 'z')
		unsigned_var = (size_t)uni_var;
	else
		unsigned_var = (unsigned int)uni_var;
	*str = ft_itoa_base(unsigned_var, base);
}
