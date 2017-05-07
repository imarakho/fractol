/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smykyten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:29:24 by smykyten          #+#    #+#             */
/*   Updated: 2016/11/28 21:35:50 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			lnth(long n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

static void			recursive(char *s, long n, int i)
{
	if (n >= 10)
	{
		recursive(s, n / 10, i - 1);
		recursive(s, n % 10, i);
	}
	if (n < 10)
	{
		s[i - 1] = n + 48;
	}
}

char				*ft_itoa(int n)
{
	char	*res;
	int		i;
	long	z;

	z = n;
	i = lnth(z);
	res = (char*)malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		z *= -1;
	}
	res[i] = '\0';
	recursive(res, z, i);
	return (res);
}
