/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:46:57 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/02 14:36:55 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				put_hex(const unsigned char *s, size_t size,
						size_t elem, size_t i)
{
	size_t				j;
	size_t				k;
	char				*b;
	char				buff[11];

	j = 0;
	k = 0;
	b = "0123456789abcdef";
	ft_bzero(buff, sizeof(buff));
	while (j < elem && i + j < size)
	{
		buff[k++] = b[s[i + j] / 16 % 16];
		buff[k++] = b[s[i + j] % 16];
		j++ % 2 ? buff[k++] = ' ' : 0;
		k == 10 ? write(1, buff, k) : 0;
		k == 10 && !(k = 0) ? ft_bzero(buff, sizeof(buff)) : 0;
	}
	while (j < elem)
	{
		buff[k++] = ' ';
		buff[k++] = ' ';
		j++ % 2 ? buff[k++] = ' ' : 0;
		k == 10 ? write(1, buff, k) : 0;
		k == 10 && !(k = 0) ? ft_bzero(buff, sizeof(buff)) : 0;
	}
}

static void				put_car(const unsigned char *s, size_t size,
						size_t elem, size_t i)
{
	size_t				j;
	size_t				k;
	char				buff[66];

	j = 0;
	k = 0;
	while (j < elem && i + j < size)
	{
		if (s[i + j] >= 32 && s[i + j] < 127)
			buff[k++] = s[i + j];
		else
			buff[k++] = '.';
		k == 64 ? write(1, buff, k) : 0;
		k == 64 && !(k = 0) ? ft_bzero(buff, sizeof(buff)) : 0;
		++j;
	}
	buff[k++] = '\n';
	write(1, buff, k);
}

void					ft_print_mem(const void *mem, size_t size, size_t elem)
{
	size_t				i;
	const unsigned char	*s;

	i = 0;
	s = (const unsigned char*)mem;
	while (i < size)
	{
		put_hex(s, size, elem, i);
		put_car(s, size, elem, i);
		i += elem;
	}
}
