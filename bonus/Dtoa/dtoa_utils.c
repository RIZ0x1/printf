#include "tmphead.h"

long int		ft_getexponent(double x)
{
	unsigned long int	y;

	ft_memcpy(&y, &x, 8);
	y = (y << 1);
	y = (y >> 53);
	return ((long int)y - 1023);
}
/*
**GETTING EXPONENT
*/
size_t			ft_mantissalen(long int exponent)
{
	size_t len;
	len = 1;

	if (exponent >= 0)
		len = (exponent >= 52) ? (exponent + 1) : 53;
	else
		len = (-exponent + 53);
	return (len);
}
/*
**GETTING THE LENGHT OF THE MANTISSA
*/
char			*ft_getmantissa(double x, long int exponent)
{
	unsigned long int	y;
	size_t				i;
	char				*result;
	char				*ret;

	result = ft_calloc(54, sizeof(char));
	ret = result;
	ft_memcpy(&y, &x, 8);
	y = (y << 12);
	*result++ = (exponent == -1023) ? '0' : '1';
	i = 0;
	while (i++ < 52)
	{
		if (y & 0x8000000000000000)
			*result++ = '1';
		else
			*result++ = '0';
		y <<= 1;
	}
	return (ret);
}
/*
**GETTING MANTISSA ITSELF
*/
void			ft_cutstr(char **tocut, char **a, char **b, long int x)
{
	*a = ft_strdup(*tocut + x + 1);
	*(*tocut + (x + 1)) = '\0';
	*b = ft_strdup(*tocut);
}
/*
**SEPARATION STRING IN TWO
*/
char			*ft_round_number(char **number, size_t prec)
{
	char	*p;
	int		x;

	p = (ft_strchr(number, '.') + prec);
	if ((*p + 1) >= '6')
	{
		x = 1;
		while (x)
		{
			if (*p == '9')
				*p = '0';
			else if (*p == '.')
				(p--);
			else if (p == number)
			{
				number = ft_strjoin();
			}
			else
				*p = *p + x--;
			(p--);
		}
	}
}
