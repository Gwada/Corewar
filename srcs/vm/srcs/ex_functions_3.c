/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/10 20:26:45 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void				_ex_sti(t_core *c, t_process *p)
{
	unsigned char	p_1;
	int				p_2;
	int				p_3;

	c->v[5](c, p, 0);
	if (!(p_1 = c->v[1](c, p, p->l[1])) || p_1 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2]: 0;
	p_3 = c->v[p->ins.param[2]](c, p, p->l[3]);
	if (p->ins.param[2] & T_REG && (!p_3 || p_3 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->ins.param[2] & T_REG ? p_3 = p->reg[p_3]: 0;
	p_2 = c->v[0](c, p, p_2 + p_3);
//	ft_psprintf(c->buff, "%x to p->pc + (%d %% IDX_MOD)\n", p->reg[p_1], p_2);//
	p_3 = -1;
	while (++p_3 < 4)
	{
		c->ram[id(p_2 + p_3)] = (p->reg[p_1] >> (24 - (p_3 * 8))) & 0xff;
		c->r_2[id(p_2 + p_3)] &= ~(0xff);
		c->r_2[id(p_2 + p_3)] |= ((1 << (*p->reg - 1)) | (1 << 5));
	}
	p->pc = moov_opc(c, p, *p->l);
}

void				_ex_fork(t_core *c, t_process *p)
{
	t_process		*new;

	if (!(new = new_process(c)))
	{
		clean_process(c->ps);
		display_error(c, 0, NULL);
		exit(EXIT_FAILURE);
	}
	c->v[5](c, p, 0);
	*new = *p;
	new->prev = NULL;
	new->next = c->ps;
	c->ps->prev = new;
	c->ps = new;
	if (c->bd & DEBUG)
		ft_printf("fork pc + (%hd %% IDX_MOD)\n", c->v[3](c, p, p->l[1]));
	new->pc = id(p->pc + (c->v[3](c, p, p->l[1]) % IDX_MOD));
	c->r_2[new->pc] |= OPC;
	read_instruct(c, new);
	p->pc = moov_opc(c, p, *p->l);
	--new->ins.nb_cycles;
}

void				_ex_lld(t_core *c, t_process *p)
{
//	ft_printf("\t{green}{bold}IN\tLLD\n{eoc}");//

	unsigned char	reg;

	c->v[5](c, p, 0);
	if (!(reg = c->v[1](c, p, p->l[2])) || reg > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->reg[reg] = c->v[*p->ins.param](c, p, p->l[1]);
	p->carry = p->reg[reg] ? 0 : 1;
	p->pc = moov_opc(c, p, *p->l);

//	ft_printf("\t{green}{bold}END\tLLD\n{eoc}");//
}

void				_ex_lldi(t_core *c, t_process *p)
{
//	ft_printf("\t{green}{bold}IN\tLLDI\n{eoc}");//

	int				i;
	int				p_1;
	int				p_2;
	unsigned char	p_3;

	i = -1;
	c->v[5](c, p, 0);
	p_1 = c->v[*p->ins.param](c, p, p->l[1]);
	if (*p->ins.param & T_REG && (!p_1 || p_1  > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_3 > 16)
		return ((void)(p->pc = moov_opc(c, p, *p->l)));
	p_2 = c->v[0](c, p, p_2 + p_1);
	while (++i < 4)
		p->reg[p_3] = (p->reg[p_3] << 8) | c->ram[id(p_2 + i)];
	p->pc = moov_opc(c, p, *p->l);
	p->carry = p->reg[p_3] ? 0 : 1;

//	ft_printf("\t{green}{bold}END\tLLDI\n{eoc}");//
}

void				_ex_lfork(t_core *c, t_process *p)
{
	t_process		*new;

	if (!(new = new_process(c)))
	{
		clean_process(c->ps);
		display_error(c, 0, NULL);
		exit(EXIT_FAILURE);
	}
	c->v[5](c, p, 0);
	*new = *p;
	new->next = c->ps;
	new->prev = NULL;
	c->ps->prev = new;
	c->ps = new;
	if (c->bd & DEBUG)
		ft_printf("lfork pc + %hd\n", c->v[*p->ins.param](c, p, p->l[1]));
	new->pc = id(p->pc + c->v[*p->ins.param](c, p, p->l[1]));
	c->r_2[new->pc]	|= OPC;
	read_instruct(c, new);
	p->pc = moov_opc(c, p, *p->l);
	--new->ins.nb_cycles;
}
