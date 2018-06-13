/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/13 13:20:23 by dlavaury         ###   ########.fr       */
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
	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	p_3 = c->v[1](c, p, p->l[3]);
	if ((*p->ins.param & T_REG && (p_1 < 1 || p_1 > 16))
	|| (p->ins.param[1] & T_REG && (p_2 < 1 || p_2 > 16)) || !p_3 || p_3 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	if (c->bd & DEBUG)
	{
		ft_printf("and %s%d ", *p->ins.param & T_REG ? "" : "r", p_1);
		ft_printf("%s%d r%hhu\n", p->ins.param[1] & T_REG ? "r" : "", p_2, p_3);
	}
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
	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	p_3 = c->v[1](c, p, p->l[3]);
	if ((*p->ins.param & T_REG && (p_1 < 1 || p_1 > 16))
	|| (p->ins.param[1] & T_REG && (p_2 < 1 || p_2 > 16)) || !p_3 || p_3 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	if (c->bd & DEBUG)
	{
		ft_printf("or %s%d ", *p->ins.param & T_REG ? "" : "r", p_1);
		ft_printf("%s%d r%hhu\n", p->ins.param[1] & T_REG ? "r" : "", p_2, p_3);
	}
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
	c->v[5](c, p, 0);
	p_1 = c->v[*p->ins.param](c, p, p->l[1]);
	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	p_3 = c->v[1](c, p, p->l[3]);
	if ((*p->ins.param & T_REG && (p_1 < 1 || p_1 > 16))
	|| (p->ins.param[1] & T_REG && (p_2 < 1 || p_2 > 16)) || !p_3 || p_3 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	if (c->bd & DEBUG)
	{
		ft_printf("xor %s%d ", *p->ins.param & T_REG ? "" : "r", p_1);
		ft_printf("%s%d r%hhu\n", p->ins.param[1] & T_REG ? "r" : "", p_2, p_3);
	}
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
	short			p_1;
	short			p_2;
	unsigned char	p_3;

	c->v[5](c, p, 0);
	p_1 = c->v[*p->ins.param](c, p, p->l[1]);
	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	p_3 = c->v[1](c, p, p->l[3]);
	if ((*p->ins.param & T_REG && (p_1 < 1 || p_1 > 16))
	|| (p->ins.param[1] & T_REG && (p_2 < 1 || p_2 > 16)) || !p_3 || p_3 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	if (c->bd & DEBUG)
	{
		ft_printf("ldi %hd %d r%hhu\t\t", p_1, p_2 , p_3);
		ft_printf("load from %d to r%hhu\n", p->pc + p_1 + p_2, p_3);
	}
	p_2 = c->v[0](c, p, p_2 + p_1);
	p_1 = -1;
	while (++p_1 < 4)
		p->reg[p_3] = (p->reg[p_3] << 8) | c->ram[id(p_2 + p_1)];
	p->pc = moov_opc(c, p, *p->l);
}
