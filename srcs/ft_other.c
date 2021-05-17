/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:57:17 by jcarlena          #+#    #+#             */
/*   Updated: 2020/12/26 12:14:31 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned long	ft_getend(const char *s, const char *set)
{
	unsigned long x;
	unsigned long y;

	x = 0;
	while (s[x])
	{
		y = 0;
		while (set[y])
		{
			if (s[x] == set[y])
				return (x + 1);
			(y++);
		}
		(x++);
	}
	return (x + 1);
}

size_t			ft_getcontsize(char conv)
{
	if (conv == 'd' || conv == 'i')
		return (sizeof(int));
	if (conv == 's')
		return (sizeof(char*));
	if (conv == 'c' || conv == '%')
		return (sizeof(char));
	if (conv == 'p')
		return (sizeof(void*));
	if (conv == 'u' || conv == 'x' || conv == 'X')
		return (sizeof(unsigned int));
	if (conv == 'x' || conv == 'X')
		return (sizeof(unsigned long));
	return (0);
}

size_t			ft_gethexlen(unsigned long int nbr)
{
	int	n;

	n = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		(n++);
	}
	return (n);
}

int				ft_exceptions(t_format **node)
{
	if ((*node)->conv == 'd' || (*node)->conv == 'i')
	{
		if ((*node)->prec && *((int*)(*node)->cont) == 0)
		{
			if ((*node)->width)
				return (!*((*node)->width) && !*((*node)->prec));
			else
				return (!(*node)->width && !*((*node)->prec));
		}
	}
	return (0);
}
