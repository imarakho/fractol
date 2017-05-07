/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smykyten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:21:22 by smykyten          #+#    #+#             */
/*   Updated: 2016/11/25 16:39:20 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t n)
{
	char		*pdst;
	char const	*psrc;

	pdst = dst;
	psrc = src;
	if (n == 0)
		return (NULL);
	while (n)
	{
		if (*psrc == c)
		{
			*pdst = *psrc;
			return (++pdst);
		}
		*pdst++ = *psrc++;
		n--;
	}
	return (NULL);
}
