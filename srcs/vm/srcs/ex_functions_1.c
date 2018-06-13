/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/13 15:19:51 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void				ex_live(t_core *c, t_process *p)
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
				ft_printf("{green}un processus dit que le joueur %d", -id_p);
				c->bd & DEBUG ? ft_printf("(%s) est en vie{eoc}", c->p[i].name)
				: ft_printf("(%s) est en vie{eoc}\n", c->p[i].name);
			}
		}
	c->bd & DEBUG && !(c->bd & VISUAL) ? ft_printf("\n") : 0;
	c->bd & VISUAL ? visu(c, 3, p, id(p->pc + *p->l), id_p) : 0;
	p->pc = moov_opc(c, p, *p->l);
}

void				ex_ld(t_core *c, t_process *p)
{
	unsigned char	reg;

	c->v[5](c, p, 0);
	if (!(reg = c->v[p->ins.param[1]](c, p, p->l[2])) || reg > 16)
	{
		c->bd & DEBUG ? ft_printf("invalid reg: %hhu\n", reg) : 0;
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	}
	p->reg[reg] = c->v[*p->ins.param](c, p, p->l[1]);
	c->bd & DEBUG ? ft_printf("ld %d r%hhu", p->reg[reg], reg) : 0;
	p->carry = (p->reg[reg] == 0);
	c->bd & DEBUG ? ft_printf("\tcarry = %d\n", p->carry) : 0;
	c->bd & VISUAL ? visu(c, 5, p, id(p->pc + *p->l), 0) : 0;
	p->pc = moov_opc(c, p, *p->l);
}

void				ex_st(t_core *c, t_process *p)
{
	int				i;
	unsigned char	p_1;
	short			p_2;

	c->v[5](c, p, 0);
	i = -1;
	p_1 = c->v[*p->ins.param](c, p, p->l[1]);
	p_2 = c->v[p->ins.param[1] & T_REG ? 1 : 3](c, p, p->l[2]);
	if (!p_1 || p_1 > 16 || (p->ins.param[1] & T_REG && (p_2 < 1 || p_2 > 16)))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->ins.param[1] & T_REG ? p->reg[p_2] = p->reg[p_1] : 0;
	if (c->bd & DEBUG && p->ins.param[1] & T_REG)
		ft_printf("st r%hhu -> r%hu (%#x)\n", p_1, p_2, p->reg[1]);
	if (c->bd & DEBUG && !(p->ins.param[1] & T_REG))
		ft_printf("st r%hhu -> pc + (%#hd %% IDX_MOD)\n", p_1, p_2);
	!(p->ins.param[1] & T_REG) ? p_2 = id(p->pc + (p_2 % IDX_MOD)) : 0;
	if (!(p->ins.param[1] & T_REG))
		while (++i < 4)
		{
			c->ram[id(p_2 + i)] = (p->reg[p_1] >> (24 - (i * 8))) & 0xff;
			c->r_2[id(p_2 + i)] &= ~(0xff);
			c->r_2[id(p_2 + i)] |= ((1 << (*p->reg - 1)) | (1 << 5));
		}
	c->bd & VISUAL ? visu(c, 4, p, id(p->pc + *p->l), id(p_2)) : 0;
	p->pc = moov_opc(c, p, *p->l);
}

void				ex_add(t_core *c, t_process *p)
{
	unsigned char	p_1;
	unsigned char	p_2;
	unsigned char	p_3;

	c->v[5](c, p, 0);
	p_1 = c->v[1](c, p, p->l[1]);
	p_2 = c->v[1](c, p, p->l[2]);
	p_3 = c->v[1](c, p, p->l[3]);
	if (!p_1 || !p_2 || !p_3 || p_1 > 16 || p_2 > 16 || p_3 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	if (c->bd & DEBUG)
		ft_printf("add r%hhu r%hhu r%hhu\n", p_1, p_2, p_3);
	p->reg[p_3] = p->reg[p_1] + p->reg[p_2];
	p->carry = (p->reg[p_3] == 0);
	c->bd & VISUAL ? visu(c, 5, p, id(p->pc + *p->l), 0) : 0;
	p->pc = moov_opc(c, p, *p->l);
}

void				ex_sub(t_core *c, t_process *p)
{
	unsigned char	p_1;
	unsigned char	p_2;
	unsigned char	p_3;

	c->v[5](c, p, 0);
	p_1 = c->v[1](c, p, p->l[1]);
	p_2 = c->v[1](c, p, p->l[2]);
	p_3 = c->v[1](c, p, p->l[3]);
	if (!p_1 || !p_2 || !p_3 || p_1 > 16 || p_2 > 16 || p_3 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	if (c->bd & DEBUG)
		ft_printf("sub r%hhu r%hhu r%hhu\n", p_1, p_2, p_3);
	p->reg[p_3] = p->reg[p_1] - p->reg[p_2];
	p->carry = (p->reg[p_3] == 0);
	c->bd & VISUAL ? visu(c, 5, p, id(p->pc + *p->l), 0) : 0;
	p->pc = moov_opc(c, p, *p->l);
}
