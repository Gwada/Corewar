/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:32:27 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/02/15 18:01:59 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_itoa_base(int n, int base, char *bs)
{
	char	*s;
	int		neg;
	int		count;

	if (n == -2147483648 && base == 10)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	neg = (n < 0 && base == 10 ? 1 : 0);
	count = ft_nb_len(n, base);
	if (!(s = ft_strnew(count + neg + 1)))
		return (NULL);
	n = (n < 0 && base == 10 ? -n : n);
	s[count + neg] = '\0';
	while (n)
	{
		s[--count + neg] = bs[(unsigned int)n % base];
		n /= base;
	}
	s[0] = (neg != 0 ? '-' : s[0]);
	return (s);
}
