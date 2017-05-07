/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:12:33 by imarakho          #+#    #+#             */
/*   Updated: 2016/11/26 14:44:11 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int character)
{
	if ((character >= 65 && character <= 90) ||
		(character >= 97 && character <= 122) ||
		(character <= 57 && character >= 48))
		return (1);
	else
		return (0);
}
