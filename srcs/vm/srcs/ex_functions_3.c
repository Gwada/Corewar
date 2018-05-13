/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/13 20:34:55 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void			_ex_sti(t_core *c, t_process *p)
{
	int			i;
	unsigned	p_1;
	unsigned	p_2;
	unsigned	p_3;

	i = -1;
	p_1 = 0;
	p_2 = 0;
	p_3 = 0;
	if ((p_1 = c->v[1](c, p, 2)) > 15)
		return ;
	p_1 = p->reg[p_1];
//	ft_printf("p_1 = %p\n", p_1);//
	p_2 = c->v[p->ins.param[1]](c, p, 3);
	if (p->ins.param[1] & T_REG && p_2 > 15)
		return ;
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2]: 0;
//	ft_printf("p_2 = %06p\n", p_2);//
	p_3 = c->v[p->ins.param[2]](c, p, (p->ins.param[1] & T_REG ? 4 : 5));
	if (p->ins.param[2] & T_REG && p_3 > 15)
		return ;
	p->ins.param[2] & T_REG ? p_3 = p->reg[p_3]: 0;
//	ft_printf("p_3 = %06p\n", p_3);//
	p_2 = id(p->pc + ((p_2 + p_3) % IDX_MOD));
//	ft_printf("p->pc + (p_3 + p_2) %% IDX_MOD = %p\n", p_2);//
	while (++i < 4)
		c->ram[c->v[0](c, p, id(p_2 + i))] = (p_1 >> (24 - (i * 8))) & 0xff;
	p->opc = id(p->opc + (p->ins.param[1] & T_REG ? 3 : 4));
	p->opc = id(p->opc + (p->ins.param[2] & T_REG ? 1 : 2));
}

void			_ex_fork(t_core *c, t_process *p)
{
	t_process	*new;

	if (!(new = new_process(c)))
	{
		clean_process(c->ps);
		exit(EXIT_FAILURE);
	}
	p->opc = id(p->opc + 2);
	*new = *p;
	new->pc = id((p->pc + c->v[4](c, p, 1)) % IDX_MOD);
	read_instruct(c, new);
	insert_process(&c->ps, new);
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
	p->opc = id(p->opc + (*p->ins.param & T_DIR ? 6 : 4));
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
	p->opc = id(p->opc + id_o);
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
	p->opc = id(p->opc + 3);
	*new = *p;
	new->pc = id(c->v[4](c, p, 1));
	insert_process(&c->ps, new);
}
