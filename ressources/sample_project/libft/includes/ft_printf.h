/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:47:05 by brigoux           #+#    #+#             */
/*   Updated: 2016/06/25 16:40:21 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# include <locale.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include "libft.h"

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

typedef struct		s_conv
{
	int				pound;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				width;
	int				prec;
	int				l;
	int				h;
}					t_conv;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

int					ft_printf(const char *restrict format, ...);

void				ft_checkflags(t_conv *convs, char **format);
void				ft_checkmodif(t_conv *convs, char **format);
void				ft_checkprec(t_conv *convs, char **format);
void				ft_checkwidth(t_conv *convs, char **format);
char				*ft_convert(va_list *val, char **format);
char				*ft_format(char *str, t_conv *conv, char fts);
char				*ft_getarg(va_list *val, char type, t_conv *conv);
char				*ft_lltoa_base(long long int num, int base, char *lset);
int					ft_parse(char *format, va_list *val);
int					ft_printchar(t_conv *conv, int c, char fts);
int					ft_printls(wchar_t *str, t_conv *conv);
int					ft_printwchar(wchar_t c);
char				*ft_tronc(char *str, t_conv *conv, char fts);
char				*ft_ulltoa_base(
		unsigned long long int num, int base, char *lset);
char				*get_hh(va_list *val, char type);
char				*get_h(va_list *val, char type);
char				*get_i(va_list *val, char type);
char				*get_l(va_list *val, char type);
char				*get_ll(va_list *val, char type);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
