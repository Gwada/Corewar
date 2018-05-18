/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/17 16:17:11 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void				_ex_sti(t_core *c, t_process *p)
{
	ft_printf("\t{green}{bold}IN\tSTI\n{eoc}");//

	int				i;
	unsigned char	p_1;
	int				p_2;
	int				p_3;

	c->v[5](c, p, 0);
	i = -1;
	if (!(p_1 = c->v[1](c, p, p->l[1])) || p_1 > 16)
		return ((void)(p->pc = id(p->pc + *p->l)));

	ft_printf("\t\tp_1: %hhu\tp->reg[p_1]: %#x\n", p_1, p->reg[p_1]);//

	p_2 = c->v[p->ins.param[1] & T_REG ? 1 : 3](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ((void)(p->pc = id(p->pc + *p->l)));
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2]: 0;

	ft_printf("\t\tp_2 = %#x\n", p_2);//

	p_3 = c->v[p->ins.param[2] & T_REG ? 1 : 3](c, p, p->l[3]);
	if (p->ins.param[2] & T_REG && (!p_3 || p_3 > 16))
		return ((void)(p->pc = id(p->pc + *p->l)));
	p->ins.param[2] & T_REG ? p_3 = p->reg[p_3]: 0;

	ft_printf("\t\tp_3 = %#x\n", p_3);//

	p_2 = c->v[0](c, p, p_2 + p_3);

	ft_printf("\t\tp->pc + (p_3 + p_2) %% IDX_MOD = %#x\n", p_2);//

	while (++i < 4)
		c->ram[id(p_2 + i)] = (p->reg[p_1] >> (24 - (i * 8))) & 0xff;
	p->pc = id(p->pc + *p->l);

	ft_printf("\t{green}{bold}END\tSTI\n{eoc}");//
}

void				_ex_fork(t_core *c, t_process *p)
{
	ft_printf("\t{green}{bold}IN\tFORK (nouv process pareil que le pere sauf new->pc = p->pc + (p_1 % IDX_MOD))\n{eoc}");//

	t_process		*new;

	if (!(new = new_process(c)))
	{
		clean_process(c->ps);
		//fonction affichage errer malloc
		exit(EXIT_FAILURE);
	}
	c->v[5](c, p, 0);
	*new = *p;
	new->pc = id(p->pc + ((short)c->v[3](c, p, p->l[1]) % IDX_MOD));

	ft_printf("\t\tnew->pc %#x %u\n", new->pc, new->pc);//

	read_instruct(c, new);
	p->pc = id(p->pc + *p->l);
	insert_process(c, new);

	ft_printf("\t{green}{bold}END\tFORK\n{eoc}");//
}

void				_ex_lld(t_core *c, t_process *p)
{
	ft_printf("\t{green}{bold}IN\tLLD\n{eoc}");//

	unsigned char	reg;

	c->v[5](c, p, 0);
	if (!(reg = c->v[1](c, p, p->l[2])) || reg > 16)
		return ((void)(p->pc = id(p->pc + *p->l)));
	p->reg[reg] = c->v[*p->ins.param](c, p, p->l[1]);
	p->carry = p->reg[reg] ? 0 : 1;
	p->pc = id(p->pc + *p->l);

	ft_printf("\t{green}{bold}END\tLLD\n{eoc}");//
}

void				_ex_lldi(t_core *c, t_process *p)
{
	ft_printf("\t{green}{bold}IN\tLLDI\n{eoc}");//

	int				p_1;
	int				p_2;
	unsigned char	p_3;

	c->v[5](c, p, 0);
	p_1 = c->v[*p->ins.param](c, p, p->l[1]);
	if (*p->ins.param & T_REG && (!p_1 || p_1  > 16))
		return ((void)(p->pc = id(p->pc + *p->l)));
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;

	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ((void)(p->pc = id(p->pc + *p->l)));
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;

	if (!(p_3 = c->v[1](c, p, p->l[3])) || p_3 > 16)
		return ((void)(p->pc = id(p->pc + *p->l)));
	p->reg[p_3] = c->v[2](c, p, p_2 + p_1);
	p->pc = id(p->pc + *p->l);
	p->carry = p->reg[p_3] ? 0 : 1;

	ft_printf("\t{green}{bold}END\tLLDI\n{eoc}");//
}

void				_ex_lfork(t_core *c, t_process *p)
{
	ft_printf("\t{green}{bold}IN\tFORK (nouv process pareil que le pere sauf new->pc = p->pc + p_1)\n{eoc}");//
	t_process		*new;

	if (!(new = new_process(c)))
	{
		clean_process(c->ps);
		exit(EXIT_FAILURE);
	}
	c->v[5](c, p, 0);
	*new = *p;
	new->pc = id(p->pc + (short)c->v[3](c, p, p->l[1]));

	ft_printf("\t\tnew->pc %#x %u\n", new->pc, new->pc);//

	read_instruct(c, new);
	p->pc = id(p->pc + *p->l);
	insert_process(c, new);

	ft_printf("\t{green}{bold}END\tFORK\n{eoc}");//
}
