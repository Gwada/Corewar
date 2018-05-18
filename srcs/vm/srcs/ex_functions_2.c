/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/17 16:16:38 by dlavaury         ###   ########.fr       */
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
		return ((void)(p->pc = id(p->pc + *p->l)));

	ft_printf("\t\tp_1: %#x\n", p_1);//

	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;

	ft_printf("\t\tp_1: %#x\n", p_1);//

	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ((void)(p->pc = id(p->pc + *p->l)));

	ft_printf("\t\tp_2: %#x\n", p_2);//

	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;

	ft_printf("\t\tp_2: %#x\n", p_2);//

	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_3 > 16)
		return ((void)(p->pc = id(p->pc + *p->l)));

	ft_printf("\t\t1 p_3: %#x\n", p_3);//
	ft_printf("\t\t1 p_3: %#x\n", p->reg[p_3]);//

	p->reg[p_3] = p_1 & p_2;

	ft_printf("\t\t2 p_3: %#x\n", p->reg[p_3]);//

	p->carry = p->reg[p_3] ? 0 : 1;
	p->pc = id(p->pc + *p->l);

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
		return ((void)(p->pc = id(p->pc + *p->l)));
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ((void)(p->pc = id(p->pc + *p->l)));
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_3 > 16)
		return ((void)(p->pc = id(p->pc + *p->l)));
	p->reg[p_3] = p_1 | p_2;
	p->carry = p->reg[p_3] ? 1 : 0;
	p->pc = id(p->pc + *p->l);

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
		return ((void)(p->pc = id(p->pc + *p->l)));
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ((void)(p->pc = id(p->pc + *p->l)));
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_3 > 16)
		return ((void)(p->pc = id(p->pc + *p->l)));
	p->reg[p_3] = p_1 ^ p_2;
	p->carry = p->reg[p_3] ? 0 : 1;
	p->pc = id(p->pc + *p->l);

	ft_printf("{green}{bold}\tEND\tXOR{eoc}\n");//
}

void				_ex_zjmp(t_core *c, t_process *p)
{
	ft_printf("{green}{bold}\tIN\tZJMP (si carry == 1 charge p->pc en p->pc + (p_1 %% IDX_MOD)){eoc}\n");//
	ft_printf("\t\tp->pc: %#x\n", p->pc);

	c->v[5](c, p, 0);
	if (p->carry == 1)
		p->pc = id(p->pc + ((short)c->v[3](c, p, p->l[1]) % IDX_MOD));
	else
		p->pc = id(p->pc + *p->l);

	ft_printf("\t\tp->pc: %#x\n", p->pc);
	ft_printf("{green}{bold}\tEND\tZJMP{eoc}\n");//
}

void				_ex_ldi(t_core *c, t_process *p)
{
	ft_printf("{green}{bold}\tIN\tLDI{eoc}\n");//

	int				p_1;
	int				p_2;
	unsigned char	p_3;

	c->v[5](c, p, 0);
	p_1 = c->v[*p->ins.param](c, p, p->l[1]);
	if (*p->ins.param & T_REG && (!p_1 || p_1 > 16))
		return ((void)(p->pc = id(p->pc + *p->l)));
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;

	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ((void)(p->pc = id(p->pc + *p->l)));
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;

	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_3 > 16)
		return ((void)(p->pc = id(p->pc + *p->l)));
	p->reg[p_3] = c->v[2](c, p, (p_2 + p_1) % IDX_MOD);
	p->pc = id(p->pc + *p->l);

	ft_printf("{green}{bold}\tEND\tLDI{eoc}\n");//
}
