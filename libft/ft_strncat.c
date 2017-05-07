/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:50:02 by imarakho          #+#    #+#             */
/*   Updated: 2016/11/29 13:47:21 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t i;
	size_t size;

	size = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	while (s2[size] != '\0' && n > 0)
	{
		s1[i + size] = s2[size];
		size++;
		n--;
	}
	s1[i + size] = '\0';
	return (s1);
}
