/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:23:30 by iyerin            #+#    #+#             */
/*   Updated: 2017/11/07 17:23:31 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_counter(char const *s, char c)
{
	size_t i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while ((*s != c) && (*s))
				s++;
		}
		else
			s++;
	}
	return (i);
}

static size_t	ft_len_counter(char const *s, char c)
{
	size_t j;

	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			j++;
			s++;
		}
		else
			return (j);
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	k;
	size_t	j;
	size_t	w;

	if (!s)
		return (NULL);
	w = ft_word_counter(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (w + 1))))
		return (NULL);
	k = 0;
	while (k < w)
	{
		j = 0;
		while (*s == c)
			s++;
		if (!(arr[k] = ft_strnew(ft_len_counter(s, c))))
			return (NULL);
		while ((*s != c) && (*s))
			arr[k][j++] = *s++;
		arr[k][j] = '\0';
		k++;
	}
	arr[w] = NULL;
	return (arr);
}
