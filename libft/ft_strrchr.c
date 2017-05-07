/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:55:48 by imarakho          #+#    #+#             */
/*   Updated: 2016/11/30 16:14:48 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		i;

	i = ft_strlen(s);
	while (*s)
		s++;
	if (c == '\0')
	{
		while (*s + 1 >= 0)
		{
			if (*s == c)
				return ((char *)s);
			s--;
		}
	}
	while (i >= 0)
	{
		if (*s == c)
			return (p = (char *)s);
		s--;
		i--;
	}
	return (NULL);
}
