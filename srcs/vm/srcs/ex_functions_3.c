/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/12 10:57:01 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void		_ex_sti(t_core *c, t_process *p)
{
	int				i;
	unsigned int	p_1;
	unsigned int	p_2;
	unsigned int	p_3;

	i = -1;
	p_1 = 0;
	p_2 = 0;
	p_3 = 0;
	if (!(p_1 = c->v[1](c, p, 2)) || p_1 > 16)
		return ;
	p_1 = p->rg[p_1];
	p_2 = c->v[p->ins.param[1]](c, p, 3);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ;
	p->ins.param[1] & T_REG ? p_2 = p->rg[p_2]: 0;
	p_3 = c->v[p->ins.param[2]](c, p, (p->ins.param[1] & T_REG ? 4 : 5));
	if (p->ins.param[2] & T_REG && (!p_3 || p_3 > 16))
		return ;
	p->ins.param[2] & T_REG ? p_3 = p->rg[p_3]: 0;
	p_2 += p_3;
	while (++i < 4)
		c->ram[c->v[0](c, p, p_2 + i)] = (p_1 >> (24 - (i * 8))) & 0xff;
	p->pc = id(p->pc + (p->ins.param[1] & T_REG ? 3 : 4));
	p->pc = id(p->pc + (p->ins.param[2] & T_REG ? 1 : 2));
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
