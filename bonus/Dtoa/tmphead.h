#ifndef TMPHEAD_H
# define TMPHEAD_H
# include <stdlib.h>
# include <stdio.h>

char		*ft_doubletobin(double x, size_t prec);
void		ft_setvars(char **cat, char **n_i, char **m_d, long int exponent);
long int	ft_getexponent(double x);
size_t		ft_mantissalen(long int exponent);
char		*ft_getmantissa(double x, long int exponent);
void		ft_cutstr(char **tocut, char **a, char **b, long int x);
char		*ft_halfof(char *nbr);
char		*ft_decadd(char *a, char *b);
char		*ft_bintodec(char *bin, size_t prec);
char		*ft_bintoint(char *bin, int sign);
char		*ft_round_number(char **number, size_t prec);

void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memset(void *destination, int c, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
size_t		ft_getnbrlen(long int nbr);
char		*ft_ltoa(long int nl);


#endif
