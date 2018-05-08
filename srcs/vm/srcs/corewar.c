/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:42:35 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/08 20:00:24 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

static int		check_cycle_param(t_core *core)
{
//	ft_printf("{bold}{magenta}IN\tCHECK_CYCLE_PARAM{eoc}\n");//
	t_process	*tmp;

	if (core->n_cycle == core->max_cycle)
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
//	ft_printf("{bold}{magenta}END\tCHECK_CYCLE_PARAM{eoc}\n\n");//
	return (!core->n_process || (core->n_cycle && core->n_cycle == core->dump));
}

void			check_instruct(t_core *core)
{
	ft_printf("{bold}{yellow}IN\tCHECK_INSTRUCT{eoc}\n");//
	t_process	*tmp;

	tmp = core->ps;
	while (tmp)
	{
		tmp->ins.nb_cycles > 0 ? --tmp->ins.nb_cycles : 0;
		!tmp->ins.name ? *tmp->reg = id(*tmp->reg + 1) : 0;
		!tmp->ins.name ? read_instruct(core, tmp) : 0;
		if (!tmp->ins.nb_cycles && tmp->ins.name)
		{
			exec_instruct(core, tmp);
		}
		tmp = tmp->next;
	}
	ft_printf("{bold}{yellow}END\tCHECK_INSTRUCT{eoc}\n\n");//
}

void			corewar(t_core *core)
{
	ft_printf("{bold}{red}IN\tCOREWAR{eoc}\n");//

	if (!(core->ps = init_process(core, -1)))
		return (display_error(core, 0));
	ft_printf("{yellow}{bold}START{eoc}\t");//
	ft_printf("%u process in progress\n\n", core->n_process);//
	t_process *tmp = core->ps;
	while (tmp)
	{
		ft_printf("tmp->id = %u\n", tmp->reg[1]);
		ft_printf("tmp->ins.name = %s\n", tmp->ins.name);
		ft_printf("tmp->ins.nb_cycles = %s\n\n", tmp->ins.name);
		tmp = tmp->next;
	}
//	ft_print_mem(core->ram, MEM_SIZE, 64, 0);
	while (core->n_process > 0)
	{
		if (check_cycle_param(core))
			break ;
		check_instruct(core);
		++core->cycle;
		++core->n_cycle;
	}

	ft_printf("there are %u total cycles\n", core->cycle);//
	ft_printf("%u is last cycle number\n", core->n_cycle);//
	ft_printf("%u is cycle_to_die\n", core->max_cycle);//
	ft_printf("%u process in progress\n", core->n_process);//

	core->ps = clean_process(core->ps);

	ft_printf("{bold}{red}END\tCOREWAR{eoc}\n");//
}
