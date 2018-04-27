/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:46:15 by brigoux           #+#    #+#             */
/*   Updated: 2016/03/02 21:35:44 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *restrict format, ...)
{
	va_list		*val;
	char		*fcpy;
	char		*ptr;
	int			n;

	n = 0;
	while (format[n])
		n++;
	fcpy = ft_strnew(n);
	while (--n >= 0)
		fcpy[n] = format[n];
	ptr = fcpy;
	va_start(*(val = (va_list *)malloc(sizeof(va_list))), format);
	n = ft_parse(fcpy, val);
	va_end(*val);
	free(val);
	free(ptr);
	return (n);
}
