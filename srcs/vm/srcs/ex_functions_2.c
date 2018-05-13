/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/13 20:25:28 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void				_ex_and(t_core *c, t_process *p)
{
	int				i;
	unsigned int	p_1;
	unsigned int	p_2;
	unsigned int	p_3;

	i = 2;
	p_1 = c->v[*p->ins.param](c, p, i++);
	if (*p->ins.param & T_REG && p_1 > 15)
		return ;
	*p->ins.param & T_REG ? p_1 = p->reg[p_1] : 0;
	*p->ins.param & T_DIR ? i += 3 : 0;
	*p->ins.param & T_IND ? ++i : 0;
	p_2 = c->v[p->ins.param[1]](c, p, i++);
	if (p->ins.param[1] & T_REG && p_2 > 15)
		return ;
	p->ins.param[1] & T_REG ? p_2 = p->reg[p_2] : 0;
	p->ins.param[1] & T_DIR ? i += 3 : 0;
	p->ins.param[1] & T_IND ? ++i : 0;
	if (!(p_3 = c->v[1](c, p, i)) || p_3 > 16)
		return ;
	p->reg[p_3] = p_1 & p_2;
	p->carry = p->carry ? 0 : 1;
	p->opc = id(p->opc + i);
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
	p->opc = id(p->opc + id_o);
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
	p->opc = id(p->opc + id_o);
}

void				_ex_zjmp(t_core *c, t_process *p)
{
	if (p->carry == 1)
	{
//		ft_printf("opc = %p ind = %u\n", c->ram[*p->rg], *p->rg);//
		p->opc = id(p->pc + ((p->opc + c->v[3](c, p, 1)) % IDX_MOD) - 1);
	}
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
	p->opc = id(p->opc + id_o);

}
