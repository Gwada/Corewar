/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkwidth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:50:50 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/09 19:13:41 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_checkwidth(t_conv *convs, char **format)
{
	if (ft_isdigit(**format))
	{
		convs->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else
		convs->width = 0;
}
