/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:48:45 by jcarlena          #+#    #+#             */
/*   Updated: 2020/12/26 14:18:05 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_handler		ft_gethandler(char conv)
{
	if (conv == 'd' || conv == 'i')
		return (ft_handler_di);
	if (conv == 's')
		return (ft_handler_s);
	if (conv == 'c')
		return (ft_handler_c);
	if (conv == 'p')
		return (ft_handler_p);
	if (conv == 'u')
		return (ft_handler_u);
	if (conv == 'x' || conv == 'X')
		return (ft_handler_x);
	if (conv == '%')
		return (ft_handler_perc);
	return (0);
}