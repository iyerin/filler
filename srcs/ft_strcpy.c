/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 13:02:26 by iyerin            #+#    #+#             */
/*   Updated: 2017/09/25 13:02:28 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, const char *src)
{
	const char	*tempsrc;
	char		*tempdest;

	tempsrc = src;
	tempdest = dest;
	while (*tempsrc != '\0')
	{
		*tempdest = *tempsrc;
		tempdest++;
		tempsrc++;
	}
	*tempdest = '\0';
	return (dest);
}
