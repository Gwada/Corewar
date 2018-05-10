/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/10 20:39:17 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void		_ex_sti(t_core *c, t_process *p)
{
	unsigned int	p_1;
	unsigned int	p_2;
	unsigned int	p_3;

	p_1 = 0;
	p_2 = 0;
	p_3 = 0;
	c->ram[id(*p->reg + p_3 + 3)] = p_1 & 0xff;
	if (!(p_1 = c->v[1](c, p, c->ram[id(*p->reg + 2)])) || p_1 > 16)
		return ;
	if (p->ins.param[1] & T_REG)
		if (!(p_2 = c->v[1](c, p, c->ram[id(*p->reg + 3)])) || p_2 > 16)
			return ;
	if (p->ins.param[1] ^ T_REG)
		p_2 = c->v[p->ins.param[1]](c, p, id(*p->reg + 3));
	if (p->ins.param[2] & T_REG)
		if (!(p_3 = c->v[1](c, p, c->ram[id(*p->reg + 5)])) || p_3 > 16)
			return ;
	if (p->ins.param[2] ^ T_REG)
		p_3 = c->v[p->ins.param[2]](c, p, id(*p->reg + 5));
	c->ram[id(*p->reg + p_3)] = p_1 >> 24;
	c->ram[id(*p->reg + p_3 + 1)] = (p_1 >> 16) & 0xff;
	c->ram[id(*p->reg + p_3 + 2)] = (p_1 >> 8) & 0xff;
	c->ram[id(*p->reg + p_3 + 3)] = p_1 & 0xff;
	*p->reg = id(*p->reg + (p->ins.param[1] & T_REG ? 3 : 4));
	*p->reg = id(*p->reg + (p->ins.param[2] & T_REG ? 1 : 2));
}

void		_ex_fork(t_core *core, t_process *process)
{
	(void)core;
	(void)process;
}

void		_ex_lld(t_core *core, t_process *process)
{
	(void)core;
	(void)process;
}

void		_ex_lldi(t_core *core, t_process *process)
{
	(void)core;
	(void)process;
}

void		_ex_lfork(t_core *core, t_process *process)
{
	(void)core;
	(void)process;
}
