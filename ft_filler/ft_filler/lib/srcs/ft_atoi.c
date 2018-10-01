/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:00:03 by iyerin            #+#    #+#             */
/*   Updated: 2017/11/02 20:00:04 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				res;
	int				znak;
	unsigned long	kostil;

	kostil = 0;
	res = 0;
	znak = 1;
	while ((*str == ' ') || ((*str >= 9) && (*str <= 13)))
		str++;
	if (*str == '-')
		znak = -1;
	if ((*str == '-') || (*str == '+'))
		str++;
	while ((*str >= 48) && (*str <= 57))
	{
		res = res * 10 + (*str - 48);
		kostil = kostil * 10 + (*str - 48);
		str++;
		if ((znak == 1) && (kostil > 9223372036854775806))
			return (-1);
		if ((znak == -1) && (kostil > 9223372036854775807))
			return (0);
	}
	return (res * znak);
}
