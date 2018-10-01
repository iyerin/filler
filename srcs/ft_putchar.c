/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:38:50 by iyerin            #+#    #+#             */
/*   Updated: 2018/09/24 19:49:24 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int value)
{
	unsigned char arr[4];

	if (value < 128)
		return (write(1, &value, 1));
	else if (value < 2048)
	{
		arr[0] = 192 | (value >> 6);
		arr[1] = 128 | (value & 63);
		return (write(1, &arr, 2));
	}
	else if (value < 65536)
	{
		arr[0] = 224 | ((value >> 12) & 15);
		arr[1] = 128 | ((value >> 6) & 63);
		arr[2] = 128 | (value & 63);
		return (write(1, &arr, 3));
	}
	else
	{
		arr[0] = 240 | ((value >> 18) & 7);
		arr[1] = 128 | ((value >> 12) & 63);
		arr[2] = 128 | ((value >> 6) & 63);
		arr[3] = 128 | ((value & 63));
		return (write(1, &arr, 4));
	}
}
