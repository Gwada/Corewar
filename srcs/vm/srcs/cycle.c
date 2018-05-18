/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 11:17:02 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/18 15:03:16 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

static size_t	process_live_checker(t_core *core)
{
	t_process	*tmp;

	tmp = core->ps;
	while (core->n_process && tmp)
		tmp = !tmp->live ? del_process(core, tmp) : tmp->next;
	return (!core->n_process ? 1 : 0);
}

size_t			cycle_checker(t_core *core)
{
	ft_printf("\t{black}{bold}IN\tCYCLE_CHECKER{eoc}\n");//
	if ((int)core->current_cycle == core->max_cycle)
	{
		if (process_live_checker(core))
			return (1);
		ft_printf("core->current_cycle_live = %d\n", core->current_cycle_live);
		ft_printf("core->last_decr = %d\t", core->last_decr);
		if (core->current_cycle_live >= NBR_LIVE)
			core->max_cycle -= CYCLE_DELTA;
		else
			++core->last_decr;
		if (core->last_decr >= MAX_CHECKS)
		{
			core->max_cycle -= CYCLE_DELTA;
			core->last_decr = 0;
		}
		core->current_cycle = 0;
		core->current_cycle_live = 0;
	}
	if (core->bd & DUMP && core->dump && core->total_cycle == (int)core->dump)
	{
//		ft_print_mem(core->ram, MEM_SIZE, 32, 0);
//
//		ft_print_mem(core->ram, MEM_SIZE, 64, 0);

		return (1);
	}

	ft_printf("\t{black}{bold}END\tCYCLE_CHECKER{eoc}\n");//

	return (0);
}
