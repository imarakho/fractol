/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smykyten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:14:12 by smykyten          #+#    #+#             */
/*   Updated: 2016/12/01 18:35:09 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int i;
	int result;
	int sign;

	i = 0;
	result = 0;
	sign = 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\f' ||
			s[i] == '\t' || s[i] == '\v' || s[i] == '\r'))
		i++;
	if (s[i] == 43)
		i++;
	else if (s[i] == 45)
	{
		sign *= -1;
		i++;
	}
	while (s[i] != '\0' && (s[i] > 47 && s[i] < 58))
	{
		result = result * 10 + (s[i] - 48);
		i++;
	}
	return (sign * result);
}
