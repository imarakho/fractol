/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:21:12 by imarakho          #+#    #+#             */
/*   Updated: 2016/11/29 12:52:44 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	if (c == '\0')
	{
		while (*s + 1)
		{
			if (*s == c)
				return ((char *)s);
			s++;
		}
	}
	while (*s)
	{
		if (*s == c)
		{
			p = (char *)s;
			return (p);
		}
		s++;
	}
	return (NULL);
}
