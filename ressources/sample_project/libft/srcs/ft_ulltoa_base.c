/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:58:53 by brigoux           #+#    #+#             */
/*   Updated: 2016/03/03 11:21:04 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ulltoa_base(unsigned long long int num, int base, char *lset)
{
	if (num >= (unsigned long long)base)
		return (ft_strjoinfree(ft_lltoa_base(num / base, base, lset),
					ft_lltoa_base(num % base, base, lset)));
	else
		return (ft_chartostr(lset[num]));
}
