/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_fill_wins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:40:20 by fchanal           #+#    #+#             */
/*   Updated: 2018/06/13 17:21:06 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define NO_SPACE_ENABLE		1

bool				put_byte(t_core *core, t_coord *pos, char *ram, int *index)
{
	int color;

	color = handle_color(core, *index, pos);
	mvwaddch(core->visu.arena.win, pos->y, (pos->x)++, ram[(*index)++]);
	mvwaddch(core->visu.arena.win, pos->y, (pos->x)++, ram[(*index)++]);
	if (color)
		mvwchgat(core->visu.arena.win, pos->y, pos->x - 2, 2,\
				A_STANDOUT, color, NULL);
	if (pos->x < core->visu.arena.size.x - 3)
	{
		mvwaddch(core->visu.arena.win, pos->y, (pos->x)++, ' ');
		return (0);
	}
	else
		return (NO_SPACE_ENABLE);
}

static void			quit(void)
{
	endwin();
	exit(1);
}

void				fill_arena(t_core *core)
{
	char	*ram;
	t_coord	pos;
	int		index;

	if (!(ram = ft_get_hex_memory(core->ram, MEM_SIZE)))
		quit();
	pos.y = 1;
	index = 0;
	while (pos.y < core->visu.arena.size.y - 1)
	{
		pos.x = 3;
		while (1)
		{
			if (index >= MEM_SIZE * 2)
			{
				free(ram);
				return ;
			}
			if (put_byte(core, &pos, ram, &index) == NO_SPACE_ENABLE)
				break ;
		}
		++pos.y;
	}
	free(ram);
}

void				fill_title(t_core *c)
{
	wattrset(c->visu.title.win, COLOR_PAIR(1));
	mvwprintw(c->visu.title.win, 1, c->visu.title.size.x / 2 - 12, "%S", T_1);
	wattrset(c->visu.title.win, COLOR_PAIR(2));
	mvwprintw(c->visu.title.win, 2, c->visu.title.size.x / 2 - 12, "%S", T_2);
	wattrset(c->visu.title.win, COLOR_PAIR(3));
	mvwprintw(c->visu.title.win, 3, c->visu.title.size.x / 2 - 12, "%S", T_3);
	wattrset(c->visu.title.win, COLOR_PAIR(1));
	mvwprintw(c->visu.title.win, 4, 2, "%S", T_4);
}

void				fill_states(t_core *c)
{
	unsigned	x;
	unsigned	count;

	count = 0;
	x = 2;
	while (count < c->player)
	{
		wattrset(c->visu.states.win, COLOR_PAIR(count + 1));
		mvwprintw(c->visu.states.win, 1, x, "%s", H_1);
		mvwprintw(c->visu.states.win, 2, x, "%s", H_2);
		mvwprintw(c->visu.states.win, 3, x, "%s", H_3);
		mvwprintw(c->visu.states.win, 4, x, "%s", H_4);
		mvwprintw(c->visu.states.win, 5, x, "%s", H_5);
		++count;
		x += 12;
	}
}
