/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/12 19:45:56 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void				_ex_live(t_core *c, t_process *p)
{
	unsigned int	i;
	unsigned int	id_p;

	i = 0;
	++c->total_live;
	++p->total_live;
	++c->current_cycle_live;
	++p->current_cycle_live;
	id_p = c->v[T_DIR](c, p, 1);
	if (!id_p || id_p > MAX_PLAYERS)
		return ;
	c->last_live_player = id_p;
	*p->rg = id(*p->rg + 4);
	while (c->p[i].id != id_p && i < 4)
		++i;
	++c->p[i].total_live;
	++c->p[i].current_cycle_live;
	c->last_live_player = id_p;
	ft_printf("un processus dit que le joueur");
	ft_printf(" %u(%s) est en vie\n", id_p, c->p[i].name);
}

void				_ex_ld(t_core *c, t_process *p)
{
	int				i;
	unsigned int	p_1;
	unsigned int	p_2;

	i = -1;
	p_1 = c->v[*p->ins.param](c, p, 2);
	p_2 = *p->ins.param & T_DIR ? c->v[1](c, p, 6) : c->v[1](c, p, 4);
	if (!p_2 || p_2 > REG_NUMBER)
		return ;
	p->rg[p_2] = p_1;
	p->carry = p->carry ? 0 : 1;
	*p->rg = id(*p->rg + (*p->ins.param & T_DIR ? 6 : 4));
}

void				_ex_st(t_core *c, t_process *p)
{
	int				i;
	unsigned int	p_1;
	unsigned int	p_2;

	i = -1;
	if (!(p_1 = c->v[1](c, p, 2)) || p_1 > 16)
		return ;
	p_1 = p->rg[p_1];
	if (p->ins.param[1] & T_REG)
	{
		if (!(p_2 = c->v[1](c, p, 3)) || p_2 > 16)
			return ;
		p->rg[p_2] = p->rg[p_1];
	}
	else
	{
		p_2 = c->v[2](c, p, 3) >> 16;
		while (++i < 4)
			c->ram[c->v[0](c, p, p_2 + i)] = (p_1 >> (24 - (i * 8))) & 0xff;
	}
	*p->rg = p->ins.param[1] & T_REG ? id(*p->rg + 3) : id(*p->rg + 4);
}

void				_ex_add(t_core *core, t_process *process)
{
	unsigned int	p_1;
	unsigned int	p_2;
	unsigned int	p_3;

	if (!(p_1 = core->v[1](core, process, 2)) || p_1 > 16)
		return ;
	if (!(p_2 = core->v[1](core, process, 3)) || p_2 > 16)
		return ;
	if (!(p_3 = core->v[1](core, process, 4)) || p_3 > 16)
		return ;
	process->rg[p_3] = process->rg[p_1] + process->rg[p_2];
	process->carry = process->carry ? 0 : 1;
	*process->rg = id(*process->rg + 4);
}

void				_ex_sub(t_core *core, t_process *process)
{
	unsigned int	p_1;
	unsigned int	p_2;
	unsigned int	p_3;

	if (!(p_1 = core->v[1](core, process, 2)) || p_1 > 16)
		return ;
	if (!(p_2 = core->v[1](core, process, 3)) || p_2 > 16)
		return ;
	if (!(p_3 = core->v[1](core, process, 4)) || p_3 > 16)
		return ;
	process->rg[p_3] = process->rg[p_1] - process->rg[p_2];
	process->carry = process->carry ? 0 : 1;
	*process->rg = id(*process->rg + 4);
}
