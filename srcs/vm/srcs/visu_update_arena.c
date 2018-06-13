/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_update_arena.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:22:51 by fchanal           #+#    #+#             */
/*   Updated: 2018/06/13 18:37:27 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				blink_pc(t_core *c, t_process *p, unsigned new_pc)
{
	t_coord			pos;
	unsigned		color;

	color = p->reg[0];
	if (color > c->player)
		color = 5;
	pos.y = (p->pc / ((c->visu.arena.size.x - 3) / 3)) + 1;
	pos.x = (p->pc % ((c->visu.arena.size.x - 3) / 3)) * 3 + 3;
	if (pos.y < c->visu.arena.size.y - 1)
		mvwchgat(c->visu.arena.win, pos.y, pos.x, 2, A_NORMAL, color, NULL);
	pos.y = (new_pc / ((c->visu.arena.size.x - 3) / 3)) + 1;
	pos.x = (new_pc % ((c->visu.arena.size.x - 3) / 3)) * 3 + 3;
	if (pos.y < c->visu.arena.size.y - 1)
		mvwchgat(c->visu.arena.win, pos.y, pos.x, 2, A_STANDOUT, color, NULL);
}

static void			set_color(unsigned *color, unsigned player_nb, t_process *p)
{
	*color = p->reg[0];
	if (*color > player_nb)
		*color = 5;
}

void				write_on_ram(t_core *c, t_process *p, unsigned index)
{
	t_coord		pos;
	int			count;
	unsigned	color;

	set_color(&color, c->player, p);
	if ((pos.y = (index / ((c->visu.arena.size.x - 3) / 3)) + 1) >\
			c->visu.arena.size.y - 2)
		return ;
	pos.x = (index % ((c->visu.arena.size.x - 3) / 3)) * 3 + 3;
	count = 0;
	while (count < 4)
	{
		if (pos.x > c->visu.arena.size.x - 3)
		{
			if (++pos.y >= c->visu.arena.size.y - 1)
				break ;
			pos.x = 3;
		}
		wattrset(c->visu.arena.win, COLOR_PAIR(color));
		mvwaddch(c->visu.arena.win, pos.y, (pos.x)++, \
				HEX_DIGIT[c->ram[index + count] >> 4]);
		mvwaddch(c->visu.arena.win, pos.y, (pos.x)++, \
				HEX_DIGIT[c->ram[index + count++] & 0x0F]);
		++(pos.x);
	}
}

void				update_arena(t_core *c, int id, t_process *p, uint64_t t)
{
	blink_pc(c, p, t >> 32);
	if (id == 3)
	{
		update_states(c, p, t & YZ);
		wrefresh(c->visu.states.win);
	}
	else if (id == 4)
		write_on_ram(c, p, t & YZ);
	else if (id == 6)
		blink_pc(c, p, t & YZ);
	wrefresh(c->visu.arena.win);
}
