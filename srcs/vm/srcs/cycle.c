/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 11:17:02 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/16 18:57:36 by dlavaury         ###   ########.fr       */
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

static size_t	cycle_to_die_checker(t_core *core)
{
	if (core->last_decr < MAX_CHECKS && max_checker(core))
	{
		ft_printf("{yellow}......................................................................................{eoc}");//
		core->max_cycle -= CYCLE_DELTA;
		if (core->max_cycle <= 0)
			return (1);
		core->last_decr = 0;
	}
	else if (core->last_decr >= MAX_CHECKS)
	{
		ft_printf("{red}......................................................................................{eoc}");//
		core->max_cycle -= CYCLE_DELTA;
		if (core->max_cycle <= 0)
			return (1);
		core->last_decr = 0;
	}
	return (0);
}

size_t			max_checker(t_core *core)
{
	t_process	*tmp;

	tmp = core->ps;
	while (tmp)
	{
		if (!tmp->live && ++core->last_decr)
			return (0);
		tmp = tmp->next;
	}
//	return (CYCLE_DELTA);
	return (1);
}

size_t			cycle_checker(t_core *core)
{
	if (core->bd & DUMP && core->dump && core->total_cycle == (int)core->dump)
	{
//		ft_print_mem(core->ram, MEM_SIZE, 32, 0);
//
		ft_print_mem(core->ram, MEM_SIZE, 64, 0);

		return (1);
	}
	if ((int)core->current_cycle == core->max_cycle)
	{
		if (!core->total_live || process_live_checker(core))
			return (1);
		if (core->total_live && !(core->current_cycle_live % NBR_LIVE))
			if (cycle_to_die_checker(core))
				return (1);
		core->current_cycle = 0;
		core->current_cycle_live = 0;
	}
	return (0);
}
