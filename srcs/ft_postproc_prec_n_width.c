/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_postproc_prec_n_width.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 13:03:07 by jcarlena          #+#    #+#             */
/*   Updated: 2020/12/27 00:54:08 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char			*ft_sprec(char *str, t_format *node)
{
	int 	i;
	char	*result;

	result = str;
	if ((*(node->prec) == 0 && (node->conv == '%' || node->conv == 'c')) ||
											*(node->prec) < 0)
		return (result);
	else if ((size_t)*(node->prec) < ft_strlen(str))
	{
		result = ft_calloc(*(node->prec) + 1, sizeof(char));
		i = 0;
		while (i < *(node->prec))
		{
			result[i] = str[i];
			(i++);
		}
		free(str);
	}
	return (result);
}

char				*ft_dixuprec(char *str, t_format *node)
{
	char	*result;
	int		len;
	int		nl;

	if (!*(node->prec) && !*((int*)node->cont))
		return (ft_strdup("\0"));
	if (*(node->prec) > (len = ft_strlen(str)) || *((int*)node->cont) < 0)
	{
		nl = (*(node->prec) >= len ? *(node->prec) : len);
		nl = (ft_strchr(str, '-') && (*(node->prec) >= len) ? nl + 1 : nl);
		if (!(result = ft_calloc(nl + 1, sizeof(char))))
			return (NULL);
		ft_memset(result, '0', nl);
		if (ft_strchr(str, '-'))
		{
			*result = '-';
			ft_strlcpy(result + nl - (len - 1), str + 1, len);
		}
		else
			ft_strlcpy(result + (nl - len), str, len + 1);
		return (result);
	}
	else
		return (str);
}

char			*ft_setwidth(char *str, t_format *node)
{
	char	*result;
	char	c;
	int		len;

	result = str;
	if (node->width != NULL && *(node->width) < 0 && (node->flags |= MINUS_FLAG))
		*(node->width) = -*(node->width);
	if (node->prec != NULL && *(node->width) > *(node->prec))
		node->flags = (node->flags & ~ZERO_FLAG);
	if (*(node->width) > (len = (int)ft_strlen(str)))
	{
		c = (ZERO_FLAG & node->flags && !(MINUS_FLAG & node->flags)) ? '0' : ' ';
		result = ft_calloc(*(node->width) + 1, sizeof(char));
		ft_memset(result, c, *(node->width));
		if (MINUS_FLAG & node->flags)
			ft_memcpy(result, str, len);
		else
			ft_strlcpy((result + (*(node->width) - len)), str, len + 1);
		free(str);
	}
	return (result);
}

void			ft_neg_width(char *result, char *str, t_format *node, char c)
{
	if (*((int*)node->cont) < 0 && (c == '0' || (MINUS_FLAG & node->flags)))
	{
		*result = '-';
		ft_strlcpy(result + *((int*)node->width) - (ft_strlen(str) - 1),
					str + 1, ft_strlen(str));
	}
	else
		ft_strlcpy(result + *((int*)node->width) - (ft_strlen(str)), str, ft_strlen(str) + 1);
}

char			*ft_diwidth(char *str, t_format *node)
{
	char	*result;
	char	c;
	int		len;
	size_t	newlen;

	if (node->width != NULL && *(node->width) < 0 && (node->flags |= MINUS_FLAG))
		*(node->width) = -*(node->width);
	if (node->prec != NULL && *(node->width) > *(node->prec))
		node->flags = (node->flags & ~ZERO_FLAG);
	if (!!(result = str) && *(node->width) > (len = (int)ft_strlen(str)))
	{
		c = (ZERO_FLAG & node->flags && !(MINUS_FLAG & node->flags)) ? '0' : ' ';
		newlen = *(node->width);
		result = ft_calloc(newlen + 1, sizeof(char));
		ft_memset(result, c, newlen);
		if (MINUS_FLAG & node->flags)
			ft_memcpy(result, str, len);
		else
			ft_neg_width(result, str, node, c);
		free(str);
	}
	return (result);
}