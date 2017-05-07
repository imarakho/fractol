/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:03:07 by imarakho          #+#    #+#             */
/*   Updated: 2016/12/01 20:52:10 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*wordscpy(char *ar, char const *str, char c, int index)
{
	int		start;
	int		end;

	start = index;
	while (str[start] != c)
		start++;
	end = start;
	start = index;
	ar = malloc(sizeof(char) * (end - start + 1));
	index = 0;
	while (start < end)
	{
		ar[index] = str[start];
		start++;
		index++;
	}
	ar[index] = '\0';
	return (ar);
}

static int		wordsnum(char const *str, char c)
{
	int		i;
	int		countwords;

	i = 0;
	countwords = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c && str[i + 1] == c) ||
			(str[i] != c && str[i + 1] == '\0'))
			countwords++;
		i++;
	}
	return (countwords);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (wordsnum(s, c) + 1));
	if (!arr)
		return (NULL);
	while (j < wordsnum(s, c))
	{
		while (s[i] == c)
			i++;
		arr[j] = wordscpy(arr[j], s, c, i);
		while (s[i] != c)
			i++;
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
