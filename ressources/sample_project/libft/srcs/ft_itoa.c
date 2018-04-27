/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 18:39:47 by brigoux           #+#    #+#             */
/*   Updated: 2016/01/24 17:58:55 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		return (ft_strjoinfree(ft_chartostr('-'), ft_itoa(-n)));
	if (n >= 10)
		return (ft_strjoinfree(ft_itoa(n / 10), ft_itoa(n % 10)));
	return (ft_chartostr('0' + n));
}
