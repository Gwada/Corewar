/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 11:17:02 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/13 14:53:16 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

static size_t	process_live_checker(t_core *core)
{
	t_process	*tmp;

	while (core->n_process && !core->ps->live)
		core->ps = del_process(core, core->ps);
	if (!core->n_process || !core->ps)
		return (1);
	tmp = core->ps;
	while (core->n_process && tmp)
	{
		if (tmp->next && !tmp->next->live)
			tmp->next = del_process(core, tmp->next);
		tmp->live = 0;
		tmp = tmp->next;
	}
	return (!core->n_process || !core->ps ? 1 : 0);
}

static size_t	cycle_to_die_checker(t_core *core)
{
	if (core->last_decr < MAX_CHECKS)
	{
		if (core->current_cycle_live >= NBR_LIVE)
		{
			if (core->max_cycle - CYCLE_DELTA <= 0)
				return (1);
			core->max_cycle -= CYCLE_DELTA;
			core->last_decr = 0;
		}
		else
			++core->last_decr;
	}
	else
	{
		if (core->max_cycle - CYCLE_DELTA <= 0)
			return (1);
		core->max_cycle -= CYCLE_DELTA;
		core->last_decr = 0;
	}
	core->current_cycle = 0;
	core->current_cycle_live = 0;
	return (0);
}

size_t			cycle_checker(t_core *core)
{
	if (core->bd & DUMP && core->dump && core->total_cycle == core->dump)
	{
//		ft_print_mem(core->ram, MEM_SIZE, 32, 0);
		return (1);
	}
	if ((int)core->current_cycle == core->max_cycle)
	{
		if (process_live_checker(core))
			return (1);
		if (cycle_to_die_checker(core))
			return (1);
	}
	return (0);
}
