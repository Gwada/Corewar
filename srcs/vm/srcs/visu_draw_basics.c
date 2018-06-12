#include "corewar.h"

static void	init_wins_size(t_core *c)
{
	c->visu.title.size.y = c->visu.w_size.y / 8;	
	c->visu.title.size.x = c->visu.w_size.x / 4;

	c->visu.usages.size.y = (int)(double)(c->visu.w_size.y / 7.5);
	c->visu.usages.size.x = c->visu.w_size.x / 4;

	c->visu.stats.size.y = (int)(double)(c->visu.w_size.y / 2);
	c->visu.stats.size.x = c->visu.w_size.x / 4;

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
	mvwprintw(c->visu.title.win, 0, c->visu.title.size.x / 2 - 4, " TITLE ");

	if (c->visu.usages.win)
		delwin(c->visu.usages.win);
	c->visu.usages.win = newwin(c->visu.usages.size.y, c->visu.usages.size.x, c->visu.title.size.y, 0);

	box(c->visu.usages.win, ACS_VLINE, ACS_HLINE);
	mvwprintw(c->visu.usages.win, 0, c->visu.usages.size.x / 2 - 4, " USAGE ");

	if (c->visu.stats.win)
		delwin(c->visu.stats.win);
	c->visu.stats.win = newwin(c->visu.stats.size.y, c->visu.stats.size.x, c->visu.title.size.y + c->visu.usages.size.y, 0);

	box(c->visu.stats.win, ACS_VLINE, ACS_HLINE);
	mvwprintw(c->visu.stats.win, 0, c->visu.stats.size.x / 2 - 4, " STATS ");

	if (c->visu.states.win)
		delwin(c->visu.states.win);
	c->visu.states.win = newwin(c->visu.states.size.y, c->visu.states.size.x ,c->visu.title.size.y + c->visu.usages.size.y + c->visu.stats.size.y, 0);

	box(c->visu.states.win, ACS_VLINE, ACS_HLINE);
	mvwprintw(c->visu.states.win, 0, c->visu.states.size.x / 2 - 4, " STATES ");

	if (c->visu.arena.win)
		delwin(c->visu.arena.win);
	c->visu.arena.win = newwin(c->visu.arena.size.y, c->visu.arena.size.x, 0, c->visu.w_size.x / 4 + 1);

	box(c->visu.arena.win, ACS_VLINE, ACS_HLINE);
	mvwprintw(c->visu.arena.win, 0, c->visu.arena.size.x / 2 - 4, " ARENA ");
}


