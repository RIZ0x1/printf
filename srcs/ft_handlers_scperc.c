/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers_scperc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 13:14:01 by jcarlena          #+#    #+#             */
/*   Updated: 2020/12/26 18:17:01 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				ft_handler_s(t_format *node)
{
	if (node != NULL && node->cont != NULL)
	{
		if (*((char**)node->cont))
			node->output = ft_strdup(*((char**)node->cont));
		else
			node->output = ft_strdup("(null)");
		if (node->prec != NULL)
			node->output = ft_sprec(node->output, node);
		if (node->width != NULL)
			node->output = ft_setwidth(node->output, node);
		return (1);
	}
	return (0);
}

int				ft_handler_c(t_format *node)
{
	if (node != NULL && node->cont != NULL)
	{
		if (node->prec != NULL)
			node->output = ft_sprec(node->output, node);
		if (node->width != NULL)
		{
			node->output = ft_calloc(*(node->width), sizeof(char));
			ft_memset(node->output, ' ', *(node->width));
			if (MINUS_FLAG & node->flags)
				node->output[0] = *((char*)node->cont);
			else
				node->output[*(node->width) - 1] = *((char*)node->cont);
			node->len = *(node->width);
		}
		else
		{
			node->output = ft_calloc(sizeof(char) * 2, sizeof(char));
			node->output[0] = *((char*)node->cont);
			node->len = 1;
		}
		return (1);
	}
	return (0);
}

int				ft_handler_perc(t_format *node)
{
	if (node != NULL)
	{
		node->output = ft_strdup("%");
		if (node->prec != NULL)
				node->output = ft_sprec(node->output, node);
		if (node->width != NULL)
				node->output = ft_setwidth(node->output, node);
		return (1);
	}
	return (0);
}
