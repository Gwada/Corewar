/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:42:35 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/13 17:46:02 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

/*static void		check_ins(t_core *c, t_process *tmp, unsigned char opc)
{
	opc = c->ram[id(*tmp->rg)];
	if ((!opc_c(opc) || !tmp->ins.name) && !tmp->ins.nb_cycles)
	{
		*tmp->rg = id(*tmp->rg + 1);
		read_instruct(c, tmp);
	}
	if (tmp->ins.name && opc_c(opc) && !tmp->ins.nb_cycles)
	{
		if (!ft_strcmp(tmp->ins.name, g_op_tab[opc - 1].name))
			exec_instruct(c, tmp, opc - 1);
		else
		{
			*tmp->rg = id(*tmp->rg + 1);
			read_instruct(c, tmp);
		}
	}
}*/

static void			check_instruct(t_core *c, unsigned char opc)
{
	ft_printf("{bold}{yellow}IN\tCHECK_INSTRUCT{eoc}\n");//
	t_process		*tmp;

	tmp = c->ps;
	while (tmp)
	{
		if (tmp->ins.nb_cycles > 0)
			--tmp->ins.nb_cycles;
		else
		{
			opc = c->ram[id(*tmp->rg)];
			if (opc_c(opc) && tmp->ins.name
			&& !ft_strcmp(tmp->ins.name, g_op_tab[opc - 1].name))
				exec_instruct(c, tmp, opc - 1);
			*tmp->rg = id(*tmp->rg + 1);
			read_instruct(c, tmp);
			if (tmp->ins.nb_cycles > 0)
				ft_printf("{blue}{bold}{underline}NEED SORT\n{eoc}");
		}
		tmp = tmp->next;
	}
	ft_printf("{bold}{yellow}END\tCHECK_INSTRUCT{eoc}\n\n");//
}
static void		put_champ(t_core *core)
{
	unsigned	i;

	if (core->dump && core->total_cycle == core->dump)
		return ;
	if (!core->last_live_player)
	{
		ft_printf("There is no winner at the end of this game\n");//
		return ;
	}
	i = 0;
	while (i < core->player && core->p[i].id != core->last_live_player)
		++i;
	ft_printf("le joueur %u(%s) a gagne\n", core->p[i].id, core->p[i].name);//
}
void				corewar(t_core *core)
{
	ft_printf("{bold}{red}IN\tCOREWAR{eoc}\n");//

	if (!(core->ps = init_process(core, -1)))
		return (display_error(core, 0));
	while (core->n_process > 0)
	{
		ft_printf("%u cycles\n", core->total_cycle);
		if (cycle_checker(core))
			break ;
		check_instruct(core, 0);
		++core->total_cycle;
		++core->current_cycle;
	}

	ft_printf("\nthere are %u total cycles\n", core->total_cycle);//
	ft_printf("%u process in progress\n", core->n_process);//
	ft_printf("{bold}{red}END\tCOREWAR{eoc}\n");//

	put_champ(core);
	core->ps = clean_process(core->ps);
}
