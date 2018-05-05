/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:42:35 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/04 15:59:10 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void	put_rect(int y, int x)
{
	int		cy;
	int		cx;
	int		count = 0;

	mvaddch(0, 0, ACS_ULCORNER);
	mvaddch(0, x, ACS_URCORNER);
	mvaddch(y, 0, ACS_LLCORNER);
	mvaddch(y, x, ACS_LRCORNER);
	cy = 1;
	while (cy < y)
	{
		mvaddch(cy, 0, ACS_VLINE);
		mvaddch(cy, x, ACS_VLINE);
		++cy;
	}
	cx = 1;
	while (cx < x)
	{
		++count;
		mvaddch(0, cx, ACS_HLINE);
		mvaddch(x, cx, ACS_HLINE);
		++cx;
	}
	mvprintw(35, 30, "\n\n%d\n", count);
}

void	put_grid(int y, int x)
{
	(void)y;
	(void)x;
	/*put_rect(25, 25);*/
	int		i;

	i = 0;
	while (i < y) {
		mvaddch(i, x / 4, '.');
		mvaddch(i, 0, '.');
		mvaddch(i, x - 1, '.');
		i++;
	}
	i = 0;
	while (i < x) {
		mvaddch(0, i, '.');
		mvaddch(y - 1, i, '.');
		if (i < x / 4) {
			mvaddch(y / 8, i, '.');
			mvaddch((int)(double)(y / 2.6), i, '.');
			mvaddch((int)(double)(y / 1.2), i, '.');
		}
		i++;
	}
}

void	reload(bool *stop)
{
	int		y;
	int		x;

	erase();
	getmaxyx(stdscr,y,x);
	put_grid(y, x);
	if (getch() == 'q')
		*stop = true;
}

void	visu()
{
	bool	stop;

	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);

	stop = false;
	while (stop == false) 
		reload(&stop);

	endwin();
}

void	corewar(t_core *c)
{
	visu();
	/*ft_print_mem(c->ram, MEM_SIZE, 64, 0);*/
	(void)c;
}
