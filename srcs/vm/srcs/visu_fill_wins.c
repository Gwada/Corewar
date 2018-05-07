#include "visu.h"

void	draw_basics(t_visu_env *env)
{
	int		row, col;

	env->w.title = newwin(env->w_size.y / 8, env->w_size.x / 4, 0, 0);

	box(env->w.title, ACS_VLINE, ACS_HLINE);
	getmaxyx(env->w.title, row, col);
	wattrset(env->w.title, A_BOLD);
	mvwprintw(env->w.title, 0, col / 2 - 4, " TITLE ");

	if (env->w.usages)
		delwin(env->w.usages);
	env->w.usages = newwin((int)(double)(env->w_size.y / 3.5), env->w_size.x / 4, env->w_size.y / 8, 0);

	box(env->w.usages, ACS_VLINE, ACS_HLINE);
	getmaxyx(env->w.usages, row, col);
	wattrset(env->w.usages, A_BOLD);
	mvwprintw(env->w.usages, 0, col / 2 - 4, " USAGE ");

	if (env->w.stats)
		delwin(env->w.stats);
	env->w.stats = newwin((int)(double)(env->w_size.y / 2.2), env->w_size.x / 4, (int)(double)(env->w_size.y / 3.5) + env->w_size.y / 8, 0);

	box(env->w.stats, ACS_VLINE, ACS_HLINE);
	getmaxyx(env->w.stats, row, col);
	wattrset(env->w.stats, A_BOLD);
	mvwprintw(env->w.stats, 0, col / 2 - 4, " STATS ");

	if (env->w.states)
		delwin(env->w.states);
	env->w.states = newwin((int)(double)(env->w_size.y / 6.5), env->w_size.x / 4, (int)(double)(env->w_size.y / 3.5) + env->w_size.y / 8 + (int)(double)(env->w_size.y / 2.2), 0);

	box(env->w.states, ACS_VLINE, ACS_HLINE);
	getmaxyx(env->w.states, row, col);
	wattrset(env->w.states, A_BOLD);
	mvwprintw(env->w.states, 0, col / 2 - 4, " STATES ");

	if (env->w.arena)
		delwin(env->w.arena);
	env->w.arena = newwin(env->w_size.y, env->w_size.x - (env->w_size.x / 4 + 1), 0, env->w_size.x / 4 + 1);

	box(env->w.arena, ACS_VLINE, ACS_HLINE);
	getmaxyx(env->w.arena, row, col);
	wattrset(env->w.arena, A_BOLD);
	mvwprintw(env->w.arena, 0, col / 2 - 4, " ARENA ");
}

void	fill_arena(t_core *c, t_visu_env *env) // make proper
{
	int		y, x;
	char	*m;
	uint8_t	space;
	uint32_t	index;

	if (!(m = ft_get_hex_memory(c->ram, MEM_SIZE)))
		return ;
	getmaxyx(env->w.arena, y, x);
	space = 0;
	index = 0;
	for (int i = 1 ; i < y - 1 ; ++i) {
		for (int j = 3 ; j < x - 3 ; ++j) {
			if (index == MEM_SIZE * 2)
			{
				free(m);
				return ;
			}
			if (space == 2)
			{
				if (j == x - 5)
					break ;
				else if (j == 3)
				{
					mvwaddch(env->w.arena, i, j, m[index++]);
					space = 1;
				}
				else
				{
					mvwaddch(env->w.arena, i, j, ' ');
					space = 0;
				}
			}
			else
			{
				mvwaddch(env->w.arena, i, j, m[index++]);
				++space;
			}
		}
	}
	free(m);
}

void	fill_title(t_visu_env *env)
{
	t_coord c;

	getmaxyx(env->w.title, c.y, c.x);
	wattrset(env->w.title, COLOR_PAIR(1));
	mvwprintw(env->w.title, 1, c.x / 2 - 12, "%S", T_1);
	wattrset(env->w.title, COLOR_PAIR(2));
	mvwprintw(env->w.title, 2, c.x / 2 - 12, "%S", T_2);
	wattrset(env->w.title, COLOR_PAIR(3));
	mvwprintw(env->w.title, 3, c.x / 2 - 12, "%S", T_3);
	wattrset(env->w.title, COLOR_PAIR(1));
	mvwprintw(env->w.title, 4, 2, "%S", T_4);
}

void	fill_states(t_core *c, t_visu_env *env)
{
	int			x;
	unsigned	count;

	count = 0;
	x = 2;
	while (count < c->player)
	{
		wattrset(env->w.states, COLOR_PAIR(count + 1));
		mvwprintw(env->w.states, 1, x, "%s", H_1);
		mvwprintw(env->w.states, 2, x, "%s", H_2);
		mvwprintw(env->w.states, 3, x, "%s", H_3);
		mvwprintw(env->w.states, 4, x, "%s", H_4);
		mvwprintw(env->w.states, 5, x, "%s", H_5);
		++count;
		x += 12;
	}
}
