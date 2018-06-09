/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 11:17:02 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/09 18:10:24 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"//

static size_t	process_live_checker(t_core *core)
{
	t_process	*tmp;

	tmp = core->ps;
	while (core->n_process > 0 && tmp)
	{
		if (!tmp->live)
		{
//			ft_printf("plc1\n");//
			if (!(tmp = del_process(core, tmp)))
			{
//			ft_printf("plc1.1\n");//
				return (core->n_process == 0);
			}
//			ft_printf("plc2\n\n");//
		}
		else
		{
			tmp->live = 0;
			tmp = tmp->next;
//			ft_printf("plc3\n\n");//
		}
	}
	return (core->n_process == 0);
}

size_t			cycle_checker(t_core *core)
{
//	ft_printf("cc1\n");
	if (core->bd & DUMP && core->dump && core->total_cycle == (int)core->dump)
	{
//		ft_print_mem(core->ram, MEM_SIZE, 32, 0);
//	ft_printf("cc2\n");
		return (1);
	}
	if ((int)core->current_cycle == core->max_cycle)
	{
//	ft_printf("cc3\n");
		if (process_live_checker(core))
			return (1);
//	ft_printf("cc4\n");
		if (core->current_cycle_live >= NBR_LIVE)
		{
			core->last_decr = 0;
			core->max_cycle -= CYCLE_DELTA;
		}
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
//	ft_printf("cc4\n");
	return (core->max_cycle <= 0);

}
