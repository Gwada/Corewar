/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tktorza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 14:57:17 by tktorza           #+#    #+#             */
/*   Updated: 2016/07/25 15:38:03 by tktorza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		racine_carre(int val, int nb)
{
	if (nb * nb >= val)
		return (nb);
	else
		return (racine_carre(val, nb + 1));
}

int		basic_status(int nb)
{
	int ok;

	ok = 24;
	(nb & STAT_PC) > 0 ? ok = 25 : nb;
	return (ok);
}

int		colored_status(int nb)
{
	int		val;

	val = 3 + ((nb & STAT_NUM) >> 4);
	if ((nb & STAT_PC) == 0)
		return ((nb & STAT_COPY) == 0) ? (19 + ((nb & STAT_NUM)
					>> 4)) : (15 + ((nb & STAT_NUM) >> 4));
	else
	{
		(nb & STAT_COPY) > 0 ? val = -1 + ((nb & STAT_NUM) >> 4) : nb;
		(nb & STAT_LIVE) > 0 ? val = (7 + ((nb & STAT_NUM) >> 4)) : nb;
		(nb & STAT_AFF) > 0 ? val = (11 + ((nb & STAT_NUM) >> 4)) : nb;
		return (val);
	}
}

int		color_status(int nb)
{
	int pair_nb;

	pair_nb = colored_status(nb);
	((nb & STAT_NUM) >> 4) == 0 ? pair_nb = basic_status(nb) : pair_nb;
	attron(COLOR_PAIR(pair_nb));
	return (pair_nb);
}

void	color_one(void)
{
	init_color(COLOR_WW, 1000, 1000, 1000);
	init_color(COLOR_GREY, 400, 400, 400);
	init_color(COLOR_BLUE_C, 105 * 1000 / 255
			, 118 * 1000 / 255, 252 * 1000 / 255);
	init_color(COLOR_RED_C, 255 * 1000 / 255
			, 107 * 1000 / 255, 90 * 1000 / 255);
	init_color(COLOR_GREEN_C, 103 * 1000 / 255
			, 248 * 1000 / 255, 110 * 1000 / 255);
	init_color(COLOR_YELLOW_C, 255 * 1000 / 255
			, 255 * 1000 / 255, 107 * 1000 / 255);
	init_pair(0, COLOR_BLUE_C, COLOR_BLUE);
	init_pair(1, COLOR_GREEN_C, COLOR_GREEN);
	init_pair(2, COLOR_YELLOW_C, COLOR_YELLOW);
	init_pair(3, COLOR_RED_C, COLOR_RED);
	init_pair(4, COLOR_BLACK, COLOR_BLUE);
	init_pair(5, COLOR_BLACK, COLOR_GREEN);
	init_pair(6, COLOR_BLACK, COLOR_YELLOW);
	init_pair(7, COLOR_BLACK, COLOR_RED);
	init_pair(8, COLOR_WHITE, COLOR_BLUE);
	init_pair(9, COLOR_WHITE, COLOR_GREEN);
	init_pair(10, COLOR_WHITE, COLOR_YELLOW);
	init_pair(11, COLOR_WHITE, COLOR_RED);
	init_pair(12, COLOR_GREY, COLOR_BLUE);
	init_pair(13, COLOR_GREY, COLOR_GREEN);
}
