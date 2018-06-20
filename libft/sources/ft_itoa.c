/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:06:10 by dlavaury          #+#    #+#             */
/*   Updated: 2017/11/06 17:07:14 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int				number;
	char			*sn;
	unsigned int	ui;

	ui = (n < 0) ? -n : n;
	number = ft_countnumber(n);
	if (!(sn = (char*)malloc(sizeof(char) * (number + 1))))
		return (NULL);
	sn[number] = '\0';
	while (--number >= 0)
	{
		sn[number] = (!number && n < 0) ? '-' : ui % 10 + '0';
		ui /= 10;
	}
	return (sn);
}
