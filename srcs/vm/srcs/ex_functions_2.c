/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/12 20:32:43 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void				_ex_and(t_core *c, t_process *p)
{
	int				p_1;
	int				p_2;
	unsigned char	p_3;

	c->v[5](c, p, 0);
	p_1 = c->v[*p->ins.param](c, p, p->l[1]);
	if (*p->ins.param & T_REG && (p_1 < 1 || p_1 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && (p_2 < 1 || p_2 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_3 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->reg[p_3] = p_1 & p_2;
	p->carry = (p->reg[p_3] == 0);
	p->pc = moov_opc(c, p, *p->l);
}

void				_ex_or(t_core *c, t_process *p)
{
	int				p_1;
	int				p_2;
	unsigned char	p_3;

	c->v[5](c, p, 0);
	p_1 = c->v[*p->ins.param](c, p, p->l[1]);
	if (*p->ins.param & T_REG && (p_1 < 1 || p_1 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && (p_2 < 1 || p_2 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_3 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->reg[p_3] = p_1 | p_2;
	p->carry = (p->reg[p_3] == 0);
	p->pc = moov_opc(c, p, *p->l);
}

void		_ex_xor(t_core *c, t_process *p)
{
	int				p_1;
	int				p_2;
	unsigned char	p_3;

	c->v[5](c, p, 0);
	p_1 = c->v[*p->ins.param](c, p, p->l[1]);
	if (*p->ins.param & T_REG && (p_1 < 1 || p_1 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && (p_2 < 1 || p_2 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_3 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->reg[p_3] = p_1 ^ p_2;
	p->carry = (p->reg[p_3] == 0);
	p->pc = moov_opc(c, p, *p->l);
}

void				_ex_zjmp(t_core *c, t_process *p)
{
	c->v[5](c, p, 0);
	if (p->carry == 1)
	{
		c->r_2[p->pc] &= ~OPC;
		if (c->bd & DEBUG)
			ft_printf("zjmp %d {green}OK{eoc}\n", c->v[3](c, p, p->l[1]));
		p->pc = moov_opc(c, p, c->v[3](c, p, p->l[1]) % IDX_MOD);
		c->r_2[p->pc] |= OPC;
	}
	else
	{
		if (c->bd & DEBUG)
			ft_printf("zjmp %d {red}FAILED{eoc}\n", c->v[3](c, p, p->l[1]));
		p->pc = moov_opc(c, p, *p->l);
	}
}

void				_ex_ldi(t_core *c, t_process *p)
{
//	ft_printf("{green}{bold}\tIN\tLDI{eoc}\n");//

	int				i;
	int				p_1;
	int				p_2;
	unsigned char	p_3;

	i = -1;
	c->v[5](c, p, 0);
	p_1 = c->v[*p->ins.param](c, p, p->l[1]);
	if (*p->ins.param & T_REG && (p_1 < 1 || p_1 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && (p_2 < 1 || p_2 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_3 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p_2 = (short)c->v[0](c, p, p_2 + p_1);
	while (++i < 4)
		p->reg[p_3] = (p->reg[p_3] << 8) | c->ram[id((short)p_2 + i)];
	p->pc = moov_opc(c, p, *p->l);
}
