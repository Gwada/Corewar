/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/10 17:16:58 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void				_ex_live(t_core *core, t_process *process)
{
	int				i;
	unsigned int	id_p;

	i = -1;
	id_p = 0;
	++core->live;
	++process->live;
	while (++i < REG_SIZE)
		id_p = (id_p << 8) | core->ram[id(*process->reg + i + 1)];
	if (!id_p || id_p > MAX_PLAYERS)
		return ;
	++core->n_live;
	++process->n_live;
	core->last_live_player = id_p;
	*process->reg = id(*process->reg + 4);
	i = 0;
	while (core->p[i].id != id_p && i < 4)
		++i;
	ft_printf("un processus dit que le joueur");
	ft_printf(" %u(%s) est en vie\n", id_p, core->p[i].name);
}

void				_ex_ld(t_core *c, t_process *p)
{
	int				i;
	unsigned char	p_2;
	unsigned int	p_1;

	i = -1;
	p_1 = 0;
	if ((*p->ins.param ^ T_DIR && *p->ins.param ^ T_IND) || p->ins.param[2]
	|| p->ins.param[1] ^ T_REG || _abs(c->ram[id(*p->reg + 1)], SND))
		return ;
	while (++i < (REG_SIZE / (*p->ins.param & t_DIR ? 4 : 2)))
		p_1 = (p_1 << 8) | c->ram[id(*p->reg + i + 2)];
	*p->ins.param & T_DIR ? p_2 = c->ram[id(*p->reg + 6)] : 0;
	*p->ins.param & T_IND ? p_2 = c->ram[id(*p->reg + 4)] : 0;
	if (!p_2 || p_2 > NUMBER)
		return ;
	*p->ins.param & T_DIR ? = p->reg[p_2] = p_1 : 0;
	i = -1;
	while (*p->ins.param & T_IND && ++i < 4)
	{
		p->reg[p_2] <<= 8;
		p->reg[p_2] |= c->ram[id(*p->reg + (p_2 / IDX_MOD) + i)];
	}
}

void				_ex_st(t_core *c, t_process *p)
{
	unsigned char	p_1;
	unsigned short	p_2;

	if (*p->ins.param ^ T_REG || p->ins.param[2]
	|| (p->ins.param[1] ^ T_REG && p->ins.param[1] ^ T_IND)
	|| _abs(c->ram[id(*p->reg + 1)], SND))
		return ;
	p_1 = c->ram[id(*p->reg + 2)];
	p_2 = c->ram[id(*p->reg + 3)];
	p->ins.param[1] & T_IND ? p_2 = (p_2 << 8) | c->ram[id(*p->reg + 4)] : 0;
	if (!p_1 || p_1 > 16 || (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16)))
		return ;
	p->ins.param[1] & T_REG ? p->reg[p_2] = p->reg[p_1] : 0;
	if (p->ins.param[1] & T_IND)
	{
		c->ram[id(*p->reg + (p_2 / IDX_MOD))] = p->reg[p_1] & 0xff000000;
		c->ram[id(*p->reg + (p_2 / IDX_MOD) + 1)] = p->reg[p_1] & 0xff0000;
		c->ram[id(*p->reg + (p_2 / IDX_MOD) + 2)] = p->reg[p_1] & 0xff00;
		c->ram[id(*p->reg + (p_2 / IDX_MOD) + 3)] = p->reg[p_1] & 0xff;
	}
	*p->reg = p->ins.param[1] & T_REG ? id(*p->reg + 3) : id(*p->reg + 4);
}

void				_ex_add(t_core *core, t_process *process)
{
	(void)core;
	(void)process;
}

void				_ex_sub(t_core *core, t_process *process)
{
	(void)core;
	(void)process;
}
