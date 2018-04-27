/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <brigoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 15:23:21 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/25 17:44:55 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_memdump(void *mem, int size)
{
	int		i;
	int		c;
	char	*m;

	m = (char *)mem;
	i = 0;
	while (i < size)
	{
		ft_printf("%#0.4hx: ", i);
		c = 0;
		while (c++ < 16 && ++i)
			ft_printf((i - 1 < size ? " %0.2hhx" : "   "), m[i - 1]);
		ft_printf("  ");
		c = 16;
		while (--c >= 0 && i - c - 1 < size)
			ft_printf((ft_isprint(m[i - c - 1]) ? "%c" : "."), m[i - c - 1]);
		ft_printf("\n");
	}
	ft_printf("%#0.4hx:\n\n", i);
}
