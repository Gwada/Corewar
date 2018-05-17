#include "corewar.h"

static void	load(t_core *c)
{
	if (c->visu.event_flag & F_RELOAD)
	{
		erase();
		draw_basics(c);
		fill_title(c);
		fill_usages(c);
		fill_stats(c);
		fill_logs(c);
		fill_states(c);
		fill_arena(c);
		c->visu.event_flag &= ~F_RELOAD;
	}
	else
	{
		fill_stats(c);
		// if new instruction
		fill_arena(c);
		// if instruct == live
		// fill_states(c)
	}
}

static void	refresh_win(t_visu_env *env)
{
	wrefresh(env->title.win);
	wrefresh(env->usages.win);
	wrefresh(env->stats.win);
	wrefresh(env->logs.win);
	wrefresh(env->states.win);
	wrefresh(env->arena.win);
}

void	visu(t_core *c)
{
	t_coord			tmp;

	getmaxyx(stdscr, tmp.y, tmp.x);
	if (tmp.y != c->visu.w_size.y || tmp.x != c->visu.w_size.x) {
		c->visu.event_flag |= F_RELOAD;
		c->visu.w_size.y = tmp.y;
		c->visu.w_size.x = tmp.x;
	}
	load(c);
	refresh_win(&c->visu);
	getchar();
	exit(1); //
}
