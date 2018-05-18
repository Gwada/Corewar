#include "corewar.h"

static void	init_wins_size(t_core *c)
{
	c->visu.title.size.y = c->visu.w_size.y / 8;	
	c->visu.title.size.x = c->visu.w_size.x / 4;

	c->visu.usages.size.y = (int)(double)(c->visu.w_size.y / 7.5);
	c->visu.usages.size.x = c->visu.w_size.x / 4;

	c->visu.stats.size.y = (int)(double)(c->visu.w_size.y / 2.6);
	c->visu.stats.size.x = c->visu.w_size.x / 4;

	c->visu.logs.size.y = (int)(double)(c->visu.w_size.y / 14);
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
	mvwprintw(c->visu.stats.win, 1, 3, "Cycle to die: %d", c->max_cycle);
	mvwprintw(c->visu.stats.win, 2, 3, "Cycle delta: %d", CYCLE_DELTA);
	mvwprintw(c->visu.stats.win, 3, 3, "Max check: %d", MAX_CHECKS);
	mvwprintw(c->visu.stats.win, 4, 3, "Live number: %d", NBR_LIVE);

	mvwprintw(c->visu.stats.win, 1, c->visu.stats.size.x - 19, "Frame/Second: %d", c->visu.frame_second);
	mvwprintw(c->visu.stats.win, 2, c->visu.stats.size.x - 19, "Cycle: %d", c->total_cycle);
	mvwprintw(c->visu.stats.win, 3, c->visu.stats.size.x - 19, "Current cycle: %d", c->current_cycle);
	mvwprintw(c->visu.stats.win, 4, c->visu.stats.size.x - 19, "Last decr: %d", c->last_decr);
	mvwprintw(c->visu.stats.win, 5, c->visu.stats.size.x - 19, "Process: %d", c->n_process);

	count = 0;
	x = 3;
	y = 8;
	while (count < c->player)
	{
		if (count == 2)
		{
			x = 3;
			y += 6;
		}
		mvwprintw(c->visu.stats.win, y, x, "Player %d", count + 1);
		mvwprintw(c->visu.stats.win, y + 1, x, "Process: %d", c->p[count].total_process);
		mvwprintw(c->visu.stats.win, y + 2, x, "Current live: %d", c->p[count].current_cycle_live);
		mvwprintw(c->visu.stats.win, y + 3, x, "Total live: %d", c->p[count].total_live);
		++count;
		x += 14;
	}
}

