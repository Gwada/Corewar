#include "corewar.h"

#define HEX "0123456789ABCDEF"

char	*ft_get_hex_memory(void *m, size_t mem_size) // mem_size en octet
{
	char	*ret;
	char	*rusher;
	uint8_t	*tmp;

	if (!m || !(ret = (char*)malloc(mem_size * 2)))
		return (NULL);
	rusher = ret;
	tmp = (uint8_t*)m;
	while (mem_size)
	{
		*rusher++ = HEX[*tmp >> 4];
		*rusher++ = HEX[*tmp & 0x0F];
		++tmp;
		--mem_size;
	}
	return (ret);
}

void	draw_basics(t_env *env)
{
	int		row, col;

	erase();
	env->w.title = newwin(env->w_coord.y / 8, env->w_coord.x / 4, 0, 0);

	box(env->w.title, ACS_VLINE, ACS_HLINE);
	getmaxyx(env->w.title, row, col);
	wattrset(env->w.title, A_BOLD);
	mvwprintw(env->w.title, 0, col / 2 - 4, " TITLE ");

	env->w.usages = newwin((int)(double)(env->w_coord.y / 3.5), env->w_coord.x / 4, env->w_coord.y / 8, 0);

	box(env->w.usages, ACS_VLINE, ACS_HLINE);
	getmaxyx(env->w.usages, row, col);
	wattrset(env->w.usages, A_BOLD);
	mvwprintw(env->w.usages, 0, col / 2 - 4, " USAGE ");

	env->w.stats = newwin((int)(double)(env->w_coord.y / 2.2), env->w_coord.x / 4, (int)(double)(env->w_coord.y / 3.5) + env->w_coord.y / 8, 0);

	box(env->w.stats, ACS_VLINE, ACS_HLINE);
	getmaxyx(env->w.stats, row, col);
	wattrset(env->w.stats, A_BOLD);
	mvwprintw(env->w.stats, 0, col / 2 - 4, " STATS ");

	env->w.states = newwin((int)(double)(env->w_coord.y / 6.5), env->w_coord.x / 4, (int)(double)(env->w_coord.y / 3.5) + env->w_coord.y / 8 + (int)(double)(env->w_coord.y / 2.2), 0);

	box(env->w.states, ACS_VLINE, ACS_HLINE);
	getmaxyx(env->w.states, row, col);
	wattrset(env->w.states, A_BOLD);
	mvwprintw(env->w.states, 0, col / 2 - 4, " STATES ");

	env->w.arena = newwin(env->w_coord.y, env->w_coord.x - (env->w_coord.x / 4 + 1), 0, env->w_coord.x / 4 + 1);

	box(env->w.arena, ACS_VLINE, ACS_HLINE);
	getmaxyx(env->w.arena, row, col);
	wattrset(env->w.arena, A_BOLD);
	mvwprintw(env->w.arena, 0, col / 2 - 4, " ARENA ");

	wrefresh(env->w.title);
	wrefresh(env->w.usages);
	wrefresh(env->w.stats);
	wrefresh(env->w.states);
	wrefresh(env->w.arena);
	env->event_flag &= ~F_RELOAD;
}

void	fill_arena(t_core *c, t_env *env) // make proper
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
				wrefresh(env->w.arena);
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
	wrefresh(env->w.arena);
}

void	fill_title(t_env *env)
{
	t_coord c;

	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	getmaxyx(env->w.title, c.y, c.x);
	wattrset(env->w.title, COLOR_PAIR(1));
	mvwprintw(env->w.title, 1, c.x / 2 - 12, "%S", T_1);
	wattrset(env->w.title, COLOR_PAIR(2));
	mvwprintw(env->w.title, 2, c.x / 2 - 12, "%S", T_2);
	wattrset(env->w.title, COLOR_PAIR(3));
	mvwprintw(env->w.title, 3, c.x / 2 - 12, "%S", T_3);
	wattrset(env->w.title, COLOR_PAIR(1));
	mvwprintw(env->w.title, 4, 2, "%S", T_4);
	wrefresh(env->w.title);
}

void	fill_states(t_core *c, t_env *env)
{
	int			x;
	unsigned	count;

	count = 0;
	x = 2;
	init_pair(1, COLOR_P1, COLOR_BLACK);
	init_pair(2, COLOR_P2, COLOR_BLACK);
	init_pair(3, COLOR_P3, COLOR_BLACK);
	init_pair(4, COLOR_P4, COLOR_BLACK);
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
	wrefresh(env->w.states);
}

void	reload(t_core *c, t_env *env)
{
	if (env->event_flag & F_RELOAD)
		draw_basics(env);
	fill_title(env);
	fill_states(c, env);
	fill_arena(c, env);
	getchar();
}
	void	visu(t_core *c)
{
	t_env		env;
	char		ch;
	int			y;
	int			x;

	setlocale(LC_ALL, "");
	bzero(&env, sizeof(env)); // replace
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	start_color();
	while (1) {
		getmaxyx(stdscr, y, x);
		if (env.w_coord.y != y || env.w_coord.x != x)
			env.event_flag |= F_RELOAD;
		env.w_coord.y = y;
	env.w_coord.x = x;
		reload(c, &env);
		ch = getch();
		if (ch == 'q')
			break ;
	}
	endwin();
}
