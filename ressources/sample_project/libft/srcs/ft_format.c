/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 16:47:26 by brigoux           #+#    #+#             */
/*   Updated: 2016/03/03 14:03:36 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*part1(char *str, t_conv *conv, char fts)
{
	if (ft_strcount("sS", fts) && ft_inrange(conv->prec, 0, ft_strlen(str)))
		str[conv->prec] = '\0';
	if (ft_strcount("pdDioOuUxX", fts) && conv->prec > 0 && *str != '-')
		str = ft_strpad(str, conv->prec, '0', -1);
	if (ft_strcount("dDioOuUxX", fts)
			&& conv->prec - (int)ft_strlen(str) + 1 > 0 && *str == '-')
		str = ft_strinsert(str,
				ft_strnewfilled(conv->prec - (int)ft_strlen(str) + 1, '0'), 1);
	if (ft_strcount("dDi", fts) && conv->plus && *str != '-')
		str = ft_strjoinfree(ft_chartostr('+'), str);
	else if (ft_strcount("dDi", fts) && conv->space && *str != '-')
		str = ft_strjoinfree(ft_chartostr(' '), str);
	if (ft_strcount("pdDioOuUxX", fts) && !ft_strcmp(str, "0") && !conv->prec)
		ft_strfreedef(&str, ft_strnew(0));
	if (ft_strcount("oO", fts) && conv->pound && *str != '0')
		str = ft_strjoinfree(ft_chartostr('0'), str);
	return (str);
}

static char		*part2(char *str, t_conv *conv, char fts)
{
	if ((ft_strcount("xX", fts) && conv->pound && ft_strcmp(str, "") &&
			ft_strcmp(str, "0")) || fts == 'p')
		str = ft_strjoinfree(ft_strdup(fts > '_' ? "0x" : "0X"), str);
	if (ft_strcount("pdDioOuUxX", fts) && *ft_strchrone(str, " xX-+") &&
			conv->zero && !conv->minus && conv->width > (int)ft_strlen(str))
		str = ft_strinsert(str, ft_strnewfilled(conv->width - ft_strlen(str),
					'0'), ft_strchrone(str, " xX-+") + 1 - str);
	if (ft_strcount("dDioOuUxX", fts) && !*ft_strchrone(str, " xX-+") &&
			conv->zero && !conv->minus)
		str = ft_strpad(str, conv->width, conv->prec >= 0 ? ' ' : '0', -1);
	if (conv->width &&
			!(ft_strcount("pdDioOuUxX", fts) && conv->zero && !conv->minus))
		str = ft_strpad(str, conv->width,
				(!conv->zero || conv->minus || conv->prec > 0) ? ' ' : '0',
				conv->minus ? 1 : -1);
	return (str);
}

char			*ft_format(char *str, t_conv *conv, char fts)
{
	if (!str)
		return (str);
	str = part1(str, conv, fts);
	str = part2(str, conv, fts);
	return (str);
}
