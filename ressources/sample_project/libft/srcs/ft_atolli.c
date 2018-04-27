/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 19:05:34 by brigoux           #+#    #+#             */
/*   Updated: 2016/05/30 12:40:14 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_atolli(const char *str)
{
	int					sign;
	long long int		value;

	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	str += (*str == '-' || *str == '+') ? 0 : -1;
	value = 0;
	while (++str && ((*str >= '0' && *str <= '9')))
		value = (value * 10) + *str - '0';
	return (value * sign);
}
