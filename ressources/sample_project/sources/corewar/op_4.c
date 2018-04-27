/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <brigoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 11:54:57 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/25 22:10:13 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		op_sti(t_process *process, t_inst *inst)
{
	int		tmp;
	int		value;

	value = 0;
	if (inst->type[1] == REG_CODE)
		value += get_revertint(process->reg[inst->param[1] - 1]);
	else if (inst->type[1] == DIR_CODE)
		value += (short int)inst->param[1];
	else if (inst->type[1] == IND_CODE)
		value += (short int)get_intfrommem(process->pc +
				(inst->param[1] % IDX_MOD), 2);
	if (inst->type[2] == REG_CODE)
		value += get_revertint(process->reg[inst->param[2] - 1]);
	else if (inst->type[2] == DIR_CODE)
		value += (short int)inst->param[2];
	tmp = get_revertint(process->reg[inst->param[0] - 1]);
	set_memory(process->pc + (value % IDX_MOD), (char *)&tmp, 4);
	process->carry = process->reg[inst->param[1] - 1] == 0;
	tmp = -1;
	while (++tmp < 4)
		g_data->status[PC(process->pc + ((short int)value % IDX_MOD) + tmp)] =
			STAT_DELAY | STAT_COPY | ((process->player + 1) << 4);
}

void		op_st(t_process *process, t_inst *inst)
{
	int		tmp;

	tmp = 0;
	if (inst->type[1] == IND_CODE)
	{
		tmp = get_revertint(process->reg[inst->param[0] - 1]);
		set_memory(process->pc + (inst->param[1] % IDX_MOD), (char *)&tmp, 4);
		tmp = -1;
		while (++tmp < 4)
			g_data->status[PC(process->pc +
					((short int)inst->param[1] % IDX_MOD)
				+ tmp)] = STAT_DELAY | STAT_COPY | ((process->player + 1) << 4);
	}
	if (inst->type[1] == REG_CODE)
		process->reg[inst->param[1] - 1] = process->reg[inst->param[0] - 1];
}
