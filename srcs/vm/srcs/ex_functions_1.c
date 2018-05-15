/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/15 22:10:26 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void				_ex_live(t_core *c, t_process *p)
{
	ft_printf("{green}{bold}\tIN\tLIVE\n{eoc}");//

	unsigned int	i;
	unsigned int	id_p;

	i = 0;
	c->v[5](c, p, 0);
	++c->total_live;
	++p->live;
	++c->current_cycle_live;
	id_p = c->v[T_DIR](c, p, p->l[1]);

	ft_printf("\t\tid_p: %p | %u\t\tp->live = %u\n", id_p, id_p, p->live);//

	if (id_p && id_p <= MAX_PLAYERS)
	{
		c->last_live_player = id_p;
		while (c->p[i].id != id_p && i < 4)
			++i;
		++c->p[i].total_live;
		++c->p[i].current_cycle_live;
		c->last_live_player = id_p;

		ft_printf("{green}un processus dit que le joueur");
		ft_printf(" %u(%s) est en vie\n{eoc}", id_p, c->p[i].name);
	}
	p->pc = id(p->pc + *p->l);

	ft_print_mem(&c->ram, MEM_SIZE, 64, 0);
	ft_printf("\t{green}{bold}END\tLIVE\n{eoc}");//
}

void				_ex_ld(t_core *c, t_process *p)
{
	ft_printf("\t{green}{bold}IN\tLD\n{eoc}");//

	int				i;
	unsigned int	p_1;
	unsigned int	p_2;

	c->v[5](c, p, 0);
	i = -1;
	p_1 = c->v[*p->ins.param](c, p, p->l[1]);

	ft_printf("\t\tp_1 = %#x\n", p_1);

	if ((p_2 = c->v[1](c, p, p->l[2])) > 15)
		return ((void)(p->pc = id(p->pc + *p->l)));

	ft_printf("\t\t(reg)p_2 = %u p->reg[p_2]: %u\n", p_2, p->reg[p_2]);

	p->reg[p_2] = (*p->ins.param & T_DIR ? p_1 : c->v[2](c, p, p_1));

	ft_printf("\t\tp->reg[p_2]: %#x\n", p->reg[p_2]);

	p->carry = p->carry ? 0 : 1;
	p->pc = id(p->pc + *p->l);

	ft_print_mem(&c->ram, MEM_SIZE, 64, 0);
	ft_printf("\t{green}{bold}END\tLD\n{eoc}");//
}

void				_ex_st(t_core *c, t_process *p)
{
	ft_printf("\t{green}{bold}IN\tST\n{eoc}");//
	ft_print_mem(&c->ram, MEM_SIZE, 64, 0);

	int				i;
	unsigned int	p_1;
	unsigned int	p_2;

	c->v[5](c, p, 0);
	i = -1;
	if ((p_1 = c->v[1](c, p, p->l[1])) > 15)
		return ((void)(p->pc = id(p->pc + *p->l)));
	ft_printf("\t\tp_1 = %u\n", p_1);//
	p_1 = p->reg[p_1];

	ft_printf("\t\tp_1 = %#x\n", p_1);//

	p_2 = c->v[p->ins.param[1] & T_REG ? 1 : 3](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && p_2 > 15)
		return ((void)(p->pc = id(p->pc + *p->l)));
	if (p->ins.param[1] & T_REG)
	{//

		ft_printf("\t\tp_2 = %u\n", p_2);//

		p->reg[p_2] = p_1;

		ft_printf("\t\tp_2 = %#x\n", p->reg[p_2]);//
	}//
	else
	{

		ft_printf("\t\t(addr)p_2 = %u\n", p_2);//

		p_2 = c->v[0](c, p, p_2);

		ft_printf("\t\t(addr)p_2 %u\n", p_2);//

		while (++i < 4)
			c->ram[id(p_2 + i)] = (p_1 >> (24 - (i * 8))) & 0xff;
	}
	p->pc = id(p->pc + *p->l);

	ft_print_mem(&c->ram, MEM_SIZE, 64, 0);
	ft_printf("\t{green}{bold}END\tST\n{eoc}");//
}

void				_ex_add(t_core *c, t_process *p)
{
	ft_printf("\t{green}{bold}IN\tADD{eoc}\n");

	unsigned int	p_1;
	unsigned int	p_2;
	unsigned int	p_3;

	c->v[5](c, p, 0);
	if ((p_1 = c->v[1](c, p, p->l[1])) > 15)
		return ((void)(p->pc = id(p->pc + *p->l)));
	if ((p_2 = c->v[1](c, p, p->l[2])) > 15)
		return ((void)(p->pc = id(p->pc + *p->l)));
	if ((p_3 = c->v[1](c, p, p->l[3])) > 15)
		return ((void)(p->pc = id(p->pc + *p->l)));

	ft_printf("\t\tp_1: %u | %p\n", p_1, p_1);
	ft_printf("\t\tp_2: %u | %p\n", p_2, p_2);
	ft_printf("\t\tp_3: %u | %p\n", p_3, p_3);
	ft_printf("\t\tp->reg[p_1]: %u | %p\n", p->reg[p_1], p->reg[p_1]);
	ft_printf("\t\tp->reg[p_2]: %u | %p\n", p->reg[p_2], p->reg[p_2]);
	ft_printf("\t\tp->reg[p_1] + p->reg[p_2]: %u\n", p->reg[p_2] + p->reg[p_1]);

	p->reg[p_3] = p->reg[p_1] + p->reg[p_2];

	ft_printf("\t\tp->reg[p_3]: %u | %p\n", p->reg[p_3], p->reg[p_3]);

	p->carry = p->carry ? 0 : 1;
	p->pc = id(p->pc + *p->l);

	ft_printf("\t{green}{bold}END\tADD{eoc}\n");
}

void				_ex_sub(t_core *core, t_process *process)
{
	unsigned int	p_1;
	unsigned int	p_2;
	unsigned int	p_3;

	core->v[5](core, process, 0);
	if ((p_1 = core->v[1](core, process, process->l[1])) > 15)
		return ((void)(process->pc = id(process->pc + *process->l)));
	if ((p_2 = core->v[1](core, process, process->l[2])) > 15)
		return ((void)(process->pc = id(process->pc + *process->l)));
	if ((p_3 = core->v[1](core, process, process->l[3])) > 15)
		return ((void)(process->pc = id(process->pc + *process->l)));
	process->reg[p_3] = process->reg[p_1] - process->reg[p_2];
	process->carry = process->carry ? 0 : 1;
	process->pc = id(process->pc + *process->l);
}
