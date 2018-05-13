/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/13 17:45:49 by dlavaury         ###   ########.fr       */
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
	if (*p->ins.param & T_REG && (!p_1 || p_1 > 16))
		return ;
	*p->ins.param & T_REG ? p_1 = p->rg[p_1] : 0;
	*p->ins.param & T_DIR ? i += 3 : 0;
	*p->ins.param & T_IND ? ++i : 0;
	p_2 = c->v[p->ins.param[1]](c, p, i++);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ;
	p->ins.param[1] & T_REG ? p_2 = p->rg[p_2] : 0;
	p->ins.param[1] & T_DIR ? i += 3 : 0;
	p->ins.param[1] & T_IND ? ++i : 0;
	if (!(p_3 = c->v[1](c, p, i)) || p_3 > 16)
		return ;
	p->rg[p_3] = p_1 & p_2;
	p->carry = p->carry ? 0 : 1;
	*p->rg = id(*p->rg + i);
}

void				_ex_or(t_core *c, t_process *p)
{
	unsigned int	id_o;
	unsigned int	p_1;
	unsigned int	p_2;
	unsigned int	p_3;

	id_o = 2;
	p_1 = c->v[*p->ins.param](c, p, id_o++);
	if (*p->ins.param & T_REG && (!p_1 || p_1 > 16))
		return ;
	*p->ins.param & T_REG ? p_1 = p->rg[p_1] : 0;
	*p->ins.param & T_DIR ? id_o += 3 : 0;
	*p->ins.param & T_IND ? ++id_o : 0;
	p_2 = c->v[p->ins.param[1]](c, p, id_o++);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ;
	p->ins.param[1] & T_REG ? p_2 = p->rg[p_2] : 0;
	p->ins.param[1] & T_DIR ? id_o += 3 : 0;
	p->ins.param[1] & T_IND ? ++id_o : 0;
	if (!(p_3 = c->v[1](c, p, id_o)) || p_3 > 16)
		return ;
	p->rg[p_3] = p_1 | p_2;
	p->carry = p->carry ? 0 : 1;
	*p->rg = id(*p->rg + id_o);
}

void		_ex_xor(t_core *c, t_process *p)
{
	unsigned int	id_o;
	unsigned int	p_1;
	unsigned int	p_2;
	unsigned int	p_3;

	id_o = 2;
	p_1 = c->v[*p->ins.param](c, p, id_o++);
	if (*p->ins.param & T_REG && (!p_1 || p_1 > 16))
		return ;
	*p->ins.param & T_REG ? p_1 = p->rg[p_1] : 0;
	*p->ins.param & T_DIR ? id_o += 3 : 0;
	*p->ins.param & T_IND ? ++id_o : 0;
	p_2 = c->v[p->ins.param[1]](c, p, id_o++);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ;
	p->ins.param[1] & T_REG ? p_2 = p->rg[p_2] : 0;
	p->ins.param[1] & T_DIR ? id_o += 3 : 0;
	p->ins.param[1] & T_IND ? ++id_o : 0;
	if (!(p_3 = c->v[1](c, p, id_o)) || p_3 > 16)
		return ;
	p->rg[p_3] = p_1 ^ p_2;
	p->carry = p->carry ? 0 : 1;
	*p->rg = id(*p->rg + id_o);
}

void				_ex_zjmp(t_core *c, t_process *p)
{
	if (p->carry == 1)
		*p->rg = id(p->pc + ((*p->rg + c->v[3](c, p, 1)) % IDX_MOD) - 1);
}

void		_ex_ldi(t_core *c, t_process *p)
{
	unsigned int	id_o;
	unsigned int	p_1;
	unsigned int	p_2;
	unsigned int	p_3;

	id_o = 2;
	p_1 = c->v[*p->ins.param](c, p, id_o++);
	if (*p->ins.param & T_REG && (!p_1 || p_1 > 16))
		return ;
	*p->ins.param & T_REG ? p_1 = p->rg[p_1] : ++id_o;
	p_2 = c->v[p->ins.param[1]](c, p, id_o++);
	if (p->ins.param[1] & T_REG && (!p_2 || p_2 > 16))
		return ;
	p->ins.param[1] & T_REG ? p_2 = p->rg[p_2] : ++id_o;
	if (!(p_3 = c->v[1](c, p, id_o)) || p_3 > 16)
		return ;
	p->rg[p_3] = c->v[2](c, p, p_2 + p_1);
	*p->rg = id(*p->rg + id_o);
}
