#include "tmphead.h"

void			*ft_calloc(size_t count, size_t size)
{
	void		*new;
	char		*p;
	size_t		fullsize;

	fullsize = (count * size);
	new = malloc(fullsize);
	if (new)
	{
		p = new;
		while (fullsize)
		{
			*p = '\0';
			(p++);
			(fullsize--);
		}
	}
	return (new);
}

size_t			ft_strlen(const char *s)
{
	int n;

	n = 0;
	while (s[n])
		(n++);
	return (n);
}

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char*)dst;
	s = (char*)src;
	while (n && (dst || src))
	{
		*d = *s;
		(d++);
		(s++);
		(n--);
	}
	return (dst);
}

void			*ft_memset(void *destination, int c, size_t len)
{
        char *tmp_mem;

        tmp_mem = (char*)destination;
        while (len--)
        {
                *tmp_mem = (char)c;
                (tmp_mem++);
        }
        return (destination);
}

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*p;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	p = (char*)src;
	if (!dst || !src)
		return (0);
	len = ft_strlen(p);
	if (!dstsize)
		return (len);
	while (i < (dstsize - 1) && p[i])
	{
		dst[i] = p[i];
		(i++);
	}
	dst[i] = '\0';
	return (len);
}

char    *ft_strdup(const char *s1)
{
        int             i;
        char    *new;

        i = 0;
        while (s1[i])
                (i++);
        new = malloc(i + 1);
        if (!new)
                return (NULL);
        i = 0;
        while (s1[i])
        {
                new[i] = s1[i];
                (i++);
        }
        new[i] = '\0';
        return (new);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char                    *p;
        char                    *k;
        unsigned int    size;

        if (!s1)
                return (NULL);
        size = ft_strlen(s1) + ft_strlen(s2);
        if ((p = ft_calloc(size + 1, sizeof(s1))) == NULL)
                return (NULL);
        k = p;
        while (*s1)
        {
                (*p) = (*s1);
                (p++);
                (s1++);
        }
        while (*s2)
        {
                (*p) = (*s2);
                (p++);
                (s2++);
        }
        return (k);
}

char    *ft_strchr(const char *s, int c)
{
        char *p;

        p = (char*)s;
        while (*p)
        {
                if (*p == (char)c)
                        return (p);
                (p++);
        }
        if (!c)
                return (p);
        else
                return (NULL);
}

size_t   ft_getnbrlen(long int nbr)
{
        int n;

        if (nbr <= 0)
        {
                nbr = -nbr;
                n = 1;
        }
        else
                n = 0;
        while (nbr > 0)
        {
                nbr /= 10;
                (n++);
        }
        return (n);
}

char                    *ft_ltoa(long int nl)
{
        char            *s;
        size_t          len;

        len = ft_getnbrlen(nl) - 1;
        if (!(s = ft_calloc(len + 2, sizeof(char))))
                return (NULL);
        if (nl == 0)
                *s = '0';
        if (nl < 0)
        {
                *s = '-';
                nl = -nl;
        }
        while (nl > 0)
        {
                s[len--] = (nl % 10) + '0';
                nl /= 10;
        }
        return (s);
}
