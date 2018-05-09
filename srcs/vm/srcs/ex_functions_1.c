/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/09 20:30:23 by dlavaury         ###   ########.fr       */
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
	*process->reg = id(*process->reg + 1);
	while (++i < 4)
	{
		id_p = (id_p << 8) | core->ram[*process->reg];
		*process->reg = id(*process->reg + 1);
	}
	if (!id_p || id_p > 4)
		return ;
	ft_printf("un processus dit que le joueur");
	ft_printf(" %u() est en vie\n", id_p);
}

void				_ex_ld(t_core *core, t_process *process)
{
	(void)core;
	(void)process;
}

void				_ex_st(t_core *c, t_process *p)
{
	unsigned char	p_1;
	unsigned short	p_2;

	ft_printf("ocp = %hhx\n", c->ram[id(*p->reg)]);//
	ft_printf("opcode = %hhx\n", c->ram[id(*p->reg + 1)]);//

	if (*p->ins.param ^ T_REG || p->ins.param[2]
	|| (p->ins.param[1] ^ T_REG && p->ins.param[1] ^ T_IND)
	|| _abs(c->ram[id(*p->reg + 1)], SND))
		return ;
	p_1 = c->ram[id(*p->reg + 2)];

	ft_printf("param_1 = %hhx\n", p_1);//

	p_2 = c->ram[id(*p->reg + 3)];
	p->ins.param[1] ^ T_REG ? p_2 = (p_2 << 8) | c->ram[id(*p->reg + 4)] : 0;
	
	ft_printf("param_2 = %hx\n", p_2);//

	if (!p_1 || p_1 > 16 || (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16)))
		return ;
	p->ins.param[1] & T_REG ? p->reg[p_2] = p->reg[p_1] : 0;
	if (p->ins.param[1] ^ T_REG)
	{
		ft_printf("test 1\n\n");
		ft_printf("indice = %u\n", id(*p->reg + (p_2 / IDX_MOD)));
		ft_printf("hex = %x\n\n", c->ram[id(*p->reg + (p_2 / IDX_MOD))]);

		ft_printf("indice = %u\n", id(*p->reg + (p_2 / IDX_MOD) + 1));
		ft_printf("hex = %x\n\n", c->ram[id(*p->reg + (p_2 / IDX_MOD) + 1)]);
		
		ft_printf("indice = %u\n", id(*p->reg + (p_2 / IDX_MOD) + 2));
		ft_printf("hex = %x\n\n", c->ram[id(*p->reg + (p_2 / IDX_MOD) + 2)]);
		
		ft_printf("indice = %u\n", id((*p->reg + (p_2 / IDX_MOD)) + 3));
		ft_printf("hex = %x\n\n", c->ram[id(*p->reg + (p_2 / IDX_MOD) + 3)]);

		c->ram[id(*p->reg + (p_2 / IDX_MOD))] = p->reg[p_1] & 0xff000000;
		c->ram[id((*p->reg + (p_2 / IDX_MOD)) + 1)] = p->reg[p_1] & 0xff0000;
		c->ram[id((*p->reg + (p_2 / IDX_MOD)) + 2)] = p->reg[p_1] & 0xff00;
		c->ram[id((*p->reg + (p_2 / IDX_MOD)) + 3)] = p->reg[p_1] & 0xff;
	}
	*p->reg = p->ins.param[1] & T_REG ? id(*p->reg + 3) : id(*p->reg + 4);

	ft_printf("ocp = %hhx\n\n", c->ram[id(*p->reg + 1)]);//
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
