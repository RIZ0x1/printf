#include "tmphead.h"

void	ft_setvars(char **cat, char **n_i, char **m_d, long int exponent)
{
	*n_i = NULL;
	*m_d = NULL;
	if (ft_strlen(*cat) == 53)
		ft_cutstr(cat, m_d, n_i, exponent);
	else
		if (exponent < 0)
			*m_d = (*cat + 1);
		else
			*n_i = *cat;
}

char	*ft_doubletobin(double x, size_t prec)
{
	long int	exponent;
	char		*n_i;
	char		*m_d;
	char		*cat;
	size_t		len;

	exponent = ft_getexponent(x);
	len = ft_mantissalen(exponent);
	n_i = ft_calloc((len - 52), sizeof(char));
	ft_memset(n_i, '0', (len - 53));
	m_d = ft_getmantissa(x, exponent);
	cat = (exponent > 0) ? ft_strjoin(m_d, n_i) : ft_strjoin(n_i, m_d);
	free(n_i);
	free(m_d);
	ft_setvars(&cat, &n_i, &m_d, exponent);
	m_d = ft_bintodec(m_d, prec);
	n_i = ft_bintoint(n_i, (x < 0) ? 1 : 0);
	free(cat);
	cat = ft_strjoin(n_i, ".");
	free(n_i);
	n_i = ft_strjoin(cat, m_d);
	free(m_d);
	free(cat);
	return (ft_round_number(&n_i, prec));
}
/*
**n_i - "nulls"_"int"
**m_d - "mantissa"_"double"
**cat - buffer for concatination
*/
