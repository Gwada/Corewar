/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/10 18:05:18 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void				_ex_and(t_core *c, t_process *p)
{
	ft_printf("{green}{bold}\tIN\tAND{eoc}\n");//

	int				p_1;
	int				p_2;
	unsigned char	p_3;

	c->v[5](c, p, 0);
	p_1 = c->v[*p->ins.param](c, p, p->l[1]);
	if (*p->ins.param & T_REG && (!p_1 || p_1 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_3 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->reg[p_3] = p_1 & p_2;
	p->carry = (p->reg[p_3] == 0);
	p->pc = moov_opc(c, p, *p->l);


	ft_printf("{green}{bold}\tEND\tAND{eoc}\n");//
}

void				_ex_or(t_core *c, t_process *p)
{
	ft_printf("{green}{bold}\tIN\tOR{eoc}\n");//

	int				p_1;
	int				p_2;
	unsigned char	p_3;

	c->v[5](c, p, 0);
	p_1 = c->v[*p->ins.param](c, p, p->l[1]);
	if (*p->ins.param & T_REG && (!p_1 || p_1 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_3 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->reg[p_3] = p_1 | p_2;
	p->carry = (p->reg[p_3] == 0);
	p->pc = moov_opc(c, p, *p->l);

	ft_printf("{green}{bold}\tEND\tOR{eoc}\n");//
}

void		_ex_xor(t_core *c, t_process *p)
{
	ft_printf("{green}{bold}\tIN\tXOR{eoc}\n");//

	int				p_1;
	int				p_2;
	unsigned char	p_3;

	c->v[5](c, p, 0);
	p_1 = c->v[*p->ins.param](c, p, p->l[1]);
	if (*p->ins.param & T_REG && (!p_1 || p_1 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_3 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->reg[p_3] = p_1 ^ p_2;
	p->carry = (p->reg[p_3] == 0);
	p->pc = moov_opc(c, p, *p->l);

	ft_printf("{green}{bold}\tEND\tXOR{eoc}\n");//
}

void				_ex_zjmp(t_core *c, t_process *p)
{
	ft_printf("{green}{bold}\tIN\tZJMP (si carry == 1 charge p->pc en p->pc + (p_1 %% IDX_MOD)){eoc}\n\t\tp->pc: %#x\n", p->pc);//

	c->v[5](c, p, 0);
	if (p->carry == 1)
	{
		c->r_2[p->pc] &= ~OPC;
		p->pc = id(p->pc + (c->v[3](c, p, p->l[1]) % IDX_MOD));
		c->r_2[p->pc] |= OPC;
		ft_printf("\t\t{green}OK{eoc}\n");
	}
	else
	{
		p->pc = moov_opc(c, p, *p->l);
		ft_printf("\t\t{red}FAILED{eoc}\n");
	}

	ft_printf("\t\tp->pc: %#x\t%d\n{green}{bold}\tEND\tZJMP{eoc}\n", p->pc, p->pc);
}

void				_ex_ldi(t_core *c, t_process *p)
{
	ft_printf("{green}{bold}\tIN\tLDI{eoc}\n");//

	int				i;
	int				p_1;
	int				p_2;
	unsigned char	p_3;

	i = -1;
	c->v[5](c, p, 0);
	p_1 = c->v[*p->ins.param](c, p, p->l[1]);
	if (*p->ins.param & T_REG && (!p_1 || p_1 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_3 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p_2 = (short)c->v[0](c, p, p_2 + p_1); //cast?
	while (++i < 4)
		p->reg[p_3] = (p->reg[p_3] << 8) | c->ram[id((short)p_2 + i)]; //cast?
	p->pc = moov_opc(c, p, *p->l);

	ft_printf("{green}{bold}\tEND\tLDI{eoc}\n");//
}
