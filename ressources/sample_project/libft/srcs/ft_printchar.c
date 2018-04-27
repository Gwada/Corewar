/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:10:30 by brigoux           #+#    #+#             */
/*   Updated: 2016/03/04 18:28:16 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		wchar_len(int c)
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

int				ft_printchar(t_conv *conv, int c, char fts)
{
	char	*str;

	if (conv->width)
	{
		str = ft_strnewfilled(conv->width - 1,
				conv->zero && !conv->minus ? '0' : ' ');
	}
	else
		str = ft_strdup("");
	if (fts == 'c' && !conv->l)
		c = (char)c;
	if (conv->minus)
	{
		ft_printwchar((wchar_t)c);
		ft_putstr(str);
	}
	else
	{
		ft_putstr(str);
		ft_printwchar((wchar_t)c);
	}
	free(str);
	return ((conv->width ? conv->width - 1 : 0) + wchar_len(c));
}
