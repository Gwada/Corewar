/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tktorza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 15:06:38 by tktorza           #+#    #+#             */
/*   Updated: 2016/07/25 21:50:25 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		print_winner(t_nit n, int started)
{
	t_player	*player;
	int			i;

	player = NULL;
	i = -1;
	while (++i < MAX_PLAYERS && g_data->player[i].file_name)
		if (g_data->player[i].number == g_data->last_live)
		{
			player = &(g_data->player[i]);
			break ;
		}
	attron(COLOR_PAIR(i + 20));
	mvprintw(n.y + started + 42, n.x + n.w + 4,
			"Contestant %i, \"%s\", has won !", player->number,
			player->header.prog_name);
	attroff(COLOR_PAIR(i + 20));
	refresh();
	return (0);
}

int		print_players(int x, int y, int w, t_player player[])
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS && player[i].file_name)
	{
		attron(COLOR_PAIR(i + 20));
		mvprintw(y + (i * 4) + 11, x + w + 4, "Player %d : %s"
				, -player[i].number, player[i].header.prog_name);
		attroff(COLOR_PAIR(i + 20));
		mvprintw(y + (i * 4) + 12, x + w + 4, "Last live : %-10d",
				g_data->player[i].last_live);
		mvprintw(y + (i * 4) + 13, x + w + 4
				, "Lives in current period : %-10d",
				g_data->player[i].period_live);
		i++;
	}
	return (y + (i * 3) + 13);
}

t_nit	create_box_2(t_nit n, t_win p_win, int started)
{
	mvaddch(n.y + n.h, n.x, p_win.border.bl);
	mvaddch(n.y + n.h, n.x + n.w, p_win.border.br);
	mvhline(n.y, n.x + 1, p_win.border.ts
			, n.w - 1 + racine_carre(MEM_SIZE, 1));
	mvhline(n.y + n.h, n.x + 1, p_win.border.bs
			, n.w - 1 + racine_carre(MEM_SIZE, 1));
	mvvline(n.y + 1, n.x, p_win.border.ls, n.h - 1);
	mvvline(n.y + 1, n.x + n.w, p_win.border.rs, n.h - 1);
	mvvline(n.y + 1, n.x + 1 + racine_carre(MEM_SIZE, 1) * 4
			, p_win.border.rs, n.h - 1);
	attroff(COLOR_PAIR(25));
	attron(COLOR_PAIR(26));
	mvprintw(n.y + 2, n.x + n.w + 4, "** %s **", g_running);
	mvprintw(n.y + 4, n.x + n.w + 4, "Cycles/second limit : %d", CPS_LIMIT);
	mvprintw(n.y + 6, n.x + n.w + 4, "Cycles : %d", g_data->cycle);
	mvprintw(n.y + 8, n.x + n.w + 4, "Processes : %-10d"
			, ft_lstlen(g_data->process));
	started = print_players(n.x, n.y, n.w, g_data->player);
	mvprintw(n.y + started + 1, n.x + n.w + 4
			, "CYCLE_TO_DIE : %-10d", g_data->cycle_to_die);
	mvprintw(n.y + started + 3, n.x + n.w + 4
			, "CYCLE_DELTA : %d", CYCLE_DELTA);
	mvprintw(n.y + started + 5, n.x + n.w + 4, "NBR_LIVE : %d", NBR_LIVE);
	mvprintw(n.y + started + 7, n.x + n.w + 4, "MAX_CHECKS : %d", MAX_CHECKS);
	return (n);
}

void	create_box_1(int nb, t_nit n, t_win *p_win)
{
	while (nb < MEM_SIZE)
	{
		p_win->content.x = n.x + 2;
		while (p_win->content.x < racine_carre(MEM_SIZE
					, 1) * 3 && nb < MEM_SIZE)
		{
			color_status(g_data->status[nb]);
			mvprintw(p_win->content.y, p_win->content.x
					, "%02hhx", g_data->memory[nb]);
			nb++;
			p_win->content.x += 3;
		}
		p_win->content.y++;
	}
}

void	create_box(t_win *p_win, bool flag)
{
	t_nit	n;
	int		nb;
	int		started;

	flag++;
	started = 0;
	nb = 0;
	n.x = p_win->startx;
	n.y = p_win->starty;
	n.w = p_win->width + 2;
	n.h = p_win->height + 2;
	p_win->content.val = 0;
	p_win->content.x = n.x;
	p_win->content.y = n.y + 2;
	attroff(COLOR_PAIR(26));
	attron(COLOR_PAIR(25));
	mvaddch(n.y, n.x, p_win->border.tl);
	mvaddch(n.y, n.x + n.w, p_win->border.tr);
	n = create_box_2(n, *p_win, started);
	create_box_1(nb, n, p_win);
	g_data->process ? 0 : print_winner(n, started);
	refresh();
}
