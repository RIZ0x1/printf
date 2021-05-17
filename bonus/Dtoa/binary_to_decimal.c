#include "tmphead.h"

char		*ft_halfof(char *nbr)
{
	char    *result;
	char    new;
	char    buf;

	result = nbr;
	buf = '0';
	while (*nbr)
	{
		new = ((((buf - '0') * 10) + (*nbr - '0')) / 2) + '0';
		buf = ((*nbr - '0') % 2) + '0';
		*nbr = new;
		(nbr++);
	}
	*nbr = '5';
	return (result);
}
/*
**DIVIDE ADDENDUM BY TWO
*/
char			*ft_decadd(char *a, char *b)
{
	char	*result;
	char	sum;
	char	buf;

	result = a;
	while (*(++b))
		(a++);
	(b--);
	buf = '0';
	while (a != result)
	{
		sum = (*a - '0') + (*b-- - '0') + (buf - '0');
		if (sum >= 10)
		{
			buf = '1';
			sum -= 10;
		}
		else
			buf = '0';
		*a-- = (sum + '0');
	}
	sum = (*a - '0') + (*b - '0') + (buf - '0');
	*a = (sum + '0');
	return (result);
}
/*
**ADD TO FRACTION
*/
char		*ft_bintodec(char *bin, size_t prec)
{
	size_t	len;
	char	*fraction;
	char	*add;
	char	*ret;
	char	*p;

	if (!bin)
		return (ft_strdup("0"));
	len = (prec > ft_strlen(bin)) ? prec : ft_strlen(bin);
	add = ft_calloc(ft_strlen(bin) + 1, sizeof(char));
	add[0] = '5';
	fraction = ft_calloc(len + 1, sizeof(char));
	ret = fraction;
	p = add;
	ft_memset(fraction, '0', len);
	fraction[len] = '\0';
	while (*bin)
	{
		if (*bin++ == '1')
			fraction = ft_decadd(fraction, add);
		add = ft_halfof(add);
	}
	free(p);
	return (ret);
}

/*
**BINARY TO DECIMAL PART OF INTEGER
*/
char			*ft_bintoint(char *bin, int sign)
{
	char		*stop;
	long int	tmp;
	long int	number;

	stop = bin;
	tmp = 1;
	number = 0;
	if (!bin)
		return (ft_ltoa(number));
	while (*bin)
		(bin++);
	(bin--);
	while (bin != stop)
	{
		if (*bin-- == '1')
			number += tmp;
		tmp <<= 1;
	}
	if (*bin == '1')
		number += tmp;
	number = (sign) ? -number : number;
	return (ft_ltoa(number));
}
/*
**BINARY TO INTEGER
*/
