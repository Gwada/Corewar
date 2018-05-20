/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/19 18:58:40 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void				_ex_live(t_core *c, t_process *p)
{
	ft_printf("{green}{bold}\tIN\tLIVE\n{eoc}");//

	int				i;
	int				id_p;

	i = -1;
	c->v[5](c, p, 0);
	++c->total_live;
	++p->live;
	++c->current_cycle_live;
	id_p = c->v[*p->ins.param](c, p, p->l[1]);
	while (++i < (int)c->player)
		if (id_p == c->p[i].id)
		{
			++c->p[i].total_live;
			++c->p[i].current_cycle_live;
			c->last_live_player = id_p;
			ft_printf("{green}un processus dit que le joueur");
			ft_printf(" %d(%s) est en vie\n{eoc}", id_p, c->p[i].name);
		}

	ft_printf("\t\tid_p: %#x | %d\ttotal_live_payer: %u\n", id_p, id_p, c->p[i - 1].total_live);//
	ft_printf("\t{green}{bold}END\tLIVE\n{eoc}");//

	p->pc = id(p->pc + *p->l);
}

void				_ex_ld(t_core *c, t_process *p)
{
	ft_printf("\t{green}{bold}IN\tLD (charge p_1 dans p->reg[reg] + carry)\n{eoc}");//

	unsigned char	reg;

	c->v[5](c, p, 0);
	if (!(reg = c->v[p->ins.param[1]](c, p, p->l[2])) || reg > 16)
		return ((void)(p->pc = id(p->pc + *p->l)));

	ft_printf("p->reg[%2hhu]:\t%#x\n", reg, p->reg[reg]);

	p->reg[reg] = c->v[*p->ins.param](c, p, p->l[1]);

	ft_printf("\t\tp->reg[%2hhu]: %#x\n", reg, p->reg[reg]);

	p->carry = p->reg[reg] ? 0 : 1;
	p->pc = id(p->pc + *p->l);

	ft_printf("\t{green}{bold}END\tLD\n{eoc}");//
}

void				_ex_st(t_core *c, t_process *p)
{
	ft_printf("\t{green}{bold}IN\tST (copie p_1 vers p_2)\n{eoc}");//

	int				i;
	unsigned char	p_1;
	int				p_2;

	c->v[5](c, p, 0);
	i = -1;
	if (!(p_1 = c->v[*p->ins.param](c, p, p->l[1])) || p_1 > 16)
		return ((void)(p->pc = id(p->pc + *p->l)));

	ft_printf("p->reg[%hhu]: %#x\n", p_1, p->reg[p_1]);//

	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ((void)(p->pc = id(p->pc + *p->l)));
	if (p->ins.param[1] & T_REG)
	{//
		p->reg[p_2] = p->reg[p_1];

		ft_printf("\t\tp_2 = %hu\tp_2 = %#x\n", p_2, p->reg[p_2]);//

	}//
	else
	{

		ft_printf("\t\t{yellow}(addr)p_2 = %#x(hex) %4hd{eoc}", p_2, p_2);//

		p_2 = id(p->pc + (p_2 % IDX_MOD)); //cast ou pas?? that is the question

		ft_printf("\t\t{green}(addr)p_2 = %#x(hex) %4hd\n{eoc}", p_2, p_2);//

		while (++i < 4)
			c->ram[id(p_2 + i)] = (p->reg[p_1] >> (24 - (i * 8))) & 0xff;
	}
	p->pc = id(p->pc + *p->l);

	ft_printf("\t{green}{bold}END\tST\n{eoc}");//
}

void				_ex_add(t_core *c, t_process *p)
{
	ft_printf("\t{green}{bold}IN\tADD{eoc}\n");//

	unsigned char	p_1;
	unsigned char	p_2;
	unsigned char	p_3;

	c->v[5](c, p, 0);
	if (!(p_1 = c->v[1](c, p, p->l[1])) || p_1 > 16)
		return ((void)(p->pc = id(p->pc + *p->l)));
	if (!(p_2 = c->v[1](c, p, p->l[2])) || p_2 > 16)
		return ((void)(p->pc = id(p->pc + *p->l)));
	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_2 > 16)
		return ((void)(p->pc = id(p->pc + *p->l)));

	ft_printf("\t\tp_1: %u | %#x\tp->reg[p_1]: %#x\n\t\tp_2: %u | %#x\tp->reg[p_2]: %#x\n\t\tp_3: %u | %#x\tp->reg[o_3]: %#x\n\t\tp->reg[p_1] + p->reg[p_2]: %u\n", p_1, p_1, p->reg[p_1], p_2, p_2, p->reg[p_2], p_3, p_3, p->reg[p_3], p->reg[p_2] + p->reg[p_1]);//

	p->reg[p_3] = p->reg[p_1] + p->reg[p_2];

	ft_printf("\t\tp->reg[p_3]: %u | %p\n", p->reg[p_3], p->reg[p_3]);//

	p->carry = (p->reg[p_3] == 0);
	p->pc = id(p->pc + *p->l);

	ft_printf("\t{green}{bold}END\tADD{eoc}\n");//
}

void				_ex_sub(t_core *c, t_process *p)
{
	ft_printf("\t{green}{bold}IN\tSUB{eoc}\n");//

	unsigned char	p_1;
	unsigned char	p_2;
	unsigned char	p_3;

	c->v[5](c, p, 0);
	if (!(p_1 = c->v[1](c, p, p->l[1])) || p_1 > 16)
		return ((void)(p->pc = id(p->pc + *p->l)));
	if (!(p_2 = c->v[1](c, p, p->l[2])) || p_2 > 16)
		return ((void)(p->pc = id(p->pc + *p->l)));
	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_3 > 16)
		return ((void)(p->pc = id(p->pc + *p->l)));
	p->reg[p_3] = p->reg[p_1] - p->reg[p_2];
	p->carry = (p->reg[p_3] == 0);
	p->pc = id(p->pc + *p->l);

	ft_printf("\t{green}{bold}END\tSUB{eoc}\n");//
}
