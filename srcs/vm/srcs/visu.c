#include "corewar.h"

static void	load(t_core *c)
{
	if (c->visu.event_flag & F_RELOAD) {
		werase(c->visu.title.win);
		werase(c->visu.usages.win);
		werase(c->visu.stats.win);
		werase(c->visu.logs.win);
		werase(c->visu.states.win);
		werase(c->visu.arena.win);
		erase();
		draw_basics(c);
		fill_title(c);
		fill_usages(c);
		fill_arena(c);
		refresh();
		wrefresh(c->visu.title.win);
		wrefresh(c->visu.usages.win);
		c->visu.event_flag &= ~F_RELOAD;
	}
	// update panel
	
	fill_stats(c);
	fill_logs(c);
	fill_states(c);
	wrefresh(c->visu.stats.win);
	wrefresh(c->visu.logs.win);
	wrefresh(c->visu.states.win);
	wrefresh(c->visu.arena.win);
}


static void	refresh_win(t_core *c)
{
	(void)c;
}

static void handle_event(t_core *c, char cs)
{
	(void)c;
	if (cs == 'q')
		exit(0);
	else if (cs == ' ')
		c->visu.event_flag |= F_PAUSE;
	else if (cs == 's')
		c->visu.event_flag |= F_SKURT;
	else if (cs == '+') {
		if (c->visu.fps == 0)
			c->visu.fps = 5;
		else
			++c->visu.fps;
	}
	else if (cs == '-') {
		if (c->visu.fps == 0)
			c->visu.fps = 5;
		else
			--c->visu.fps;
	}
}

void	visu(t_core *c)
{
	getmaxyx(stdscr, c->visu.w_size.y, c->visu.w_size.x);
	load(c);
	refresh_win(c);
	handle_event(c, getch());
	if (c->visu.event_flag & F_PAUSE) {
		getchar();
		c->visu.event_flag &= ~F_PAUSE;
	}
	if (c->visu.event_flag & F_SKURT) {
		if (getchar() != 's')
		c->visu.event_flag &= ~F_SKURT;
	}
	if (c->visu.fps != 0)
		usleep(1000 / c->visu.fps * 1000);
}
