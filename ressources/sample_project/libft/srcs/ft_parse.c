/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 21:12:57 by brigoux           #+#    #+#             */
/*   Updated: 2016/03/03 15:34:17 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse(char *format, va_list *val)
{
	int		len;
	char	*str;

	len = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			len++;
		}
		else
		{
			if (!(str = ft_convert(val, &format)))
				return (-1);
			len += ft_strlen(str);
			ft_putstr(ft_strcount("cCS", *format) ? "" : str);
			free(str);
		}
		format++;
	}
	return (len);
}
