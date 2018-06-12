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
		else if (c->reverse_ps->pc > current_pc && c->reverse_ps->pc < next_process->pc)
			next_process = c->reverse_ps;
		c->reverse_ps = c->reverse_ps->next;
	}
	c->reverse_ps = next_process;
}

int	handle_color(t_core *c, int index, t_coord *pos)
{
	if (!c->reverse_ps)
		return (0);
	if ((unsigned)index / 2 >= c->reverse_ps->pc + c->p[(c->reverse_ps->reg[1] + 1) * -1].prog_size) {

		wattrset(c->visu.arena.win, COLOR_PAIR(0));
		next_pc(c);
	}
	else if ((unsigned)index / 2 >= c->reverse_ps->pc && (unsigned)index / 2 < c->reverse_ps->pc + c->p[(c->reverse_ps->reg[1] + 1) * -1].prog_size)
	{
		if ((unsigned)index / 2 == c->reverse_ps->pc)
			return (c->reverse_ps->reg[1] * -1);
		else
			wattrset(c->visu.arena.win, COLOR_PAIR(c->reverse_ps->reg[1] * -1));
	}
	return (0);
}


void	blink_pc(t_core *c, t_process *p, int new_pc)
{
	t_coord	pos;

	pos.y = (p->pc / ((c->visu.arena.size.x - 3) / 3)) + 1;
	pos.x = (p->pc % ((c->visu.arena.size.x - 3) / 3)) * 3 + 3;
	if (pos.y < c->visu.arena.size.y - 1)
		mvwchgat(c->visu.arena.win, pos.y, pos.x, 2, A_NORMAL, (p->reg[1]) * -1, NULL);
	pos.y = (new_pc / ((c->visu.arena.size.x - 3) / 3)) + 1;
	pos.x = (new_pc % ((c->visu.arena.size.x - 3) / 3)) * 3 + 3;
	if (pos.y < c->visu.arena.size.y - 1)
		mvwchgat(c->visu.arena.win, pos.y, pos.x, 2, A_STANDOUT, (p->reg[1]) * -1, NULL);
}

void	write_on_ram(t_core *c, t_process *p, int index)
{
	t_coord		pos;
	int			count;

	if ((pos.y = (p->pc / ((c->visu.arena.size.x - 3) / 3)) + 1) > c->visu.arena.size.y - 2)
		return ;
	pos.x = (p->pc % ((c->visu.arena.size.x - 3) / 3)) * 3 + 3;
	count = 0;
	while (count < 4)
	{
		if (pos.x > c->visu.arena.size.x - 3)
		{
			if (++pos.y >= c->visu.arena.size.y -1)
				break ;
			pos.x = 3;
		}
		wattrset(c->visu.arena.win, COLOR_PAIR((p->reg[1]) * -1));
		mvwaddch(c->visu.arena.win, pos.y, (pos.x)++, HEX_DIGIT[c->ram[index + count] >> 4]);
		mvwaddch(c->visu.arena.win, pos.y, (pos.x)++, HEX_DIGIT[c->ram[index + count] & 0x0F]);
		++(pos.x);
		++count;
	}
}

void	update_arena(t_core *c, int id, t_process *p, int new_pc, int index)
{
	blink_pc(c, p, new_pc);
	if (id == 3)
	{
		update_states(c, p, index);
		wrefresh(c->visu.states.win);
	}
	else if (id == 4)
		write_on_ram(c, p, index);
	else if (id == 6)
		blink_pc(c, p, index);
	wrefresh(c->visu.arena.win);
}
