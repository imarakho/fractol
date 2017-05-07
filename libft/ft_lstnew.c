/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:51:34 by imarakho          #+#    #+#             */
/*   Updated: 2016/12/01 18:45:13 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	if (!content)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
		return (tmp);
	}
	if (tmp)
	{
		tmp->content = malloc(content_size);
		tmp->content = ft_memcpy(tmp->content, content, content_size);
		tmp->next = NULL;
		tmp->content_size = content_size;
		return (tmp);
	}
	else
		return (NULL);
}
