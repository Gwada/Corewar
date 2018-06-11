#include "corewar.h"

static void	init_wins_size(t_core *c)
{
	c->visu.title.size.y = c->visu.w_size.y / 8;	
	c->visu.title.size.x = c->visu.w_size.x / 4;

	c->visu.usages.size.y = (int)(double)(c->visu.w_size.y / 7.5);
	c->visu.usages.size.x = c->visu.w_size.x / 4;

	c->visu.stats.size.y = (int)(double)(c->visu.w_size.y / 2.6);
	c->visu.stats.size.x = c->visu.w_size.x / 4;

	c->visu.logs.size.y = (int)(double)(c->visu.w_size.y / 5);
	c->visu.logs.size.x = c->visu.w_size.x / 4;

	c->visu.states.size.y = (int)(double)(c->visu.w_size.y / 6.5);
	c->visu.states.size.x = c->visu.w_size.x / 4;

	c->visu.arena.size.y = c->visu.w_size.y;
	c->visu.arena.size.x = c->visu.w_size.x - (c->visu.w_size.x / 4 + 1);
}

void	draw_basics(t_core *c)
{
	init_wins_size(c);

	if (c->visu.title.win)
		delwin(c->visu.title.win);
	c->visu.title.win = newwin(c->visu.title.size.y, c->visu.title.size.x, 0, 0);

	box(c->visu.title.win, ACS_VLINE, ACS_HLINE);
	wattrset(c->visu.title.win, A_BOLD);
	mvwprintw(c->visu.title.win, 0, c->visu.title.size.x / 2 - 4, " TITLE ");

	if (c->visu.usages.win)
		delwin(c->visu.usages.win);
	c->visu.usages.win = newwin(c->visu.usages.size.y, c->visu.usages.size.x, c->visu.title.size.y, 0);

	box(c->visu.usages.win, ACS_VLINE, ACS_HLINE);
	wattrset(c->visu.usages.win, A_BOLD);
	mvwprintw(c->visu.usages.win, 0, c->visu.usages.size.x / 2 - 4, " USAGE ");

	if (c->visu.stats.win)
		delwin(c->visu.stats.win);
	c->visu.stats.win = newwin(c->visu.stats.size.y, c->visu.stats.size.x, c->visu.title.size.y + c->visu.usages.size.y, 0);

	box(c->visu.stats.win, ACS_VLINE, ACS_HLINE);
	wattrset(c->visu.stats.win, A_BOLD);
	mvwprintw(c->visu.stats.win, 0, c->visu.stats.size.x / 2 - 4, " STATS ");

	if (c->visu.logs.win)
		delwin(c->visu.logs.win);
	c->visu.logs.win = newwin(c->visu.logs.size.y, c->visu.logs.size.x, c->visu.title.size.y + c->visu.usages.size.y + c->visu.stats.size.y, 0);

	box(c->visu.logs.win, ACS_VLINE, ACS_HLINE);
	wattrset(c->visu.logs.win, A_BOLD);
	mvwprintw(c->visu.logs.win, 0, c->visu.logs.size.x / 2 - 4, " LOGS ");

	if (c->visu.states.win)
		delwin(c->visu.states.win);
	c->visu.states.win = newwin(c->visu.states.size.y, c->visu.states.size.x ,c->visu.title.size.y + c->visu.usages.size.y + c->visu.stats.size.y + c->visu.logs.size.y, 0);

	box(c->visu.states.win, ACS_VLINE, ACS_HLINE);
	wattrset(c->visu.states.win, A_BOLD);
	mvwprintw(c->visu.states.win, 0, c->visu.states.size.x / 2 - 4, " STATES ");

	if (c->visu.arena.win)
		delwin(c->visu.arena.win);
	c->visu.arena.win = newwin(c->visu.arena.size.y, c->visu.arena.size.x, 0, c->visu.w_size.x / 4 + 1);

	box(c->visu.arena.win, ACS_VLINE, ACS_HLINE);
	wattrset(c->visu.arena.win, A_BOLD);
	mvwprintw(c->visu.arena.win, 0, c->visu.arena.size.x / 2 - 4, " ARENA ");
}

void	fill_usages(t_core *c)
{
	mvwprintw(c->visu.usages.win, (int)(double)(c->visu.usages.size.y / 2 - 1), 3, "Quit:  'q'");
	mvwprintw(c->visu.usages.win, (int)(double)(c->visu.usages.size.y / 2), 3, "Pause: 'space'");
	mvwprintw(c->visu.usages.win, (int)(double)(c->visu.usages.size.y / 2 - 1), c->visu.usages.size.x - 22, "Frame/Sec:    '+/-'");
	mvwprintw(c->visu.usages.win, (int)(double)(c->visu.usages.size.y / 2), c->visu.usages.size.x - 22, "Step by step:   's'");
}

