/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:44:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/13 15:57:00 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void				add_data(t_op *dst, t_op *src)
{
	dst->name = src->name;
	dst->nb_param = src->nb_param;
	dst->description = src->description;
	dst->nb_cycles = src->nb_cycles;
	dst->op_code = src->op_code;
	dst->ocp = src->ocp;
	dst->label_size = src->label_size;
	!src->ocp ? *dst->param = *src->param : 0;
}

unsigned int		read_instruct(t_core *c, t_process *p)
{
	unsigned char	opc;

	if (opc_c((opc = c->ram[id(p->pc)]) - 1))
	{
		add_data(&p->ins, &g_op_tab[opc - 1]);
		return (1);
	}
	p->ins.name = NULL;
	p->ins.nb_cycles = 0;
	return (0);
}

int					moov_opc(t_core *c, t_process *p, int new_pc)
{
	new_pc = id(p->pc + new_pc);
	c->r_2[p->pc] &= ~OPC;
	c->r_2[new_pc] |= OPC;
	return (new_pc);
}

int					get_ind(t_core *core, t_process *process, int ind)
{
	int				i;
	short			n;

	i = 0;
	n = 0;
	while (i < 2)
		n = (n << 8) | (core->ram[id(process->pc + ind + i++)]);
	(void)process;
	return (n);
}

int					get_len(t_core *core, t_process *p, int ind)
{
	*p->l = p->ins.ocp ? 1 : 0;
	p->l[1] = *p->l + 1;
	if (*p->ins.param & T_REG || (*p->ins.param & T_DIR && !p->ins.label_size))
		*p->l += *p->ins.param & T_REG ? 1 : 4;
	else
		*p->l += 2;
	if (p->ins.nb_param > 1 && (p->l[2] = *p->l + 1))
	{
		if (p->ins.param[1] & T_REG
		|| (p->ins.param[1] & T_DIR && !p->ins.label_size))
			*p->l += p->ins.param[1] & T_REG ? 1 : 4;
		else
			*p->l += 2;
		if (p->ins.nb_param > 2 && (p->l[3] = *p->l + 1))
		{
			if (p->ins.param[2] & T_REG
			|| (p->ins.param[2] & T_DIR && !p->ins.label_size))
				*p->l += p->ins.param[2] & T_REG ? 1 : 4;
			else
				*p->l += 2;
		}
	}
	++*p->l;
	(void)core;
	return (ind);
}
