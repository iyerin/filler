/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 00:30:00 by iyerin            #+#    #+#             */
/*   Updated: 2017/09/26 00:30:01 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	char *temp;

	temp = dest;
	if (*src != 0)
	{
		while (*temp)
			temp++;
		while (*src)
		{
			*temp = *src;
			temp++;
			src++;
		}
		*temp = '\0';
	}
	return (dest);
}
