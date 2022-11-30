#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
    t_format	*list;
    va_list		ap;
    size_t		ret;
	char		*p;

	list = NULL;
	p = NULL;
	if (!ft_preproc(&list, s))
		return (ft_fatal(&list));
	if (list != NULL)
	{
		va_start(ap, s);
		if (!ft_fillproc(list, &ap, s) || !ft_applyfoo(list))
			return (ft_fatal(&list));
		ret = ft_printall(&list, p = ft_strdup(s));
		if (p != NULL)
			free(p);
	}
	else
	{
		ret = ft_strlen(s);
		ft_putstr_fd((char*)s, 1);
	}
	return ((int)ret);
}
