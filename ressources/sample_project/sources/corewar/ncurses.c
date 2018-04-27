/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tktorza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 14:17:04 by tktorza           #+#    #+#             */
/*   Updated: 2016/07/25 22:33:10 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	color_initialize(void)
{
	color_one();
	init_pair(14, COLOR_GREY, COLOR_YELLOW);
	init_pair(15, COLOR_GREY, COLOR_RED);
	init_pair(16, COLOR_BLUE_C, COLOR_BLACK);
	init_pair(17, COLOR_GREEN_C, COLOR_BLACK);
	init_pair(18, COLOR_YELLOW_C, COLOR_BLACK);
	init_pair(19, COLOR_RED_C, COLOR_BLACK);
	init_pair(20, COLOR_BLUE, COLOR_BLACK);
	init_pair(21, COLOR_GREEN, COLOR_BLACK);
	init_pair(22, COLOR_YELLOW, COLOR_BLACK);
	init_pair(23, COLOR_RED, COLOR_BLACK);
	init_pair(24, COLOR_GREY, COLOR_BLACK);
	init_pair(25, COLOR_GREY, COLOR_GREY);
	init_pair(26, COLOR_WW, COLOR_BLACK);
}

t_win	ncurses_main_bis(void)
{
	t_win	win;

	g_running = ft_strdup("RUNNING");
	initscr();
	start_color();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	color_initialize();
	init_win_params(&win);
	printw("Press any key to start...");
	print_start();
	return (win);
}

void	ncurses_main_bbis(t_win win)
{
	check_status();
	create_box(&win, TRUE);
	refresh();
	g_data->cycle++;
}

void	ncurses_main(void)
{
	t_win	win;

	win = ncurses_main_bis();
	wait_for_key();
	while (g_data->process)
	{
		do_cycle();
		if (++g_data->period_cycle >= g_data->cycle_to_die)
		{
			g_data->period_cycle = 0;
			if (get_periodlive() >= NBR_LIVE || ++g_data->check == MAX_CHECKS)
			{
				g_data->check = 0;
				g_data->cycle_to_die = CTD(g_data->cycle_to_die - CYCLE_DELTA);
			}
			check_process(&g_data->process);
		}
		ncurses_main_bbis(win);
	}
	g_running = ft_strdup("  END  ");
	create_box(&win, TRUE);
	wait_for_key();
	endwin();
}

void	init_win_params(t_win *p_win)
{
	p_win->height = racine_carre(MEM_SIZE, 1) + 1;
	p_win->width = racine_carre(MEM_SIZE, 1) * 3;
	p_win->starty = 4;
	p_win->startx = 0;
	p_win->border.ls = '|';
	p_win->border.rs = '|';
	p_win->border.ts = '-';
	p_win->border.bs = '-';
	p_win->border.tl = '+';
	p_win->border.tr = '+';
	p_win->border.bl = '+';
	p_win->border.br = '+';
}
