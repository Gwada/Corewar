/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/13 20:39:21 by dlavaury         ###   ########.fr       */
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
	++p->live;
	++c->current_cycle_live;
	id_p = c->v[T_DIR](c, p, 1);
//	ft_printf("%p\np->live = %u\n", id_p, p->live);//
	if (!id_p || id_p > MAX_PLAYERS)
		return ;
	c->last_live_player = id_p;
	p->opc = id(p->opc + 4);
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
//	ft_printf("p_1 = %u\n", p_1);
	p_2 = c->v[1](c, p, (*p->ins.param & T_DIR ? 6 : 4));
	if (p_2 > 15)
		return ;
//	ft_printf("p_2 = %u\n", p_2);
	p->reg[p_2] = (*p->ins.param & T_DIR ? p_1 : c->v[0](c, p, p_1));
	p->carry = p->carry ? 0 : 1;
	p->opc = id(p->opc + (*p->ins.param & T_DIR ? 6 : 4));
}

void				_ex_st(t_core *c, t_process *p)
{
	int				i;
	unsigned int	p_1;
	unsigned int	p_2;

	i = -1;
	if ((p_1 = c->v[1](c, p, 2)) > 15)
		return ;
	p_1 = p->reg[p_1];
//	ft_printf("p_1 = %u / %d / %p\n", p_1, p_1, p_1);//
	p_2 = c->v[(p->ins.param[1] & T_REG ? 1 : 3)](c, p, 3);
	if (p->ins.param[1] & T_REG && p_2 > 15)
		return ;
//	ft_printf("p_2 = %u / %d / %p\n", p_2, p_2, p_2);//
	if (p->ins.param[1] & T_REG)
	{
//		ft_printf("st 1\n");
		p->reg[p_2] = p_1;
	}
	else
	{
//		ft_printf("st 2\n");
		while (++i < 4)
			c->ram[id(c->v[0](c, p, p_2 + i))] = (p_1 >> (24 - (i * 8))) & 0xff;
	}
	p->opc = id(p->opc + (p->ins.param[1] & T_REG ? 3 : 4));
}

void				_ex_add(t_core *core, t_process *process)
{
	unsigned int	p_1;
	unsigned int	p_2;
	unsigned int	p_3;

	if ((p_1 = core->v[1](core, process, 2)) > 15)
		return ;
	if ((p_2 = core->v[1](core, process, 3)) > 15)
		return ;
	if ((p_3 = core->v[1](core, process, 4)) > 15)
		return ;
	process->reg[p_3] = process->reg[p_1] + process->reg[p_2];
	process->carry = process->carry ? 0 : 1;
	process->opc = id(process->opc + 4);
}

void				_ex_sub(t_core *core, t_process *process)
{
	unsigned int	p_1;
	unsigned int	p_2;
	unsigned int	p_3;

	if ((p_1 = core->v[1](core, process, 2)) > 15)
		return ;
	if ((p_2 = core->v[1](core, process, 3)) > 15)
		return ;
	if ((p_3 = core->v[1](core, process, 4)) > 15)
		return ;
	process->reg[p_3] = process->reg[p_1] - process->reg[p_2];
	process->carry = process->carry ? 0 : 1;
	process->opc = id(process->opc + 4);
}
