/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/15 13:25:38 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void			_ex_sti(t_core *c, t_process *p)
{
	ft_printf("\t{green}{bold}IN\tSTI\n{eoc}");//
//	ft_print_mem(&c->ram, MEM_SIZE, 64, 0);//
	int			i;
	unsigned	p_1;
	unsigned	p_2;
	unsigned	p_3;

	c->v[5](c, p, 0);
	i = -1;
	p_1 = 0;
	p_2 = 0;
	p_3 = 0;
	if ((p_1 = c->v[1](c, p, p->l[1])) > 15)
		return ((void)(p->pc = id(p->pc + *p->l)));
	p_1 = p->reg[p_1 - 1];

//	ft_printf("\t\tp_1 = %p\n", p_1);//

	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && p_2 > 15)
		return ((void)(p->pc = id(p->pc + *p->l)));
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2 - 1]: 0;

//	ft_printf("\t\tp_2 = %06p\n", p_2);//

	p_3 = c->v[p->ins.param[2]](c, p, p->l[3]);
	if (p->ins.param[2] & T_REG && p_3 > 15)
		return ((void)(p->pc = id(p->pc + *p->l)));
	p->ins.param[2] & T_REG ? p_3 = p->reg[p_3 - 1]: 0;

//	ft_printf("\t\tp_3 = %06p\n", p_3);//

	p_2 = id(p->pc + ((p_2 + p_3) % IDX_MOD));

//	ft_printf("\t\tp->pc + (p_3 + p_2) %% IDX_MOD = %p\n", p_2);//

	while (++i < 4)
		c->ram[id(p_2 + i)] = (p_1 >> (24 - (i * 8))) & 0xff;
	p->pc = id(p->pc + *p->l);
//	ft_print_mem(&c->ram, MEM_SIZE, 64, 0);//
	ft_printf("\t{green}{bold}END\tSTI\n{eoc}");//
}

void			_ex_fork(t_core *c, t_process *p)
{
	ft_printf("{green}{bold}IN\tFORK\n{eoc}");//
	t_process	*new;

	if (!(new = new_process(c)))
	{
		clean_process(c->ps);
		exit(EXIT_FAILURE);
	}
	p->pc = id(p->pc + 2);
	*new = *p;
	new->pc = id(new->pc + (c->v[3](c, p, 1) % IDX_MOD));
	ft_printf("new->pc %p %u\n", new->pc, new->pc);//
	new->pc = id(new->pc + 1);
	read_instruct(c, new);
	insert_process(c, new);
	ft_printf("{green}{bold}END\tFORK\n{eoc}");//
}

void			_ex_lld(t_core *c, t_process *p)
{
	int			i;
	unsigned	p_1;
	unsigned	p_2;

	i = -1;
	p_1 = c->v[*p->ins.param](c, p, 2);
	p_2 = *p->ins.param & T_DIR ? c->v[1](c, p, 6) : c->v[1](c, p, 4);
	if (p_2 > 15)
		return ;
	p->reg[p_2] = p_1;
	p->carry = p->carry ? 0 : 1;
	p->pc = id(p->pc + (*p->ins.param & T_DIR ? 6 : 4));
}

void			_ex_lldi(t_core *c, t_process *p)
{
	unsigned	id_o;
	unsigned	p_1;
	unsigned	p_2;
	unsigned	p_3;

	id_o = 2;
	p_1 = c->v[*p->ins.param](c, p, id_o++);
	if (*p->ins.param & T_REG && p_1  > 15)
		return ;
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : ++id_o;
	p_2 = c->v[p->ins.param[1]](c, p, id_o++);
	if (p->ins.param[1] & T_REG && p_2 > 15)
		return ;
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : ++id_o;
	if ((p_3 = c->v[1](c, p, id_o)) > 15)
		return ;
	p->reg[p_3] = c->v[2](c, p, p_2 + p_1);
	p->pc = id(p->pc + id_o);
	p->carry = p->carry ? 0 : 1;
}

void			_ex_lfork(t_core *c, t_process *p)
{
	t_process	*new;

	if (!(new = new_process(c)))
	{
		clean_process(c->ps);
		exit(EXIT_FAILURE);
	}
	p->pc = id(p->pc + 2);
	*new = *p;
	new->pc = id(c->v[3](c, p, 1));
	new->pc = id(p->pc + 1);
	insert_process(c, new);
}
