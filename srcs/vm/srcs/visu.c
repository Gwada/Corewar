#include "visu.h"

static void	load(t_core *c, t_visu_env *env)
{
	draw_basics(env);
	fill_title(env);
	fill_states(c, env);
	fill_arena(c, env);
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
	wrefresh(env->w.title);
	wrefresh(env->w.usages);
	wrefresh(env->w.stats);
	wrefresh(env->w.states);
	wrefresh(env->w.arena);
}

#include <stdio.h>

void	print_info(t_core *c) // tmp
{
	(void)c;
	/*printf("%d\n", c->)*/
}

void	visu(t_core *c)
{
	t_visu_env		env;

	init(&env);
	getmaxyx(stdscr, env.w_size.y, env.w_size.x);
	load(c, &env);
	refresh_win(&env);
	getchar();
	endwin();
}
