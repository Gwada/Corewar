/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/15 13:30:58 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void				_ex_and(t_core *c, t_process *p)
{
	ft_printf("{green}{bold}\tIN\tAND{eoc}\n");//
//	ft_print_mem(&c->ram, MEM_SIZE, 64, 0);//
	
	unsigned int	p_1;
	unsigned int	p_2;
	unsigned int	p_3;

	c->v[5](c, p, 0);
	p_1 = c->v[*p->ins.param](c, p, p->l[1]);
	if (*p->ins.param & T_REG && p_1 > 15)
		return ((void)(p->pc = id(p->pc + *p->l)));

//	ft_printf("p_1: %#x\n", p_1);//

	*p->ins.param & T_REG ? p_1 = p->reg[p_1 - 1] : 0;

//	ft_printf("p_1: %#x\n", p_1);//

	p_2 = c->v[p->ins.param[1]](c, p, p->l[2]);
	if (p->ins.param[1] & T_REG && p_2 > 15)
		return ((void)(p->pc = id(p->pc + *p->l)));

//	ft_printf("p_2: %#x\n", p_2);//

	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2 - 1] : 0;

//	ft_printf("p_2: %#x\n", p_2);//

	if ((p_3 = c->v[1](c, p, p->l[3])) > 15)
		return ((void)(p->pc = id(p->pc + *p->l)));

//	ft_printf("1 p_3: %#x\n", p_3);//
//	ft_printf("1 p_3: %#x\n", p->reg[p_3 - 1]);//

	p->reg[p_3 - 1] = p_1 & p_2;

//	ft_printf("2 p_3: %#x\n", p->reg[p_3 - 1]);//

	p->carry = p->carry ? 0 : 1;
	p->pc = id(p->pc + *p->l);
//	ft_print_mem(&c->ram, MEM_SIZE, 64, 0);//
	ft_printf("{green}{bold}\tEND\tAND{eoc}\n");//
}

void				_ex_or(t_core *c, t_process *p)
{
	unsigned int	id_o;
	unsigned int	p_1;
	unsigned int	p_2;
	unsigned int	p_3;

	id_o = 2;
	p_1 = c->v[*p->ins.param](c, p, id_o++);
	if (*p->ins.param & T_REG && p_1 > 15)
		return ;
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	*p->ins.param & T_DIR ? id_o += 3 : 0;
	*p->ins.param & T_IND ? ++id_o : 0;
	p_2 = c->v[p->ins.param[1]](c, p, id_o++);
	if (p->ins.param[1] & T_REG && p_2 > 15)
		return ;
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	p->ins.param[1] & T_DIR ? id_o += 3 : 0;
	p->ins.param[1] & T_IND ? ++id_o : 0;
	if (!(p_3 = c->v[1](c, p, id_o)) || p_3 > 16)
		return ;
	p->reg[p_3] = p_1 | p_2;
	p->carry = p->carry ? 0 : 1;
	p->pc = id(p->pc + id_o);
}

void		_ex_xor(t_core *c, t_process *p)
{
	unsigned int	id_o;
	unsigned int	p_1;
	unsigned int	p_2;
	unsigned int	p_3;

	id_o = 2;
	p_1 = c->v[*p->ins.param](c, p, id_o++);
	if (*p->ins.param & T_REG && p_1 > 15)
		return ;
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	*p->ins.param & T_DIR ? id_o += 3 : 0;
	*p->ins.param & T_IND ? ++id_o : 0;
	p_2 = c->v[p->ins.param[1]](c, p, id_o++);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ;
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	p->ins.param[1] & T_DIR ? id_o += 3 : 0;
	p->ins.param[1] & T_IND ? ++id_o : 0;
	if (!(p_3 = c->v[1](c, p, id_o)) || p_3 > 16)
		return ;
	p->reg[p_3] = p_1 ^ p_2;
	p->carry = p->carry ? 0 : 1;
	p->pc = id(p->pc + id_o);
}

void				_ex_zjmp(t_core *c, t_process *p)
{
	if (p->carry == 1)
	{
		ft_printf("\np->opc = %p ind = %u\n", p->pc, p->pc);//
		p->pc = id(p->pc + (c->v[3](c, p, 1) % IDX_MOD) - 1);
		ft_printf("p->opc = %p ind = %u\n", p->pc, p->pc);//
		ft_printf("IDX_MOD = %p ind = %u\n\n", IDX_MOD, IDX_MOD);//
	}
	else
		p->pc = id(p->pc + 3);
}

void		_ex_ldi(t_core *c, t_process *p)
{
	unsigned int	id_o;
	unsigned int	p_1;
	unsigned int	p_2;
	unsigned int	p_3;

	id_o = 2;
	p_1 = c->v[*p->ins.param](c, p, id_o++);
	if (*p->ins.param & T_REG && p_1 > 15)
		return ;
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : ++id_o;
	p_2 = c->v[p->ins.param[1]](c, p, id_o++);
	if (p->ins.param[1] & T_REG && p_2 > 15)
		return ;
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : ++id_o;
	if (!(p_3 = c->v[1](c, p, id_o)) || p_3 > 16)
		return ;
	p->reg[p_3] = c->v[2](c, p, p_2 + p_1);
	p->pc = id(p->pc + id_o);

}
