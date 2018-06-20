/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:08:44 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/09 22:02:52 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int					pos_num;
	unsigned long long	max;

	max = 0;
	pos_num = 1;
	while (*nptr == ' ' || (*nptr >= 7 && *nptr <= 13))
		++nptr;
	(*nptr == '-' && (pos_num = -1)) || (*nptr == '+') ? ++nptr : 0;
	while (*nptr >= '0' && *nptr <= '9')
		if ((max = max * 10 + *nptr++ - '0') > INTMAXLEN)
			return ((pos_num == 1) ? -1 : 0);
	return ((int)(max * pos_num));
}
