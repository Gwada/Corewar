/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:41:27 by brigoux           #+#    #+#             */
/*   Updated: 2016/03/03 15:15:12 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_getarg(va_list *val, char type, t_conv *conv)
{
	char	*s;

	if (type == 'p')
	{
		return (ft_ulltoa_base((unsigned long long int)va_arg(*val, void *), 16,
					"0123456789abcdef"));
	}
	if (ft_strcount("dDioOuUxX", type))
	{
		if (conv->l == 2)
			return (get_ll(val, type));
		else if (conv->l == 1)
			return (get_l(val, type));
		else if (conv->h == 1)
			return (get_h(val, type));
		else if (conv->h == 2)
			return (get_hh(val, type));
		else
			return (get_i(val, type));
	}
	if (type == 's')
		return (ft_strdup((s = va_arg(*val, char *)) ? s : "(null)"));
	return (NULL);
}
