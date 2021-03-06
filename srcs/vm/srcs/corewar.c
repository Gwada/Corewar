/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:42:35 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/13 18:51:50 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "time.h"
#include "../../libft/includes/ft_printf.h"

static void			put_champ(t_core *core)
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

static void			ex_functions(t_core *c, t_process *p, unsigned char opc)
{
	if (p->ins.name && !ft_strcmp(p->ins.name, g_op_tab[opc].name))
	{
		if (c->ft[opc](&c->ram[id(p->pc + 1)], p))
		{
			c->bd & DEBUG ? display_cw(c, p, opc, 0) : 0;
			c->ex[opc](c, p);
			c->bd & DEBUG ? display_cw(c, p, opc, 1) : 0;
		}
		else
			p->pc = moov_opc(c, p, p->ins.ocp ? 2 : 1);
	}
}

static void			check_instruct(t_core *c, t_process *p, unsigned char opc)
{
	while (p)
	{
		if (!p->ins.nb_cycles)
		{
			if (opc_c((opc = c->ram[id(p->pc)] - 1)))
				ex_functions(c, p, opc);
			else
				p->pc = moov_opc(c, p, 1);
			read_instruct(c, p) ? --p->ins.nb_cycles : 0;
		}
		else
			--p->ins.nb_cycles;
		p = p->next;
	}
}

void				reverse_ps(t_core *c)
{
	c->reverse_ps = c->ps;
	while (c->reverse_ps->pc != 0)
		c->reverse_ps = c->reverse_ps->next;
}

void				corewar(t_core *core)
{
	if (!init_process(core, -1))
		return ((void)display_error(core, 0, NULL));
	core->bd & VISUAL ? reverse_ps(core) : 0;
	while (core->n_process > 0 && core->max_cycle > 0 && core->ps)
	{
		check_instruct(core, core->ps, 0);
		if (cycle_checker(core))
			break ;
		++core->total_cycle;
		++core->current_cycle;
		core->bd & VISUAL ? visu(core, 1, NULL, 0) : 0;
	}
	core->bd & VISUAL ? endwin() : 0;
	put_champ(core);
	clean_process(core->ps);
}
