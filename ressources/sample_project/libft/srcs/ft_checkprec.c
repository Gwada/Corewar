/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkprec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 19:09:34 by brigoux           #+#    #+#             */
/*   Updated: 2016/03/04 16:46:05 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_checkprec(t_conv *convs, char **format)
{
	if (**format == '.')
	{
		(*format)++;
		convs->prec = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else
		convs->prec = -2;
}
