/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:06:16 by imarakho          #+#    #+#             */
/*   Updated: 2016/11/28 22:02:26 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	j;
	size_t	i;
	char	*p;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)&big[i]);
	while (big[i] != '\0')
	{
		if (big[i] == little[j])
			p = (char *)&big[i];
		while (big[i] == little[j])
		{
			if (little[j + 1] == '\0')
				return (p);
			j++;
			i++;
		}
		i -= j;
		j = 0;
		i++;
	}
	return (NULL);
}
