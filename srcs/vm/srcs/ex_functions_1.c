/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/10 20:35:57 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void				_ex_live(t_core *c, t_process *p)
{
	int				i;
	int				id_p;

	i = -1;
	c->v[5](c, p, 0);
	++c->total_live;
	++p->live;
	++c->current_cycle_live;
	id_p = c->v[2](c, p, p->l[1]);
	c->bd & DEBUG ? ft_printf("live %d\t", id_p) : 0;
	while (++i < 4)
		if (id_p >= -4 && id_p < 0 && id_p == c->p[i].id)
		{
			++c->p[i].total_live;
			++c->p[i].current_cycle_live;
			c->last_live_player = id_p;
			if (!(c->bd & VISUAL))
			{
				ft_printf("{green}un processus dit que le joueur");
				ft_printf(" %d(%s) est en vie\n{eoc}", -id_p, c->p[i].name);
			}
		}
	c->bd & DEBUG && !(c->bd & VISUAL) ? ft_printf("\n") : 0;
	p->pc = moov_opc(c, p, *p->l);
}

void				_ex_ld(t_core *c, t_process *p)
{
	unsigned char	reg;

	c->v[5](c, p, 0);
	if (!(reg = c->v[p->ins.param[1]](c, p, p->l[2])) || reg > 16)
	{
		c->bd & DEBUG ? ft_printf("invalid reg: %hhu\n", reg) : 0;
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	}
	p->reg[reg] = c->v[*p->ins.param](c, p, p->l[1]);
	c->bd & DEBUG ? ft_printf("ld r%hhu %#x\t", reg, p->reg[reg]) : 0;
	p->carry = (p->reg[reg] == 0);
	c->bd & DEBUG ? ft_printf("carry = %d", p->carry) : 0;
	p->pc = moov_opc(c, p, *p->l);
}

void				_ex_st(t_core *c, t_process *p)
{
	int				i;
	unsigned char	p_1;
	short			p_2;

	c->v[5](c, p, 0);
	i = -1;
	p_1 = c->v[*p->ins.param](c, p, p->l[1]);
	p_2 = c->v[p->ins.param[1] & T_REG ? 1 : 3](c, p, p->l[2]);
	if (!p_1 || p_1 > 16 || (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16)))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->ins.param[1] & T_REG ? p->reg[p_2] = p->reg[p_1] : 0;
	if (!(p->ins.param[1] & T_REG))
	{
		p_2 = id(p->pc + (p_2 % IDX_MOD));
		while (++i < 4)
		{
			c->ram[id(p_2 + i)] = (p->reg[p_1] >> (24 - (i * 8))) & 0xff;
			c->r_2[id(p_2 + i)] &= ~(0xff);
			c->r_2[id(p_2 + i)] |= ((1 << (*p->reg - 1)) | (1 << 5));
		}
	}
	p->pc = moov_opc(c, p, *p->l);
	if (c->bd & DEBUG)
		p->ins.param[1] & T_REG ? ft_printf("st r%hd <- r%hhu\n", p_2, p_1) :
	ft_printf("st r%hhu -> pc + (%#hd %% IDX_MOD)\n", p_1, p_2);//
}

void				_ex_add(t_core *c, t_process *p)
{
//	ft_printf("\t{green}{bold}IN\tADD{eoc}\n");//

	unsigned char	p_1;
	unsigned char	p_2;
	unsigned char	p_3;

	c->v[5](c, p, 0);
	if (!(p_1 = c->v[1](c, p, p->l[1])) || p_1 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	if (!(p_2 = c->v[1](c, p, p->l[2])) || p_2 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_2 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));

//	ft_printf("\t\tp_1: %u | %#x\tp->reg[p_1]: %#x\n\t\tp_2: %u | %#x\tp->reg[p_2]: %#x\n\t\tp_3: %u | %#x\tp->reg[o_3]: %#x\n\t\tp->reg[p_1] + p->reg[p_2]: %u\n", p_1, p_1, p->reg[p_1], p_2, p_2, p->reg[p_2], p_3, p_3, p->reg[p_3], p->reg[p_2] + p->reg[p_1]);//

	p->reg[p_3] = p->reg[p_1] + p->reg[p_2];

//	ft_printf("\t\tp->reg[p_3]: %u | %p\n", p->reg[p_3], p->reg[p_3]);//

	p->carry = (p->reg[p_3] == 0);
	p->pc = moov_opc(c, p, *p->l);

//	ft_printf("\t{green}{bold}END\tADD{eoc}\n");//
}

void				_ex_sub(t_core *c, t_process *p)
{
//	ft_printf("\t{green}{bold}IN\tSUB{eoc}\n");//

	unsigned char	p_1;
	unsigned char	p_2;
	unsigned char	p_3;

	c->v[5](c, p, 0);
	if (!(p_1 = c->v[1](c, p, p->l[1])) || p_1 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));

//	ft_printf("p->ref[%hhu]\t%#x\n", p_1, p->reg[p_1]);//

	if (!(p_2 = c->v[1](c, p, p->l[2])) || p_2 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));

//	ft_printf("p->reg[%hhu]\t%#x\n", p_2, p->reg[p_2]);//

	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_3 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));

//	ft_printf("p->reg[%hhu]\t%#x\t", p_3, p->reg[p_3]);//

	p->reg[p_3] = p->reg[p_1] - p->reg[p_2];

//	ft_printf("-> {red}\t%#x{eoc}\n", p->reg[p_3]);//

	p->carry = (p->reg[p_3] == 0);
	p->pc = moov_opc(c, p, *p->l);

//	ft_printf("\t{green}{bold}END\tSUB{eoc}\n");//
}
