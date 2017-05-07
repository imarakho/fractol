/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:40:17 by imarakho          #+#    #+#             */
/*   Updated: 2016/12/11 16:20:08 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_list **alst, t_list *first)
{
	t_list *tmp;

	while (*alst)
	{
		tmp = *alst;
		if (*alst->next == NULL)
			ft_lstadd(**alst, *new);
		*alst = tmp->next;
	}
	*alst = NULL;
}
