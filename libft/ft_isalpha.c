/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:40:58 by imarakho          #+#    #+#             */
/*   Updated: 2016/11/30 16:57:22 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int character)
{
	if ((character >= 65 && character <= 90) ||
		(character >= 97 && character <= 122))
		return (1);
	else
		return (0);
}
