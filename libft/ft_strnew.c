/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smykyten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:35:48 by smykyten          #+#    #+#             */
/*   Updated: 2016/11/25 21:38:10 by smykyten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;

	ret = ft_memalloc(size + 1);
	if (ret)
	{
		while (size)
		{
			ret[size - 1] = '\0';
			size--;
		}
		return (ret);
	}
	return (NULL);
}
