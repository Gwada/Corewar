/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 16:16:30 by brigoux           #+#    #+#             */
/*   Updated: 2016/03/03 13:45:42 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_lltoa_base(long long int num, int base, char *lset)
{
	if (num + 1 == -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (num < 0)
	{
		return (ft_strjoinfree(ft_chartostr('-'),
					ft_lltoa_base(-num, base, lset)));
	}
	if (num >= base)
	{
		return (ft_strjoinfree(ft_lltoa_base(num / base, base, lset),
					ft_lltoa_base(num % base, base, lset)));
	}
	return (ft_chartostr(lset[num]));
}
