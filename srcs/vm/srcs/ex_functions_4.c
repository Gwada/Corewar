/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/14 21:41:00 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void			_ex_aff(t_core *core, t_process *process)
{
	unsigned	p_1;

	if (!(p_1 = core->v[1](core, process, 2)) || p_1 > 16)
		return ;
	ft_printf("%c\n", (process->reg[p_1] % 256));
	process->pc = id(process->pc + 2);
}

unsigned int		get_reg_ind(t_core *c, t_process *p, unsigned int ind)
{
	ft_printf("{red}registre{eoc}\n");
	return (c->ram[id(p->pc + ind)]);
}

unsigned int		get_dir_value(t_core *c, t_process *p, unsigned int ind)
{
	ft_printf("{red}direct{eoc}\n");
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	if (p->ins.label_size)
		return (c->v[3](c, p, ind));
	while (i < 4)
		n = (n << 8) | c->ram[id(p->pc + (ind % IDX_MOD) + i++)];
	ft_printf("{red}n: %p | %u{eoc}\n", n, n);
	return (n);
}

unsigned int		get_ind_value(t_core *c, t_process *p, unsigned int ind)
{
	ft_printf("{red}index{eoc}\n");
	unsigned int	i;
	unsigned int	n;
	unsigned int	pl;
	unsigned short	addr;

	i = 0;
	pl = 0;
	addr = c->v[3](c, p, ind);
	if (c->ram[id(p->pc)] > 0x0c && c->ram[id(p->pc)] < 0x10)
		n = c->v[2](c, p, addr);
	else
		n = c->v[2](c, p, p->pc + (addr % IDX_MOD));
	return (n);
}

unsigned int		get_mem_addr(t_core *c, t_process *p, unsigned int addr)
{
	unsigned int	i;

	i = 0;
	if (c->ram[id(p->pc)] > 0x0c && c->ram[id(p->pc)] < 0x10)
		return (id(p->pc + addr));
	return (id(p->pc + (p->pc + addr % IDX_MOD)));
}
