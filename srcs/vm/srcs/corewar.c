/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:42:35 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/10 19:09:20 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

static int			check_cycle_param(t_core *core)
{
//	ft_printf("{bold}{magenta}IN\tCHECK_CYCLE_PARAM{eoc}\n");//
	t_process		*tmp;

	core->bd & VISUAL ? visu(core, 0) : 0;
	if (core->n_cycle == core->max_cycle)
	{
		core->bd & VISUAL ? visu(core, 0) : 0;
		while (core->n_process && !core->ps->n_live)
		{
			core->ps = del_process(core, core->ps);
			core->bd & VISUAL ? visu(core, 0) : 0;
		}
		tmp = core->ps;
		while (core->n_process && tmp)
		{
			core->bd & VISUAL ? visu(core, 0) : 0;
			if (tmp->next && !tmp->next->n_live)
				tmp->next = del_process(core, tmp->next);
			core->bd & VISUAL ? visu(core, 0) : 0;
			tmp = tmp->next;
		}
		core->n_cycle = 0;
		core->n_live >= NBR_LIVE ? core->max_cycle -= CYCLE_DELTA : 0;
		core->n_live >= NBR_LIVE ? core->last_decr = 0 : ++core->last_decr;
		core->n_live >= NBR_LIVE ? core->n_live = 0 : 0;
		core->last_decr == MAX_CHECKS ? core->max_cycle -= CYCLE_DELTA : 0;
		core->bd & VISUAL ? visu(core, 0) : 0;
	}
	if (core->bd & DUMP && core->n_cycle == core->dump)
		ft_print_mem(core->ram, MEM_SIZE, 32, 0);
//	ft_printf("{bold}{magenta}END\tCHECK_CYCLE_PARAM{eoc}\n\n");//
	return (!core->n_process || (core->n_cycle && core->n_cycle == core->dump));
}

void				check_instruct(t_core *c, t_process *tmp, unsigned char opc)
{
	ft_printf("{bold}{yellow}IN\tCHECK_INSTRUCT{eoc}\n");//
	while (tmp)
	{
		c->bd & VISUAL ? visu(c, 0) : 0;
		tmp->ins.nb_cycles > 0 ? --tmp->ins.nb_cycles : 0;
		opc = c->ram[id(*tmp->reg)];
		if ((!opc_c(opc) || !tmp->ins.name) && !tmp->ins.nb_cycles)
		{
			ft_printf("bad opc = %hhx\n", opc);
			*tmp->reg = id(*tmp->reg + 1);
			read_instruct(c, tmp);
		}
		if (tmp->ins.name && opc_c(opc) && !tmp->ins.nb_cycles)
		{
			if (!ft_strcmp(tmp->ins.name, g_op_tab[opc - 1].name))
				exec_instruct(c, tmp, opc - 1);
			else
			{
				ft_printf("bad match\n");
				*tmp->reg = id(*tmp->reg + 1);
				read_instruct(c, tmp);
			}
		}
		tmp = tmp->next;
	}
	ft_printf("{bold}{yellow}END\tCHECK_INSTRUCT{eoc}\n\n");//
}

void				corewar(t_core *core)
{
	ft_printf("{bold}{red}IN\tCOREWAR{eoc}\n");

	if (!(core->ps = init_process(core, -1)))
		return (display_error(core, 0));
	core->bd & VISUAL ? visu(core, 0) : 0;

/*
**	DEBUG DISPLAY
*/
	ft_printf("{red}------------------------------------------------{eoc}\n\n");
	ft_printf("{yellow}{bold}START{eoc}\n");//
	ft_printf("%u process in progress\n\n", core->n_process);//
	t_process *tmp = core->ps;
	while (tmp)
	{
		ft_printf("tmp->id = %u\n", tmp->reg[1]);
		ft_printf("tmp->ins.name = %s\n", tmp->ins.name);
		ft_printf("tmp->ins.nb_cycles = %u\n\n", tmp->ins.nb_cycles);
		tmp = tmp->next;
	}
	ft_printf("{red}------------------------------------------------{eoc}\n\n");
	ft_print_mem(core->ram, MEM_SIZE, 64, 0);


	while (core->n_process > 0)
	{
		core->bd & VISUAL ? visu(core, 0) : 0;
		if (check_cycle_param(core))
			break ;
		check_instruct(core, core->ps, 0);
		core->bd & VISUAL ? visu(core, 0) : 0;
		++core->cycle;
		++core->n_cycle;
	}

	ft_printf("there are %u total cycles\n", core->cycle);//
	ft_printf("%u is last cycle number\n", core->n_cycle);//
	ft_printf("%u is cycle_to_die\n", core->max_cycle);//
	ft_printf("%u process in progress\n", core->n_process);//
	ft_printf("{bold}{red}END\tCOREWAR{eoc}\n");//

	core->bd & VISUAL ? visu(core, 0) : 0;
	core->ps = clean_process(core->ps);
}
