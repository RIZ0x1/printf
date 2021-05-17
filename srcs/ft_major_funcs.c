/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_major_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:08:02 by jcarlena          #+#    #+#             */
/*   Updated: 2020/12/26 22:05:06 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_preproc(t_format **list, const char *s)
{
	char				*specs = "cspdiuxX%";
	unsigned long		indx_a;
	unsigned long		i;
	unsigned long		indx_b;
	t_format			*new;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			indx_a = i;
			indx_b = indx_a + ft_getend(s + (i + 1), specs);
			if (indx_a != indx_b)
			{
				new = ft_newformatnode(indx_a, indx_b, *(s + indx_b));
				if (!new)
					return (0);
				ft_addback(list, new);
			}
			i = indx_b;
		}
		(i++);
	}
	return (1);
}

int			ft_fillproc(t_format *node, va_list *ap, const char *s)
{
	char	*str;
	while (node != NULL)
	{
		str = ft_substr(s, node->indxa, (node->indxb - node->indxa) + 1);
		if (!ft_getstars(node, str, ap) || !ft_getnumbers(node, str) ||
						!ft_getflags(node, str) || !ft_getcontent(node, ap))
		{
			va_end(*ap);
			return (0);
		}
		free(str);
		node = node->next;
	}
	va_end(*ap);
	return (1);
}

int		ft_applyfoo(t_format *node)
{
	while (node != NULL)
	{
		if (!(ft_gethandler(node->conv)(node)))
			return (0);
		node = node->next;
	}
	return (1);
}

static void	ft_output(t_format *node, size_t *len)
{
	if (node->conv == 'c')
	{
		write(1, node->output, node->len);
		*len += (node->conv == 'c' ? node->len : 0);
	}
	else
	{
		ft_putstr_fd(node->output, 1);
		*len += ft_strlen(node->output);
	}
}

size_t		ft_printall(t_format **list, char *s)
{
	size_t			len;
	unsigned long	start;

	len = 0;
	start = 0;
	while (*list != NULL)
	{
		s[(*list)->indxa] = '\0';
		ft_putstr_fd((s + start), 1);
		len += ft_strlen(s + start);
		ft_output(*list, &len);
		start = (*list)->indxb + 1;
		ft_delbegin(list);
	}
	if (*(s + start))
	{
		ft_putstr_fd((s + start), 1);
		len += ft_strlen(s + start);
	}
	return (len);
}
