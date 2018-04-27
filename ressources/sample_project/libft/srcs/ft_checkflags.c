/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:06:27 by brigoux           #+#    #+#             */
/*   Updated: 2016/01/25 18:44:01 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkflags(t_conv *convs, char **format)
{
	convs->pound = 0;
	convs->zero = 0;
	convs->minus = 0;
	convs->plus = 0;
	convs->space = 0;
	while (ft_strcount("#0-+ ", **format))
	{
		if (**format == '#')
			convs->pound = 1;
		else if (**format == '0')
			convs->zero = 1;
		else if (**format == '-')
			convs->minus = 1;
		else if (**format == '+')
			convs->plus = 1;
		else if (**format == ' ')
			convs->space = 1;
		else
			break ;
		(*format)++;
	}
}
