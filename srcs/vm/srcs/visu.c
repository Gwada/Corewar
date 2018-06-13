/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:21:52 by fchanal           #+#    #+#             */
/*   Updated: 2018/06/13 18:19:41 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		fill_basics(t_core *c)
{
	werase(c->visu.title.win);
	werase(c->visu.usages.win);
	werase(c->visu.stats.win);
	werase(c->visu.states.win);
	werase(c->visu.arena.win);
	erase();
	draw_basics(c);
	fill_title(c);
	fill_usages(c);
	fill_arena(c);
	fill_stats(c);
	fill_states(c);
	refresh();
	wrefresh(c->visu.title.win);
	wrefresh(c->visu.usages.win);
	wrefresh(c->visu.arena.win);
	wrefresh(c->visu.stats.win);
	wrefresh(c->visu.states.win);
}

static void		load(t_core *c, int id, t_process *p, uint64_t t)
{
	if (id == 0)
		fill_basics(c);
	else if (id == 1)
	{
		fill_stats(c);
		wrefresh(c->visu.stats.win);
	}
	else if (id > 2)
	{
		update_arena(c, id, p, t);
		wrefresh(c->visu.arena.win);
	}
}

static void		handle_event(t_core *c, char cs)
{
	if (cs == 'q')
	{
		endwin();
		exit(0);
	}
	else if (cs == ' ')
		c->visu.event_flag |= F_PAUSE;
	else if (cs == 's')
		c->visu.event_flag |= F_SKURT;
	else if (cs == '+')
	{
		if (c->visu.fps == 0)
			c->visu.fps = 50;
		else
			c->visu.fps += 10;
	}
	else if (cs == '-')
	{
		if (c->visu.fps == 0)
			c->visu.fps = 50;
		else
			c->visu.fps -= 10;
	}
}

void			visu(t_core *c, int id, t_process *p, uint64_t t)
{
	if (c->visu.w_size.y == 0 && c->visu.w_size.x == 0)
	{
		id = 0;
		getmaxyx(stdscr, c->visu.w_size.y, c->visu.w_size.x);
	}
	load(c, id, p, t);
	handle_event(c, getch());
	if (c->visu.event_flag & F_PAUSE)
	{
		getchar();
		c->visu.event_flag &= ~F_PAUSE;
	}
	if (c->visu.event_flag & F_SKURT)
	{
		if (getchar() != 's')
			c->visu.event_flag &= ~F_SKURT;
	}
	if (id == 1)
	{
		if (c->visu.fps != 0)
			usleep(1000 / c->visu.fps * 1000);
		else
			usleep(1000 * 50);
	}
}
