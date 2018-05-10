#include "visu.h"

void	init_wins_size(t_visu_env *env)
{
	env->title.size.y = env->w_size.y / 8;	
	env->title.size.x = env->w_size.x / 4;

	env->usages.size.y = (int)(double)(env->w_size.y / 3.5);
	env->usages.size.x = env->w_size.x / 4;

	env->stats.size.y = (int)(double)(env->w_size.y / 2.2);
	env->stats.size.x = env->w_size.x / 4;

	env->states.size.y = (int)(double)(env->w_size.y / 6.5);
	env->states.size.x = env->w_size.x / 4;

	env->arena.size.y = env->w_size.y;
	env->arena.size.x = env->w_size.x - (env->w_size.x / 4 + 1);
}

void	draw_basics(t_visu_env *env)
{
	init_wins_size(env);

	if (env->title.win)
		delwin(env->title.win);
	env->title.win = newwin(env->title.size.y, env->title.size.x, 0, 0);

	box(env->title.win, ACS_VLINE, ACS_HLINE);
	wattrset(env->title.win, A_BOLD);
	mvwprintw(env->title.win, 0, env->title.size.x / 2 - 4, " TITLE ");

	if (env->usages.win)
		delwin(env->usages.win);
	env->usages.win = newwin(env->usages.size.y, env->usages.size.x, env->title.size.y, 0);

	box(env->usages.win, ACS_VLINE, ACS_HLINE);
	wattrset(env->usages.win, A_BOLD);
	mvwprintw(env->usages.win, 0, env->usages.size.x / 2 - 4, " USAGE ");

	if (env->stats.win)
		delwin(env->stats.win);
	env->stats.win = newwin(env->stats.size.y, env->stats.size.x, env->title.size.y + env->usages.size.y, 0);

	box(env->stats.win, ACS_VLINE, ACS_HLINE);
	wattrset(env->stats.win, A_BOLD);
	mvwprintw(env->stats.win, 0, env->stats.size.x / 2 - 4, " STATS ");

	if (env->states.win)
		delwin(env->states.win);
	env->states.win = newwin(env->states.size.y, env->states.size.x ,env->title.size.y + env->usages.size.y + env->stats.size.y,0);

	box(env->states.win, ACS_VLINE, ACS_HLINE);
	wattrset(env->states.win, A_BOLD);
	mvwprintw(env->states.win, 0, env->states.size.x / 2 - 4, " STATES ");

	if (env->arena.win)
		delwin(env->arena.win);
	env->arena.win = newwin(env->arena.size.y, env->arena.size.x, 0, env->w_size.x / 4 + 1);

	box(env->arena.win, ACS_VLINE, ACS_HLINE);
	wattrset(env->arena.win, A_BOLD);
	mvwprintw(env->arena.win, 0, env->arena.size.x / 2 - 4, " ARENA ");
}

void	fill_usages(t_visu_env *env)
{
	(void)env;
}

void	fill_stats(t_core *c, t_visu_env *env)
{
	(void)c; (void)env;
}

void	fill_arena(t_core *c, t_visu_env *env) // make proper
{
	char		*m;
	uint8_t		space;
	uint32_t	index;

	if (!(m = ft_get_hex_memory(c->ram, MEM_SIZE)))
		ft_exit_alloc_failure();
	space = 0;
	index = 0;
	for (int i = 1 ; i < env->arena.size.y - 1 ; ++i) {
		for (int j = 3 ; j < env->arena.size.x - 3 ; ++j) {
			if (index == MEM_SIZE * 2)
			{
				free(m);
				return ;
			}
			if (space == 2)
			{
				if (j == env->arena.size.x - 5)
					break ;
				else if (j == 3)
				{
					mvwaddch(env->arena.win, i, j, m[index++]);
					space = 1;
				}
				else
				{
					mvwaddch(env->arena.win, i, j, ' ');
					space = 0;
				}
			}
			else
			{
				mvwaddch(env->arena.win, i, j, m[index++]);
				++space;
			}
		}
	}
	free(m);
}

void	fill_title(t_visu_env *env)
{
	wattrset(env->title.win, COLOR_PAIR(1));
	mvwprintw(env->title.win, 1, env->title.size.x / 2 - 12, "%S", T_1);
	wattrset(env->title.win, COLOR_PAIR(2));
	mvwprintw(env->title.win, 2, env->title.size.x / 2 - 12, "%S", T_2);
	wattrset(env->title.win, COLOR_PAIR(3));
	mvwprintw(env->title.win, 3, env->title.size.x / 2 - 12, "%S", T_3);
	wattrset(env->title.win, COLOR_PAIR(1));
	mvwprintw(env->title.win, 4, 2, "%S", T_4);
}

void	fill_states(t_core *c, t_visu_env *env)
{
	unsigned	x;
	unsigned	count;

	count = 0;
	x = 2;
	while (count < c->player)
	{
		wattrset(env->states.win, COLOR_PAIR(count + 1));
		mvwprintw(env->states.win, 1, x, "%s", H_1);
		mvwprintw(env->states.win, 2, x, "%s", H_2);
		mvwprintw(env->states.win, 3, x, "%s", H_3);
		mvwprintw(env->states.win, 4, x, "%s", H_4);
		mvwprintw(env->states.win, 5, x, "%s", H_5);
		++count;
		x += 12;
	}
}
