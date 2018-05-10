/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/10 20:36:23 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void				_ex_aff(t_core *core, t_process *process)
{
	(void)core;
	(void)process;
}

unsigned int		get_reg_value(t_core *c, t_process *p, unsigned int reg)
{
	unsigned int	value;

	(void)c;
	value = p->reg[reg];
	return (value);
}

unsigned int		get_dir_value(t_core *c, t_process *p, unsigned int ind)
{
	int				i;
	unsigned int	n;

	i = -1;
	n = 0;
	while (++i < (p->ins.label_size ? 2 : 4))
		n = (n << 8) | c->ram[id(ind + *p->reg + i)];
	return (n);
}

unsigned int		get_ind_value(t_core *c, t_process *p, unsigned int ind)
{
	ft_printf("ind\n");
	int				i;
	unsigned int	n;
	unsigned short	addr;

	i = -1;
	n = 0;
	addr = 0;
	while (++i < 2)
		addr = (addr << 8) | c->ram[id(ind + *p->reg + i)];
	i = -1;
	while (++i < 4)
		n = (n << 8) | c->ram[id(*p->reg + addr + i)];
	return (n);
}