void	fill_arena(t_core *c) // make proper
{
	char		*m;
	uint8_t		space;
	uint32_t	index;

	if (!(m = ft_get_hex_memory(c->ram, MEM_SIZE)))
		ft_exit_alloc_failure();
	space = 0;
	index = 0;
	for (int i = 1 ; i < c->visu.arena.size.y - 1 ; ++i) {
		for (int j = 3 ; j < c->visu.arena.size.x - 3 ; ++j) {
			if (index == MEM_SIZE * 2)
			{
				free(m);
				return ;
			}
			if (space == 2)
			{
				if (j == c->visu.arena.size.x - 5)
					break ;
				else if (j == 3)
				{
					mvwaddch(c->visu.arena.win, i, j, m[index++]);
					space = 1;
				}
				else
				{
					mvwaddch(c->visu.arena.win, i, j, ' ');
					space = 0;
				}
			}
			else
			{
				mvwaddch(c->visu.arena.win, i, j, m[index++]);
				++space;
			}
		}
	}
	free(m);
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
	/*c->visu.arena.size.y = c->visu.w_size.y;*/
	/*c->visu.arena.size.x = c->visu.w_size.x - (c->visu.w_size.x / 4 + 1);*/
/*}*/

/*void	draw_basics(t_core *c)*/
/*{*/
	/*init_wins_size(c);*/

	/*if (c->visu.title.win)*/
		/*delwin(c->visu.title.win);*/
	/*c->visu.title.win = newwin(c->visu.title.size.y, c->visu.title.size.x, 0, 0);*/

	/*box(c->visu.title.win, ACS_VLINE, ACS_HLINE);*/
	/*wattrset(c->visu.title.win, A_BOLD);*/
	/*mvwprintw(c->visu.title.win, 0, c->visu.title.size.x / 2 - 4, " TITLE ");*/

	/*if (c->visu.usages.win)*/
		/*delwin(c->visu.usages.win);*/
	/*c->visu.usages.win = newwin(c->visu.usages.size.y, c->visu.usages.size.x, c->visu.title.size.y, 0);*/

	/*box(c->visu.usages.win, ACS_VLINE, ACS_HLINE);*/
	/*wattrset(c->visu.usages.win, A_BOLD);*/
	/*mvwprintw(c->visu.usages.win, 0, c->visu.usages.size.x / 2 - 4, " USAGE ");*/

	/*if (c->visu.stats.win)*/
		/*delwin(c->visu.stats.win);*/
	/*c->visu.stats.win = newwin(c->visu.stats.size.y, c->visu.stats.size.x, c->visu.title.size.y + c->visu.usages.size.y, 0);*/

	/*box(c->visu.stats.win, ACS_VLINE, ACS_HLINE);*/
	/*wattrset(c->visu.stats.win, A_BOLD);*/
	/*mvwprintw(c->visu.stats.win, 0, c->visu.stats.size.x / 2 - 4, " STATS ");*/

	/*if (c->visu.states.win)*/
		/*delwin(c->visu.states.win);*/
	/*c->visu.states.win = newwin(c->visu.states.size.y, c->visu.states.size.x ,c->visu.title.size.y + c->visu.usages.size.y + c->visu.stats.size.y,0);*/

	/*box(c->visu.states.win, ACS_VLINE, ACS_HLINE);*/
	/*wattrset(c->visu.states.win, A_BOLD);*/
	/*mvwprintw(c->visu.states.win, 0, c->visu.states.size.x / 2 - 4, " STATES ");*/

	/*if (c->visu.arena.win)*/
		/*delwin(c->visu.arena.win);*/
	/*c->visu.arena.win = newwin(c->visu.arena.size.y, c->visu.arena.size.x, 0, c->visu.w_size.x / 4 + 1);*/

	/*box(c->visu.arena.win, ACS_VLINE, ACS_HLINE);*/
	/*wattrset(c->visu.arena.win, A_BOLD);*/
	/*mvwprintw(c->visu.arena.win, 0, c->visu.arena.size.x / 2 - 4, " ARENA ");*/
/*}*/

/*void	fill_usages(t_core *c)*/
/*{*/
	/*(void)c;*/
/*}*/

/*void	fill_stats(t_core *c)*/
/*{*/
	/*(void)c;*/
/*}*/

/*void	fill_arena(t_core *c) // make proper*/
/*{*/
	/*char		*m;*/
	/*uint8_t		space;*/
	/*uint32_t	index;*/

	/*if (!(m = ft_get_hex_memory(c->ram, MEM_SIZE)))*/
		/*ft_exit_alloc_failure();*/
	/*space = 0;*/
	/*index = 0;*/
	/*for (int i = 1 ; i < c->visu.arena.size.y - 1 ; ++i) {*/
		/*for (int j = 3 ; j < c->visu.arena.size.x - 3 ; ++j) {*/
			/*if (index == MEM_SIZE * 2)*/
			/*{*/
				/*free(m);*/
				/*return ;*/
			/*}*/
			/*if (space == 2)*/
			/*{*/
				/*if (j == c->visu.arena.size.x - 5)*/
					/*break ;*/
				/*else if (j == 3)*/
				/*{*/
					/*mvwaddch(c->visu.arena.win, i, j, m[index++]);*/
					/*space = 1;*/
				/*}*/
				/*else*/
				/*{*/
					/*mvwaddch(c->visu.arena.win, i, j, ' ');*/
					/*space = 0;*/
				/*}*/
			/*}*/
			/*else*/
			/*{*/
				/*mvwaddch(c->visu.arena.win, i, j, m[index++]);*/
				/*++space;*/
			/*}*/
		/*}*/
	/*}*/
	/*free(m);*/
/*}*/

/*void	fill_title(t_core *c)*/
/*{*/
	/*wattrset(c->visu.title.win, COLOR_PAIR(1));*/
	/*mvwprintw(c->visu.title.win, 1, c->visu.title.size.x / 2 - 12, "%S", T_1);*/
	/*wattrset(c->visu.title.win, COLOR_PAIR(2));*/
	/*mvwprintw(c->visu.title.win, 2, c->visu.title.size.x / 2 - 12, "%S", T_2);*/
	/*wattrset(c->visu.title.win, COLOR_PAIR(3));*/
	/*mvwprintw(c->visu.title.win, 3, c->visu.title.size.x / 2 - 12, "%S", T_3);*/
	/*wattrset(c->visu.title.win, COLOR_PAIR(1));*/
	/*mvwprintw(c->visu.title.win, 4, 2, "%S", T_4);*/
/*}*/

/*void	fill_states(t_core *c)*/
/*{*/
	/*unsigned	x;*/
	/*unsigned	count;*/

	/*count = 0;*/
	/*x = 2;*/
	/*while (count < c->player)*/
	/*{*/
		/*wattrset(c->visu.states.win, COLOR_PAIR(count + 1));*/
		/*mvwprintw(c->visu.states.win, 1, x, "%s", H_1);*/
		/*mvwprintw(c->visu.states.win, 2, x, "%s", H_2);*/
		/*mvwprintw(c->visu.states.win, 3, x, "%s", H_3);*/
		/*mvwprintw(c->visu.states.win, 4, x, "%s", H_4);*/
		/*mvwprintw(c->visu.states.win, 5, x, "%s", H_5);*/
		/*++count;*/
		/*x += 12;*/
	/*}*/
/*}*/
