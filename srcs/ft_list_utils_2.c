/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 07:27:50 by jcarlena          #+#    #+#             */
/*   Updated: 2020/12/26 15:28:56 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			ft_delnode(t_format *node)
{
	if (node != NULL)
	{
		if (node->prec != NULL)
			free(node->prec);
		if (node->width != NULL)
			free(node->width);
		if (node->cont != NULL)
			free(node->cont);
		if (node->output != NULL)
			free(node->output);
		if (node->next != NULL)
			node->next = NULL;
		free(node);
	}
}

void			ft_delbegin(t_format **list)
{
	t_format	*new;

	if (*list != NULL)
	{
		new = (*list)->next;
		ft_delnode(*list);
		*list = new;
	}
}

void			ft_dellist(t_format **list)
{
	while (*list != NULL)
		ft_delbegin(list);
}

int				ft_fatal(t_format **list)
{
	ft_dellist(list);
	return (-1);
}