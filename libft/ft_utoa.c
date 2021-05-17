/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 09:15:02 by jcarlena          #+#    #+#             */
/*   Updated: 2020/12/24 09:42:31 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_getnbrlen(unsigned int nbr)
{
	int	n;

	n = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		(n++);
	}
	return (n);
}

char	*ft_utoa(unsigned int n)
{
	char		*s;
	size_t		len;

	len = ft_getnbrlen(n);
	if (!(s = ft_calloc(len + 2, sizeof(char))))
		return (NULL);
	if (n == 0)
	{
		*s = '0';
		return (s);
	}
	while (n > 0)
	{
		s[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}
