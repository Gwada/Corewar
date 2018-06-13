/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:39:51 by fchanal           #+#    #+#             */
/*   Updated: 2018/06/13 17:40:15 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	next_pc(t_core *c)
{
	unsigned	current_pc;
	t_process	*next_process;

	current_pc = c->reverse_ps->pc;
	c->reverse_ps = c->ps;
	next_process = NULL;
	while (c->reverse_ps)
	{
		if (!next_process && c->reverse_ps->pc > current_pc)
			next_process = c->reverse_ps;
		else if (c->reverse_ps->pc > current_pc && c->reverse_ps->pc\
				< next_process->pc)
			next_process = c->reverse_ps;
		c->reverse_ps = c->reverse_ps->next;
	}
	c->reverse_ps = next_process;
}

int		handle_color(t_core *c, int index, t_coord *pos)
{
	if (!c->reverse_ps)
		return (0);
	if ((unsigned)index / 2 >= c->reverse_ps->pc\
			+ c->p[(c->reverse_ps->reg[1] + 1) * -1].prog_size)
	{
		wattrset(c->visu.arena.win, COLOR_PAIR(0));
		next_pc(c);
	}
	else if ((unsigned)index / 2 >= c->reverse_ps->pc && (unsigned)index / 2\
			< c->reverse_ps->pc + c->p[(c->reverse_ps->reg[1] + 1)\
			* -1].prog_size)
	{
		if ((unsigned)index / 2 == c->reverse_ps->pc)
			return (c->reverse_ps->reg[1] * -1);
		else
			wattrset(c->visu.arena.win,\
					COLOR_PAIR(c->reverse_ps->reg[1] * -1));
	}
	return (0);
}
