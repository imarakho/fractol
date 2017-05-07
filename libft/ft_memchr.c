/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smykyten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:55:01 by smykyten          #+#    #+#             */
/*   Updated: 2016/12/03 13:04:40 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char *ps;

	ps = s;
	if (!n)
		return (NULL);
	while (n)
	{
		if (*ps == c)
			return ((char*)ps);
		++ps;
		n--;
	}
	return (NULL);
}
