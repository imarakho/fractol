/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:14:02 by imarakho          #+#    #+#             */
/*   Updated: 2016/11/28 19:01:32 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *restrict dst,
			const char *restrict src, size_t size)
{
	size_t	i;
	size_t	i2;
	size_t	ln;

	if (ft_strlen(dst) < size)
		ln = ft_strlen(dst);
	else if (ft_strlen(dst) > size)
		ln = size;
	else
		ln = size;
	i = 0;
	i2 = 0;
	while (dst[i])
		i++;
	while (i < size - 1 && src[i2])
	{
		dst[i] = src[i2];
		i++;
		i2++;
	}
	dst[i] = '\0';
	return (ln + ft_strlen(src));
}
