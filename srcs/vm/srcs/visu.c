#include "visu.h"

static void	load(t_core *c, t_visu_env *env)
{
	if (env->event_flag & F_RELOAD)
	{
		erase();
		draw_basics(env);
		fill_title(env);
		fill_usages(env);
		fill_stats(c, env);
		fill_states(c, env);
		fill_arena(c, env);
		env->event_flag &= ~F_RELOAD;
	}
	else
	{
		mvwprintw(env->stats.win, 2, 2, "salut");
		fill_stats(c, env);
		// if new instruction
		if (42 == 42) // to handle
			fill_arena(c, env);
	}
}

static void	init_color_pair()
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
}

static void	init(t_visu_env *env)
{
	setlocale(LC_ALL, "");
	ft_bzero(env, sizeof(*env));
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	start_color();
	init_color_pair();
}

static void	refresh_win(t_visu_env *env)
{
	wrefresh(env->title.win);
	wrefresh(env->usages.win);
	wrefresh(env->stats.win);
	wrefresh(env->states.win);
	wrefresh(env->arena.win);
}

#include <stdio.h>

void	print_info(t_core *c) // tmp
{
	dprintf(2, "PROCES -> %d\n", c->n_process);
}

void	visu(t_core *c, bool s)
{
	t_visu_env		env;
	t_coord			tmp;

	if (s)
		init(&env);
	getmaxyx(stdscr, tmp.y, tmp.x);
	if (tmp.y != env.w_size.y || tmp.x != env.w_size.x) {
		env.event_flag |= F_RELOAD;
		env.w_size.y = tmp.y;
		env.w_size.x = tmp.x;
	}
	load(c, &env);
	refresh_win(&env);
	getchar();
	if (!s)
		endwin();
}
