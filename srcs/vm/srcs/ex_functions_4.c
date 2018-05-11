/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/11 21:12:42 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void				_ex_aff(t_core *core, t_process *process)
{
	(void)core;
	(void)process;
}

unsigned int		get_reg_ind(t_core *c, t_process *p, unsigned int ind)
{
	return (c->ram[id(*p->reg + ind)]);
}

unsigned int		get_dir_value(t_core *c, t_process *p, unsigned int ind)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	while (i < (p->ins.label_size ? 2 : 4))
		n = (n << 8) | c->ram[id(*p->reg + ind + i++)];
	return (n);
}

unsigned int		get_ind_value(t_core *c, t_process *p, unsigned int ind)
{
	unsigned int	i;
	unsigned int	n;
	unsigned short	addr;

	i = 0;
	n = 0;
	addr = 0;
	while (i < 2)
		addr = ((addr << 8) | c->ram[id(*p->reg + ind + i++)]);
	i = 0;
	ft_printf("addr = %x\naddr %% IDX_MOD = %u\n", addr, addr % IDX_MOD);
	if (c->ram[*p->reg] > 0x0c && c->ram[*p->reg] < 0x10)
		while (i < 4)
			n = ((n << 8) | c->ram[id(*p->reg + addr + i++)]);
	else
		while (i < 4)
			n = ((n << 8) | c->ram[id(*p->reg + (addr % IDX_MOD) + i++)]);
	return (n);
}

unsigned int		get_mem_addr(t_core *c, t_process *p, unsigned int addr)
{
	if (c->ram[*p->reg] > 0x0c && c->ram[*p->reg] < 0x10)
		return (id(*p->reg + addr));
	return (id(*p->reg + (addr % IDX_MOD)));
}
