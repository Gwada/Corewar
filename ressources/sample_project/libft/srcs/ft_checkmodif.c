/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmodif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 20:31:19 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/27 15:45:22 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkmodif(t_conv *convs, char **format)
{
	convs->l = 0;
	convs->h = 0;
	if (**format == 'l')
	{
		(*format)++;
		convs->l = (**format == 'l') ? 2 : 1;
		if (**format == 'l')
			(*format)++;
	}
	else if (**format == 'h')
	{
		(*format)++;
		convs->h = (**format == 'h') ? 2 : 1;
		if (**format == 'h')
			(*format)++;
	}
	else if (ft_strcount("jz", **format))
	{
		(*format)++;
		convs->l = 2;
	}
	if (**format < 'a' && **format != 'X')
		convs->l += 1;
}
