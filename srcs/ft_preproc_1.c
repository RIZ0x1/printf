/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preproc_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 09:25:33 by jcarlena          #+#    #+#             */
/*   Updated: 2020/12/26 14:19:56 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				ft_getstars(t_format *node, char *str, va_list *ap)
{
	while (*str)
	{
		if (*str == '*')
		{
			if (*(str - 1) == '.')
				if (!(node->prec = malloc(sizeof(int))))
					return (0);
				else
					*(node->prec) = va_arg(*ap, int);
			else
				if (!(node->width = malloc(sizeof(int))))
					return (0);
				else
					*(node->width) = va_arg(*ap, int);
		}
		(str++);
	}
	return (1);
}

int				*ft_getprec(char *str)
{
	int		*ret;
	char	*p;

	ret = NULL;
	if ((p = ft_strrchr(str, '.')) != NULL)
	{
		ret = malloc(sizeof(int));
		if (ft_isdigit(*(p + 1)))
		{
			*ret = ft_atoi(p + 1);
			return (ret);
		}
		else
		{
			*ret = 0;
			return (ret);
		}
	}
	else
		return (NULL);
}

int				*ft_getwidth(char *str)
{
	int *ret;

	ret = NULL;
	while (*str++)
	{
		if (*str == '.')
			break ;
		if (ft_isdigit(*str) && *str != '0')
		{
			ret = malloc(sizeof(int));
			*ret = ft_atoi(str);
			return (ret);
		}
	}
	return (NULL);
}

int				ft_getflags(t_format *node, char *str)
{
	while (*str++)
	{
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			node->flags |= ZERO_FLAG;
		if (*str == '-')
			node->flags |= MINUS_FLAG;
		if ((ft_isdigit(*str) && *str != '0') || *str == '.' || *str == '*')
			break ;
	}
	return (1);
}
