/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:22:25 by fchanal           #+#    #+#             */
/*   Updated: 2018/06/13 18:45:45 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*ft_get_hex_memory(void *m, size_t mem_size)
{
	char	*ret;
	char	*rusher;
	uint8_t	*tmp;

	if (!mem_size || !m || !(ret = (char*)malloc(mem_size * 2)))
		return (NULL);
	rusher = ret;
	tmp = (uint8_t*)m;
	while (mem_size)
	{
		*rusher++ = HEX_DIGIT[*tmp >> 4];
		*rusher++ = HEX_DIGIT[*tmp & 0x0F];
		++tmp;
		--mem_size;
	}
	return (ret);
}

void	ft_bzero(void *m, size_t len)
{
	uint64_t	*lw;

	while (len % 8)
	{
		*(uint8_t *)m++ = (uint8_t)0;
		--len;
	}
	if (len)
	{
		lw = (uint64_t *)m;
		while (len)
		{
			*lw++ = (uint64_t)0;
			len -= 8;
		}
	}
}

void	init_visu(t_core *c)
{
	setlocale(LC_ALL, "");
	ft_bzero(&c->visu, sizeof(c->visu));
	initscr();
	raw();
	nodelay(stdscr, TRUE);
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_WHITE);
}
