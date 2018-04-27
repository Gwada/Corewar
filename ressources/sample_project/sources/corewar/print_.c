/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <brigoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:44:40 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/25 19:16:43 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			print_dump(void)
{
	int		i;
	int		c;

	ft_printf("\nDumping memory at cycle %i ...\n", g_data->cycle);
	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%#0.4hx: ", i);
		c = 0;
		while (c++ < 32 && ++i)
			ft_printf((i - 1 < MEM_SIZE ? " %0.2hhx" : "   "),
					g_data->memory[i - 1]);
		ft_printf("  ");
		c = 32;
		while (--c >= 0 && i - c - 1 < MEM_SIZE)
			ft_printf(g_data->status[i - c - 1] ? "X" : ".");
		ft_printf("\n");
	}
	ft_printf("%#0.4hx:\n", i);
	exit(0);
}

void			print_end(void)
{
	t_player	*player;
	int			i;

	i = -1;
	while (++i < MAX_PLAYERS && g_data->player[i].file_name)
		if (g_data->player[i].number == g_data->last_live)
			player = &(g_data->player[i]);
	ft_printf("Contestant %i, \"%s\", has won !\n",
			player->number, player->header.prog_name);
}

void			print_error(int err)
{
	P_E("Error : ");
	err == 1 ? P_E("A memory allocation failled") : 0;
	err == 2 ? P_E("No arguments (-h for help)") : 0;
	err == 3 ? P_E("Invalid number after -dump") : 0;
	err == 4 ? P_E("Invalid number after -n") : 0;
	err == 5 ? P_E("There is no champion file after the last -n") : 0;
	err == 6 ? P_E("Too may arguments") : 0;
	err == 7 ? P_E("Invalid champion file, the file does not exist") : 0;
	err == 8 ? P_E("Invalid champion file, the extension is not .cor") : 0;
	err == 9 ? P_E("Invalid champion file, the file data are invalid") : 0;
	err == 10 ? P_E("Invalid champion file, prog_size is too high") : 0;
	P_E("\n");
	exit(1);
}

void			print_help(void)
{
	ft_putstr("Usage: corewar [-h] [-M | -N] [-dump N] <[-n N] ");
	ft_putstr("champion.cor> <...>\n\n");
	ft_putstr("  -dump  :  dumps memory after N cycles then exits\n");
	ft_putstr("  -h     :  print this help message\n");
	ft_putstr("  -M     :  mute output from live and aff instructions\n");
	ft_putstr("  -N     :  Ncurses display mode\n");
	ft_putstr("  -n     :  set the champion number to N\n");
	ft_putstr("\n");
	exit(0);
}

void			print_start(void)
{
	int		i;

	ft_printf("Introducing contestants...\n");
	i = -1;
	while (++i < MAX_PLAYERS && g_data->player[i].file_name)
		ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n",
				g_data->player[i].number, g_data->player[i].header.prog_size,
				g_data->player[i].header.prog_name,
				g_data->player[i].header.comment);
}
