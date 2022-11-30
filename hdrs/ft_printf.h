/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:36:41 by jcarlena          #+#    #+#             */
/*   Updated: 2020/12/26 17:55:05 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <stdio.h> // temporary
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

# define ZERO_FLAG 1
# define MINUS_FLAG 2

typedef struct			s_format
{
	char				conv;
	unsigned long		indxa;
	unsigned long		indxb;
	int					*width;
	int					*prec;
	short int			flags;
	void				*cont;
	char				*output;
	int					len;
	struct s_format		*next;
}						t_format;

typedef int 		(*t_handler)(t_format *);

/*
**...ft_major_funcs.c
*/
int					ft_preproc(t_format **list, const char *s);
int					ft_fillproc(t_format *node, va_list *ap, const char *s);
int					ft_applyfoo(t_format *node);
size_t				ft_printall(t_format **list, char *s);
/*
**...ft_printf.c
*/
int					ft_printf(const char *s, ...);
/*
**...ft_list_utils_1.c
*/
t_format			*ft_newformatnode(unsigned long a, unsigned long b, char c);
t_format			*ft_listlast(t_format *list);
void				ft_addback(t_format **list, t_format *new);
/*
**...ft_list_utils_2.c
*/
t_format			*ft_newformatnode(unsigned long a, unsigned long b, char c);
void				ft_delnode(t_format *node);
void				ft_delbegin(t_format **list);
void				ft_dellist(t_format **list);
int					ft_fatal(t_format **list);
/*
**...ft_other.c
*/
char				*ft_dectohex(unsigned long int x, char conv);
unsigned long		ft_getend(const char *s, const char *set);
size_t				ft_getcontsize(char conv);
size_t				ft_gethexlen(unsigned long int nbr);
int					ft_exceptions(t_format **node);
/*
**...ft_preproc_1.c
*/
int					ft_getstars(t_format *node, char *str, va_list *ap);
int					*ft_getprec(char *str);
int					*ft_getwidth(char *str);
int					ft_getflags(t_format *node, char *str);
/*
**...ft_preproc_2.c
*/
int					ft_getnumbers(t_format *node, char *str);
int					ft_getcontent(t_format *node, va_list *ap);
/*
**...ft_prostproc_prec_n_width.c
*/
char				*ft_sprec(char *str, t_format *node);
char				*ft_dixuprec(char *str, t_format *node);
char				*ft_setwidth(char *str, t_format *node);
void				ft_neg_width(char *result, char *str, t_format *node, char c);
char				*ft_diwidth(char *str, t_format *node);
/*
**...ft_handlers_utils.c
*/
t_handler			ft_gethandler(char conv);
/*
**...ft_handlers_dipux.c
*/
int					ft_handler_di(t_format *node);
int					ft_handler_p(t_format *node);
int					ft_handler_u(t_format *node);
int					ft_handler_x(t_format *node);
/*
**...ft_handlers_scperc.c
*/
int					ft_handler_s(t_format *node);
int					ft_handler_c(t_format *node);
int					ft_handler_perc(t_format *node);

#endif
