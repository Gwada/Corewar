#include "corewar.h"

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

	mvwprintw(c->visu.stats.win, 2, 3, "Cycle to die: %4d", c->max_cycle);
	mvwprintw(c->visu.stats.win, 3, 3, "Cycle delta: %5d", CYCLE_DELTA);
	mvwprintw(c->visu.stats.win, 4, 3, "Max check: %7d", MAX_CHECKS);
	mvwprintw(c->visu.stats.win, 5, 3, "Live number: %5d", NBR_LIVE);

	mvwprintw(c->visu.stats.win, 2, c->visu.stats.size.x - 23, "Frame/Second: %6d", c->visu.fps);
	mvwprintw(c->visu.stats.win, 3, c->visu.stats.size.x - 23, "Cycle: %13d", c->total_cycle);
	mvwprintw(c->visu.stats.win, 4, c->visu.stats.size.x - 23, "Current cycle: %5d", c->current_cycle);
	mvwprintw(c->visu.stats.win, 5, c->visu.stats.size.x - 23, "Last decr: %9d", c->last_decr);
	mvwprintw(c->visu.stats.win, 6, c->visu.stats.size.x - 23, "Process: %11d", c->n_process);

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
		mvwprintw(c->visu.stats.win, y + 1, x, "Process: %11d", c->p[count].total_process);
		mvwprintw(c->visu.stats.win, y + 2, x, "Current live: %6d", c->p[count].current_cycle_live);
		mvwprintw(c->visu.stats.win, y + 3, x, "Total live: %8d", c->p[count].total_live);
		++count;
		x = c->visu.stats.size.x - 23;
	}
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
		exit(1);
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
	wattrset(c->visu.states.win, A_BLINK);
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
