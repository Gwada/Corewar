/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 11:17:02 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/19 20:13:19 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"//

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
	if (core->bd & DUMP && core->dump && core->total_cycle == (int)core->dump)
	{
//		ft_print_mem(core->ram, MEM_SIZE, 32, 0);
		return (1);
	}
	if ((int)core->current_cycle == core->max_cycle)
	{
		if (process_live_checker(core))
			return (1);
		if (core->current_cycle_live >= NBR_LIVE && !(core->last_decr = 0))
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
	return (core->max_cycle <= 0);
}
