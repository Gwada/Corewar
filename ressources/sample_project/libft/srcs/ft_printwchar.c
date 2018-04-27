/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:01:24 by brigoux           #+#    #+#             */
/*   Updated: 2016/03/03 16:02:56 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_2byte(unsigned int c)
{
	unsigned char byte[2];
	unsigned char printed_byte;

	byte[0] = (c << 26) >> 26;
	byte[1] = ((c >> 6) << 27) >> 27;
	printed_byte = (49280 >> 8) | byte[1];
	write(1, &printed_byte, 1);
	printed_byte = (49280ll << 24) >> 24 | byte[0];
	write(1, &printed_byte, 1);
	return (2);
}

static int		print_3byte(unsigned int c)
{
	unsigned char byte[3];
	unsigned char printed_byte;

	byte[0] = (c << 26) >> 26;
	byte[1] = ((c >> 6) << 26) >> 26;
	byte[2] = ((c >> 12) << 28) >> 28;
	printed_byte = (14712960 >> 16) | byte[2];
	write(1, &printed_byte, 1);
	printed_byte = (14712960ll << 16) >> 24 | byte[1];
	write(1, &printed_byte, 1);
	printed_byte = (14712960ll << 24) >> 24 | byte[0];
	write(1, &printed_byte, 1);
	return (3);
}

static int		print_4byte(unsigned int c)
{
	unsigned char byte[4];
	unsigned char printed_byte;

	byte[0] = (c << 26) >> 26;
	byte[1] = ((c >> 6) << 26) >> 26;
	byte[2] = ((c >> 12) << 26) >> 26;
	byte[3] = ((c >> 18) << 29) >> 29;
	printed_byte = (4034953344 >> 24) | byte[3];
	write(1, &printed_byte, 1);
	printed_byte = (4034953344 << 8) >> 24 | byte[2];
	write(1, &printed_byte, 1);
	printed_byte = (4034953344 << 16) >> 24 | byte[1];
	write(1, &printed_byte, 1);
	printed_byte = (4034953344 << 24) >> 24 | byte[0];
	write(1, &printed_byte, 1);
	return (4);
}

int				ft_printwchar(wchar_t c)
{
	unsigned int wchar;

	wchar = (unsigned int)c;
	if (c <= 0x7f)
	{
		ft_putchar(c);
		return (1);
	}
	else if (c <= 0x7ff)
		return (print_2byte(wchar));
	else if (c <= 0xffff)
		return (print_3byte(wchar));
	else if (c <= 0x1fffff)
		return (print_4byte(wchar));
	else
		return (-1);
}
