/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:54:35 by jcarlena          #+#    #+#             */
/*   Updated: 2020/12/26 15:29:11 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format		*ft_newformatnode(unsigned long a, unsigned long b, char c)
{
	t_format	*new;

	new = malloc(sizeof(t_format));
	new->indxa = a;
	new->indxb = b;
	new->prec = NULL;
	new->width = NULL;
	new->output = NULL;
	new->cont = NULL;
	new->next = NULL;
	new->conv = c;
	new->flags = 0;
	return (new);
}

t_format		*ft_listlast(t_format *list)
{
	if (list != NULL)
	{
		while (list->next != NULL)
			list = list->next;
	}
	return (list);
}

void			ft_addback(t_format **list, t_format *new)
{
	if (list && *list && new)
		ft_listlast(*list)->next = new;
	else
		*list = new;
}

