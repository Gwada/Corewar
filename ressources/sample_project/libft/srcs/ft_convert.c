/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 19:36:30 by brigoux           #+#    #+#             */
/*   Updated: 2016/03/04 18:14:14 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert(va_list *val, char **format)
{
	t_conv		convs;

	(*format)++;
	ft_checkflags(&convs, format);
	ft_checkwidth(&convs, format);
	ft_checkprec(&convs, format);
	ft_checkmodif(&convs, format);
	if (**format == 'S' || (**format == 's' && convs.l))
	{
		**format = 'S';
		return (ft_strnewfilled(
					ft_printls(va_arg(*val, wchar_t *), &convs), 'S'));
	}
	else if (ft_strcount("cC", **format))
		return (ft_strnewfilled(
					ft_printchar(&convs, va_arg(*val, int), **format), 'c'));
	else if (ft_strcount("spdDioOuUxX", **format))
		return (ft_format(ft_getarg(val, **format, &convs), &convs, **format));
	else
		return (ft_format(ft_chartostr(**format), &convs, **format));
}
