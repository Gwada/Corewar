/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:46:57 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/01 21:10:48 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_memory(const void *mem, size_t size, size_t elem)
{
	size_t	i;
	size_t	j;
	const unsigned char	b[] = "0123456789abcdef";
	const unsigned char *s;

	i = 0;
	s = (const unsigned char*)mem;
	while (i < size)
	{
		j = 0;
		while (j < elem && i + j < size)
		{
			write(1, &b[s[i + j] / 16 % 16], 1);
			write(1, &b[s[i + j] % 16], 1);
			j % 2 ? write (1, " ", 1) : 0;
			++j;
		}
		while (j < elem)
		{
			write (1, "  ", 2);
			j % 2 ? write (1, " ", 1) : 0;
			++j;
		}
		j = 0;
		while (j < elem && i + j < size)
		{
			write(1, s[i + j] >= 32 && s[i + j] < 127 ? (char*)&s[i + j] : ".", 1);
			++j;
		}
		write (1, "\n", 1);
		i += elem;
	}
}
