/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_fill_wins_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:16:22 by fchanal           #+#    #+#             */
/*   Updated: 2018/06/13 17:22:06 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				update_states(t_core *c, t_process *ps, int index)
{
	int		x;

	index *= -1;
	if (index > c->player)
		return ;
	x = 2 + 12 * (index - 1);
	wattrset(c->visu.states.win, A_BLINK);
	mvwprintw(c->visu.states.win, 1, x, "%s", H_1);
	mvwprintw(c->visu.states.win, 2, x, "%s", H_2);
	mvwprintw(c->visu.states.win, 3, x, "%s", H_3);
	mvwprintw(c->visu.states.win, 4, x, "%s", H_4);
	mvwprintw(c->visu.states.win, 5, x, "%s", H_5);
	wrefresh(c->visu.states.win);
	usleep(1000 * 30);
	wattrset(c->visu.states.win, COLOR_PAIR((x - 2) / 12 + 1));
	mvwprintw(c->visu.states.win, 1, x, "%s", H_1);
	mvwprintw(c->visu.states.win, 2, x, "%s", H_2);
	mvwprintw(c->visu.states.win, 3, x, "%s", H_3);
	mvwprintw(c->visu.states.win, 4, x, "%s", H_4);
	mvwprintw(c->visu.states.win, 5, x, "%s", H_5);
}

void				fill_usages(t_core *c)
{
	mvwprintw(c->visu.usages.win, (int)(double)(c->visu.usages.size.y / 2 - 1),\
			3, "Quit:  'q'");
	mvwprintw(c->visu.usages.win, (int)(double)(c->visu.usages.size.y / 2),\
			3, "Pause: 'space'");
	mvwprintw(c->visu.usages.win, (int)(double)(c->visu.usages.size.y / 2 - 1),\
			c->visu.usages.size.x - 22, "Frame/Sec:    '+/-'");
	mvwprintw(c->visu.usages.win, (int)(double)(c->visu.usages.size.y / 2),\
			c->visu.usages.size.x - 22, "Step by step:   's'");
}

static void			player_stat(t_core *c)
{
	unsigned count;
	unsigned x;
	unsigned y;

	count = 0;
	x = 3;
	y = 10;
	while (count < c->player)
	{
		if (count == 2)
		{
			x = 3;
			y += 5;
		}
		mvwprintw(c->visu.stats.win, y, x, "Player %d", count + 1);
		mvwprintw(c->visu.stats.win, y + 2, x, "Current live: %6d",\
				c->p[count].current_cycle_live);
		mvwprintw(c->visu.stats.win, y + 3, x, "Total live: %8d",\
				c->p[count].total_live);
		++count;
		x = c->visu.stats.size.x - 23;
	}
}

void				fill_stats(t_core *c)
{
	mvwprintw(c->visu.stats.win, 2, 3, "Cycle to die: %4d", c->max_cycle);
	mvwprintw(c->visu.stats.win, 3, 3, "Cycle delta: %5d", CYCLE_DELTA);
	mvwprintw(c->visu.stats.win, 4, 3, "Max check: %7d", MAX_CHECKS);
	mvwprintw(c->visu.stats.win, 5, 3, "Live number: %5d", NBR_LIVE);
	mvwprintw(c->visu.stats.win, 2, c->visu.stats.size.x - 23,\
			"Frame/Second: %6d", c->visu.fps);
	mvwprintw(c->visu.stats.win, 3, c->visu.stats.size.x - 23,\
			"Cycle: %13d", c->total_cycle);
	mvwprintw(c->visu.stats.win, 4, c->visu.stats.size.x - 23,\
			"Current cycle: %5d", c->current_cycle);
	mvwprintw(c->visu.stats.win, 5, c->visu.stats.size.x - 23,\
			"Last decr: %9d", c->last_decr);
	mvwprintw(c->visu.stats.win, 6, c->visu.stats.size.x - 23,\
			"Process: %11d", c->n_process);
	player_stat(c);
}