void	fill_stats(t_core *c)
{
	unsigned count;
	unsigned x;
	unsigned y;

	// align
	mvwprintw(c->visu.stats.win, 2, 3, "Cycle to die: %d", c->max_cycle);
	mvwprintw(c->visu.stats.win, 3, 3, "Cycle delta: %d", CYCLE_DELTA);
	mvwprintw(c->visu.stats.win, 4, 3, "Max check: %d", MAX_CHECKS);
	mvwprintw(c->visu.stats.win, 5, 3, "Live number: %d", NBR_LIVE);

	mvwprintw(c->visu.stats.win, 2, c->visu.stats.size.x - 22, "Frame/Second: %d", c->visu.fps);
	mvwprintw(c->visu.stats.win, 3, c->visu.stats.size.x - 22, "Cycle: %d", c->total_cycle);
	mvwprintw(c->visu.stats.win, 4, c->visu.stats.size.x - 22, "Current cycle: %d", c->current_cycle);
	mvwprintw(c->visu.stats.win, 5, c->visu.stats.size.x - 22, "Last decr: %d", c->last_decr);
	mvwprintw(c->visu.stats.win, 6, c->visu.stats.size.x - 22, "Process: %d", c->n_process);

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
		mvwprintw(c->visu.stats.win, y + 1, x, "Process: %d", c->p[count].total_process);
		mvwprintw(c->visu.stats.win, y + 2, x, "Current live: %d", c->p[count].current_cycle_live);
		mvwprintw(c->visu.stats.win, y + 3, x, "Total live: %d", c->p[count].total_live);
		++count;
		x = c->visu.stats.size.x - 22;
	}
}

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

int	handle_color(t_core *c, int index, t_coord *pos) // index / 2 = byte
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

#define NO_SPACE_ENABLE	1

bool	put_byte(t_core *core, t_coord *pos, char *ram, int *index)
{
	int color;

	color = handle_color(core, *index, pos);
	mvwaddch(core->visu.arena.win, pos->y, (pos->x)++, ram[(*index)++]);
	mvwaddch(core->visu.arena.win, pos->y, (pos->x)++, ram[(*index)++]);
	if (color)
		mvwchgat(core->visu.arena.win, pos->y, pos->x - 2, 2, A_STANDOUT, color, NULL);
	if (pos->x < core->visu.arena.size.x - 3) {
		mvwaddch(core->visu.arena.win, pos->y, (pos->x)++, ' ');
		return (0);
	}
	else
		return (NO_SPACE_ENABLE);
}

void	fill_arena(t_core *core)
{
	char	*ram;
	t_coord	pos;
	int		index;

	if (!(ram = ft_get_hex_memory(core->ram, MEM_SIZE)))
		ft_exit_alloc_failure();
	pos.y = 1;
	index = 0;
	while (pos.y < core->visu.arena.size.y - 1) {
		pos.x = 3;
		while (1) {
			if (index >= MEM_SIZE * 2) {
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

void	fill_title(t_core *c)
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

void	fill_logs(t_core *c)
{
	(void)c;
}

void	fill_states(t_core *c)
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

void	update_states(t_core *c, t_process *ps, int index)
{
	int		x;

	x = 2 + 12 * (index - 1);
	wattrset(c->visu.states.win, A_BLINK); // up flashing
	mvwprintw(c->visu.states.win, 1, x, "%s", H_1);
	mvwprintw(c->visu.states.win, 2, x, "%s", H_2);
	mvwprintw(c->visu.states.win, 3, x, "%s", H_3);
	mvwprintw(c->visu.states.win, 4, x, "%s", H_4);
	mvwprintw(c->visu.states.win, 5, x, "%s", H_5);
	wrefresh(c->visu.states.win);
	usleep(1000 * 50);
	wattrset(c->visu.states.win, COLOR_PAIR((x - 2) / 12 + 1));
	mvwprintw(c->visu.states.win, 1, x, "%s", H_1);
	mvwprintw(c->visu.states.win, 2, x, "%s", H_2);
	mvwprintw(c->visu.states.win, 3, x, "%s", H_3);
	mvwprintw(c->visu.states.win, 4, x, "%s", H_4);
	mvwprintw(c->visu.states.win, 5, x, "%s", H_5);
}

void	blink_pc(t_core *c, t_process *p, int new_pc)
{ 
	mvwchgat(c->visu.arena.win, (p->pc / ((c->visu.arena.size.x - 3) / 3)) + 1, (p->pc % ((c->visu.arena.size.x - 3) / 3)) * 3 + 3, 2, A_NORMAL, (p->reg[1]) * -1, NULL);
	mvwchgat(c->visu.arena.win, (new_pc / ((c->visu.arena.size.x - 3) / 3)) + 1, (new_pc % ((c->visu.arena.size.x - 3) / 3)) * 3 + 3, 2, A_STANDOUT, (p->reg[1]) * -1, NULL);
}

void	write_on_ram(t_core *c, t_process *p, int index)
{
	t_coord		pos;
	int			count;

	pos.y = (p->pc / ((c->visu.arena.size.x - 3) / 3)) + 1;
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
