/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smykyten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:49:17 by smykyten          #+#    #+#             */
/*   Updated: 2016/11/25 20:16:11 by smykyten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*pdst;
	char const	*psrc;

	pdst = dst;
	psrc = src;
	if (psrc < pdst)
	{
		pdst += len - 1;
		psrc += len - 1;
		while (len)
		{
			*pdst-- = *psrc--;
			len--;
		}
		return (dst);
	}
	while (len)
	{
		*pdst++ = *psrc++;
		len--;
	}
	return (dst);
}
