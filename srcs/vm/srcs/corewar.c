/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:42:35 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/07 21:30:39 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

static int			check_cycle_param(t_core *core)
{
	t_process	*tmp;

	if (core->n_cycle == core->max_cycle) // suppression de process "morts"
	{
		while (core->n_process && !core->ps->n_live)
			core->ps = del_process(core, core->ps);
		tmp = core->ps;
		while (core->n_process && tmp)
		{
			if (tmp->next && !tmp->next->n_live)
				tmp->next = del_process(core, tmp->next);
			tmp = tmp->next;
		}
		core->n_cycle = 0;
		core->n_live >= NBR_LIVE ? core->max_cycle -= CYCLE_DELTA : 0;
		core->n_live >= NBR_LIVE ? core->last_decr = 0 : ++core->last_decr;
		core->n_live >= NBR_LIVE ? core->n_live = 0 : 0;
		core->last_decr == MAX_CHECKS ? core->max_cycle -= CYCLE_DELTA : 0;
	}
	if (core->bd & DUMP && core->n_cycle == core->dump)
		ft_print_mem(core->ram, MEM_SIZE, 32, 0);
	return (!core->n_process || core->cycle == core->dump);
}

void				corewar(t_core *core)
{
	ft_printf("{bold}{red}IN\tCOREWAR{eoc}\n");

	if (!(core->ps = init_process(core, -1)))
		return (display_error(core, 0));

	while (core->n_process > 0)
	{
		++core->cycle;
		++core->n_cycle;
		if (check_cycle_param(core))
			break ;
	}

	ft_printf("there are %u total cycles\n", core->cycle);//
	ft_printf("%u is last cycle number\n", core->n_cycle);//
	ft_printf("%u is cycle_to_die\n", core->max_cycle);//
	ft_printf("%u process in progress\n", core->n_process);//

	visu(core, 1);
	visu(core, 0);
	clean_process(core->ps);

	/*ft_printf("{bold}{red}END\tCOREWAR{eoc}\n");//*/
}
