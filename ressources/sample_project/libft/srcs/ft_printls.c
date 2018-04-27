/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:15:32 by brigoux           #+#    #+#             */
/*   Updated: 2016/03/04 18:15:00 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		putwidth(t_conv *conv, int len)
{
	char	*str;

	if (conv->width > len && !conv->minus)
	{
		len = conv->width - len;
		str = ft_strnewfilled(len, !conv->zero || conv->minus ? ' ' : '0');
		ft_putstr(str);
		free(str);
		return (len);
	}
	return (0);
}

static int		wclen(int c)
{
	if (c <= 0x7f)
		return (1);
	else if (c <= 0x7ff)
		return (2);
	else if (c <= 0xffff)
		return (3);
	else if (c <= 0x1fffff)
		return (4);
	return (0);
}

static int		wspartlen(wchar_t *str, int size)
{
	int		len;

	len = 0;
	while (*str)
	{
		if (len + wclen(*str) > size)
			return (len);
		len += wclen(*str);
		str++;
	}
	return (len);
}

static int		wstrlen(wchar_t *str)
{
	int len;

	len = 0;
	while (*str)
	{
		len += wclen(*str);
		str++;
	}
	return (len);
}

int				ft_printls(wchar_t *str, t_conv *conv)
{
	int		len;
	int		n;
	char	*s;

	if (!str)
		str = L"(null)";
	len = 0 + putwidth(conv, ft_inrange(conv->prec, 0, wstrlen(str)) ?
			wspartlen(str, conv->prec) : wstrlen(str));
	n = 0;
	while (*str)
	{
		if (conv->prec >= 0 &&
				(n >= conv->prec || n + wclen(*str) > conv->prec))
			break ;
		n += ft_printwchar(*str);
		str++;
	}
	if (len + len < conv->width && conv->minus)
	{
		s = ft_strnewfilled(conv->width - (len + n), conv->zero ? '0' : ' ');
		ft_putstr(s);
		free(s);
		len = conv->width - n;
	}
	return (len + n);
}
