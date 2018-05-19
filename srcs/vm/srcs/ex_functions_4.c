/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/19 18:26:12 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void			_ex_aff(t_core *c, t_process *p)
{
	unsigned	p_1;

	c->v[5](c, p, 0);
	if (!(p_1 = c->v[1](c, p, p->l[1])) || p_1 > 16)
		return ((void)(p->pc = id(p->pc + *p->l)));
	ft_printf("%c\n", (p->reg[p_1] % 256));
	p->pc = id(p->pc + *p->l);
}

int				get_reg_ind(t_core *c, t_process *p, int ind)
{
	ft_printf("\t\t{red}registre{eoc}\n");//
	return (c->ram[id(p->pc + ind)]);
}

int				get_dir_value(t_core *c, t_process *p, int ind)
{
	ft_printf("\t\t{red}direct{eoc}\t");//
	int			i;
	int			n;

	i = -1;
	n = 0;
	while (++i < (p->ins.label_size ? 2 : 4))
		n = (n << 8) | c->ram[id(p->pc + ind + i)];
	ft_printf("value: %#x\n", n);
	return (n);
}

int				get_ind_value(t_core *c, t_process *p, int ind)
{
	ft_printf("\t\t{red}indirec{eoc}\t");//
	int			i;
	int			n;
	short		addr;

	i = 0;
	addr = (short)c->v[3](c, p, ind);
	c->ram[id(p->pc)] < 0x0d || c->ram[id(p->pc)] > 0x0f ? addr %= IDX_MOD : 0;

	ft_printf("addr: %#x | %hd\t", addr, addr);

	while (++i < 4)
		n = (n << 8) | c->ram[id(p->pc + addr + i)];

	ft_printf("value: %#x\n", n);

	return (n);
}

int				get_mem_addr(t_core *c, t_process *p, int addr)
{
	c->ram[id(p->pc)] < 0x0d || c->ram[id(p->pc)] > 0x0f ? addr %= IDX_MOD : 0;
	return (id(p->pc + addr));
}
