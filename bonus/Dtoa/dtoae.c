#include "tmphead.h"

char		*ft_bintodec(char *bin, size_t prec)
{
	size_t	len;
	char	*fraction;
	char	*add;
	char	*ret;
	char	*p;

	if (!bin)
		return (ft_strdup("0"));
	len = ft_strlen(bin);
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
