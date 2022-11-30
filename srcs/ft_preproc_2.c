/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preproc_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 09:28:46 by jcarlena          #+#    #+#             */
/*   Updated: 2020/12/24 13:28:46 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_getnumbers(t_format *node, char *str)
{
	if (node->prec == NULL)
		node->prec = ft_getprec(str);
	if (node->width == NULL)
		node->width = ft_getwidth(str);
	return (1);
}

int				ft_getcontent(t_format *node, va_list *ap)
{
	size_t size;

	if (!(size = ft_getcontsize(node->conv)) || !(node->cont = malloc(size)))
		return (0);
	else if (node->conv == 'd' || node->conv == 'i')
		*((int*)node->cont) = va_arg(*ap, int);
	else if (node->conv == 's')
		*((char**)node->cont) = va_arg(*ap, char*);
	else if (node->conv == 'c')
		*((char*)node->cont) = (char)va_arg(*ap, int);
	else if (node->conv == 'p')
		*((void**)node->cont) = va_arg(*ap, void*);
	else if (node->conv == 'u' || node->conv == 'x' || node->conv == 'X')
		*((unsigned int*)node->cont) = va_arg(*ap, unsigned int);
	else if (node->conv == '%')
		*((char*)node->cont) = '%';
	return (1);
}

