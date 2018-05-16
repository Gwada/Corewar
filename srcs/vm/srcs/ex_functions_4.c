/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/16 20:44:55 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void			_ex_aff(t_core *core, t_process *process)
{
	unsigned	p_1;

	core->v[5](core, process, 0);
	if ((p_1 = core->v[1](core, process, process->l[1])) < 16)
	{
		ft_printf("\t\tp_1 = %#x | %u\n", p_1, p_1);
		ft_printf("\t\tprocess->reg[p_1]: %#x\n", process->reg[p_1]);
		ft_printf("%c\n", (process->reg[p_1] % 256));
	}
	process->pc = id(process->pc + *process->l);
}

unsigned int		get_reg_ind(t_core *c, t_process *p, unsigned int ind)
{
	ft_printf("\t\t{red}registre{eoc}\n");//
	return (c->ram[id(p->pc + ind)]);
}

unsigned int		get_dir_value(t_core *c, t_process *p, unsigned int ind)
{

	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	if (p->ins.label_size)
		return (c->v[3](c, p, ind));
	ft_printf("\t\t{red}direct (4 octets){eoc}\n");//
	while (i < 4)
		n = (n << 8) | c->ram[id(p->pc + ind + i++)];
	return (n);
}

unsigned int		get_ind_value(t_core *c, t_process *p, unsigned int ind)
{
	ft_printf("\t\t{red}index{eoc}\n");//
	unsigned int	i;
	unsigned int	n;
	unsigned int	try;
	unsigned short	addr;

	i = 0;
	addr = c->v[3](c, p, id(p->pc + ind));
	try = 0;
	p->ins.label_size ? try = 1 : 0;
	p->ins.label_size ? p->ins.label_size = 0 : 0;
	if (c->ram[id(p->pc)] > 0x0c && c->ram[id(p->pc)] < 0x10)
		n = c->v[2](c, p, addr);
	else
		n = c->v[2](c, p, addr % IDX_MOD);
	try ? p->ins.label_size = 1 : 0;
	return (n);
}

unsigned int		get_mem_addr(t_core *c, t_process *p, unsigned int addr)
{
	if (c->ram[id(p->pc)] > 0x0c && c->ram[id(p->pc)] < 0x10)
		return (id(p->pc + addr));
	return (id(p->pc + (addr % IDX_MOD)));
}
