/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/12 12:12:18 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void				_ex_aff(t_core *c, t_process *p)
{
	unsigned char	p_1;

	c->v[5](c, p, 0);
	if (!(p_1 = c->v[1](c, p, p->l[1])) || p_1 > 16)
		return ((void)(p->pc = id(p->pc + *p->l)));
	if (!(c->bd & VISUAL) && !(c->bd & DEBUG))
		ft_printf("%c\n", p->reg[p_1] % 256);
	c->bd & VISUAL ? visu(c, 5, p, id(p->pc + *p->l), 0) : 0;
	p->pc = moov_opc(c, p, *p->l);
}

int					get_reg_ind(t_core *c, t_process *p, int ind)
{
	return (c->ram[id(p->pc + ind)]);
}

int					get_dir_value(t_core *c, t_process *p, int ind)
{
	int			i;
	int			n;

	i = -1;
	n = 0;
	while (++i < (p->ins.label_size ? 2 : 4))
		n = (n << 8) | c->ram[id(p->pc + ind + i)];
	return (n);
}

int					get_ind_value(t_core *c, t_process *p, int ind)
{
	int				i;
	int				n;
	short			addr;

	i = -1;
	n = 0;
	addr = c->v[3](c, p, ind);
	if (c->ram[id(p->pc)] < 0x0d || c->ram[id(p->pc)] > 0x0f)
		addr %= IDX_MOD;
	while (++i < 4)
		n = (n << 8) | c->ram[id(p->pc + addr + i)];
	return (n);
}

int					get_mem_addr(t_core *c, t_process *p, int addr)
{
	if (c->ram[id(p->pc)] < 0x0d || c->ram[id(p->pc)] > 0x0f)
		addr %= IDX_MOD;
	return (id(p->pc + addr));
}
