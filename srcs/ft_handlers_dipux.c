/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers_dipux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 13:14:12 by jcarlena          #+#    #+#             */
/*   Updated: 2020/12/26 12:14:42 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				ft_handler_di(t_format *node)
{
	if (node != NULL && node->cont != NULL)
	{
		if (ft_exceptions(&node))
		{
			node->output = ft_strdup("\0");
			return (1);
		}
		else
			node->output = ft_itoa(*((int*)node->cont));
		if (node->prec != NULL)
		{
			node->output = ft_dixuprec(node->output, node);
			if (node->output == NULL)
				return (0);
		}
		if (node->width != NULL)
		{
			node->output = ft_diwidth(node->output, node);
			if (node->output == NULL)
				return (0);
		}
		return (1);
	}
	return (0);
}

char			*ft_dectohex(unsigned long int x, char conv)
{
	unsigned long int		hexdig;
	char					*res;
	char					*p;
	size_t					len;

	len = ft_gethexlen(x);
	if (!(res = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	if (x == 0x0)
		return (res);
	p = (res + len - 1);
	while (len--)
	{
		hexdig = (x % 16);
		if (hexdig >= 10)
			*p-- = (hexdig - 10) + ((conv == 'X') ? 'A' : 'a');
		else
			*p-- = (hexdig + '0');
		x /= 16;
	}
	return (res);
}

int				ft_handler_p(t_format *node)
{
	unsigned long	x;
	char			*p;

	x = *((unsigned long*)node->cont);
	node->output = ft_strjoin("0x", p = ft_dectohex(x, node->conv));
	if (p != NULL)
		free(p);
	p = NULL;
	if (x == 0x0 && !(node->prec))
		node->output = ft_strjoin(p = node->output, "0");
	if (node->width != NULL)
		node->output = ft_setwidth(node->output, node);
	if (node->output == NULL)
		return (0);
	if (p != NULL)
		free(p);
	return (1);
}

int				ft_handler_u(t_format *node)
{
	if (node != NULL && node->cont != NULL)
	{
		node->output = ft_utoa(*((int*)node->cont));
		if (node->prec != NULL)
		{
			node->output = ft_dixuprec(node->output, node);
			if (node->output == NULL)
				return (0);
			}
		if (node->width != NULL)
		{
			node->output = ft_setwidth(node->output, node);
			if (node->output == NULL)
				return (0);
		}
		return (1);
	}
	return (0);
}

int				ft_handler_x(t_format *node)
{
	unsigned int	x;

	x = *((unsigned int*)node->cont);
	if (node != NULL && node->cont != NULL)
	{
		if (x == 0)
			node->output = ft_strdup("0");
		else
			node->output = ft_dectohex(x, node->conv);
		if (node->prec != NULL)
		{
			node->output = ft_dixuprec(node->output, node);
			if (node->output == NULL)
				return (0);
		}
		if (node->width != NULL)
		{
			node->output = ft_setwidth(node->output, node);
			if (node->output == NULL)
				return (0);
		}
		return (1);
	}
	return (0);
}