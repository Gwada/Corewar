/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <brigoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 12:18:49 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/25 21:24:34 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		run_vm(void)
{
	print_start();
	while (g_data->process)
	{
		do_cycle();
		if (++g_data->period_cycle >= g_data->cycle_to_die)
		{
			g_data->period_cycle = 0;
			if (get_periodlive() >= NBR_LIVE || ++g_data->check == MAX_CHECKS)
			{
				g_data->check = 0;
				g_data->cycle_to_die = CTD(g_data->cycle_to_die - CYCLE_DELTA);
			}
			check_process(&g_data->process);
		}
		if (g_data->cycle == g_data->dump)
			print_dump();
		g_data->cycle++;
	}
	print_end();
}

void		run_ncurses(void)
{
	ncurses_main();
}
