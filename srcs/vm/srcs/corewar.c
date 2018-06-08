/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:42:35 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/08 19:35:45 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "time.h"
#include "../../libft/includes/ft_printf.h"

static void			check_instruct(t_core *c, unsigned char opc)
{
/*
	ft_printf("\n{bold}{yellow}{underline}IN\tCHECK_INSTRUCT\t");//
	ft_printf("{red}CYCLE: %u\n{eoc}", c->total_cycle);//
*/
	t_process		*tmp;

	tmp = c->ps;
	while (tmp)
	{
		if (!tmp->ins.nb_cycles)
		{
			if (opc_c((opc = c->ram[id(tmp->pc)] - 1)) && tmp->ins.name)
			{
				if (!ft_strcmp(tmp->ins.name, g_op_tab[opc].name))
				{
					if (c->ft[opc](&c->ram[id(tmp->pc + 1)], tmp))
					{
						display_corewar(c, tmp, opc, 0);
						c->ex[opc](c, tmp);
						display_corewar(c, tmp, opc, 1);
					}
					else
						tmp->pc = id(tmp->pc + 1);
				}
			}
			else
				tmp->pc = id(tmp->pc + 1);
			read_instruct(c, tmp) ? --tmp->ins.nb_cycles : 0;
		}
		else
			--tmp->ins.nb_cycles;
		tmp = tmp->next;
	}

//	ft_printf("{bold}{yellow}{underline}END\tCHECK_INSTRUCT{eoc}\n");//

}
static void		put_champ(t_core *core)
{
	unsigned	i;

	if (core->dump && core->total_cycle == (int)core->dump)
		return ;
	if (!core->last_live_player)
	{
		ft_printf("There is no winner at the end of this game\n");
		return ;
	}
	i = 0;
	while (i < core->player && core->p[i].id != core->last_live_player)
		++i;
	ft_printf("le joueur %d(%s) a gagne\n", -core->p[i].id, core->p[i].name);
}
void				corewar(t_core *core)
{
//	ft_printf("{bold}{red}IN\tCOREWAR{eoc}\n");//

	if (!(core->ps = init_process(core, -1)))
		return ((void)display_error(core, 0, NULL));
	while (core->n_process > 0 && core->max_cycle > 0 && core->ps)
	{
/*
		ft_printf("{bold}{red}current cycle: %u\tcycle_to_die: %d\tbefore cycle_to_die: %d\tcurrent_live: %d\n{eoc}",  core->current_cycle, core->max_cycle, core->max_cycle - core->current_cycle, core->current_cycle_live);
*/
		check_instruct(core, 0);
		if (cycle_checker(core))
			break ;
		++core->total_cycle;
		++core->current_cycle;
	}
/*
	ft_printf("{bold}\n%u process in progress at end\nend after %u cycles\n{red}END\tCOREWAR{eoc}\n", core->n_process, core->total_cycle);//
*/
	put_champ(core);
	core->n_process ? clean_process(core->ps) : 0;
}
