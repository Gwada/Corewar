/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfromsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:58:35 by brigoux           #+#    #+#             */
/*   Updated: 2016/03/03 14:29:50 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_ll(va_list *val, char type)
{
	if (ft_strcount("Ddi", type))
	{
		return (ft_lltoa_base(va_arg(*val, long long int),
					10, "0123456789"));
	}
	if (ft_strcount("oO", type))
	{
		return (ft_ulltoa_base(va_arg(*val, unsigned long long int),
					8, "01234567"));
	}
	if (ft_strcount("uU", type))
	{
		return (ft_ulltoa_base(va_arg(*val, unsigned long long int),
					10, "0123456789"));
	}
	if (ft_strcount("xX", type))
	{
		return (ft_ulltoa_base(va_arg(*val, unsigned long long int),
					16, type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF"));
	}
	return (NULL);
}

char		*get_l(va_list *val, char type)
{
	if (ft_strcount("Ddi", type))
	{
		return (ft_lltoa_base(va_arg(*val, long int),
					10, "0123456789"));
	}
	if (ft_strcount("oO", type))
	{
		return (ft_ulltoa_base(va_arg(*val, unsigned long int),
					8, "01234567"));
	}
	if (ft_strcount("uU", type))
	{
		return (ft_ulltoa_base(va_arg(*val, unsigned long int),
					10, "0123456789"));
	}
	if (ft_strcount("xX", type))
	{
		return (ft_ulltoa_base(va_arg(*val, unsigned long int),
					16, type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF"));
	}
	return (NULL);
}

char		*get_i(va_list *val, char type)
{
	if (ft_strcount("Ddi", type))
	{
		return (ft_lltoa_base(va_arg(*val, int),
					10, "0123456789"));
	}
	if (ft_strcount("oO", type))
	{
		return (ft_ulltoa_base(va_arg(*val, unsigned int),
					8, "01234567"));
	}
	if (ft_strcount("uU", type))
	{
		return (ft_ulltoa_base(va_arg(*val, unsigned int),
					10, "0123456789"));
	}
	if (ft_strcount("xX", type))
	{
		return (ft_ulltoa_base(va_arg(*val, unsigned int),
					16, type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF"));
	}
	return (NULL);
}

char		*get_h(va_list *val, char type)
{
	if (ft_strcount("Ddi", type))
	{
		return (ft_lltoa_base((short)va_arg(*val, int),
					10, "0123456789"));
	}
	if (ft_strcount("oO", type))
	{
		return (ft_ulltoa_base((unsigned short)va_arg(*val, int),
					8, "01234567"));
	}
	if (ft_strcount("uU", type))
	{
		return (ft_ulltoa_base((unsigned short)va_arg(*val, int),
					10, "0123456789"));
	}
	if (ft_strcount("xX", type))
	{
		return (ft_ulltoa_base((unsigned short)va_arg(*val, int),
					16, type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF"));
	}
	return (NULL);
}

char		*get_hh(va_list *val, char type)
{
	if (ft_strcount("Ddi", type))
	{
		return (ft_lltoa_base((char)va_arg(*val, int),
					10, "0123456789"));
	}
	if (ft_strcount("oO", type))
	{
		return (ft_ulltoa_base((unsigned char)va_arg(*val, int),
					8, "01234567"));
	}
	if (ft_strcount("uU", type))
	{
		return (ft_ulltoa_base((unsigned char)va_arg(*val, int),
					10, "0123456789"));
	}
	if (ft_strcount("xX", type))
	{
		return (ft_ulltoa_base((unsigned char)va_arg(*val, int),
					16, type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF"));
	}
	return (NULL);
}
