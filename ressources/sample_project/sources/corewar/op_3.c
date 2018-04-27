/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <brigoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 11:54:47 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/25 22:16:19 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			op_lldi(t_process *process, t_inst *inst)
{
	int		value;

	value = 0;
	if (inst->type[0] == REG_CODE)
		value += get_revertint(process->reg[inst->param[0] - 1]);
	else if (inst->type[0] == DIR_CODE)
		value += (short int)inst->param[0];
	else if (inst->type[0] == IND_CODE)
		value += (short int)get_intfrommem(process->pc +
				(inst->param[0] % IDX_MOD), IND_SIZE);
	if (inst->type[1] == REG_CODE)
		value += get_revertint(process->reg[inst->param[1] - 1]);
	else if (inst->type[1] == DIR_CODE)
		value += (short int)inst->param[1];
	process->reg[inst->param[2] - 1] = (short int)get_intfrommem(process->pc +
			value, IND_SIZE);
	process->carry = process->reg[inst->param[0] - 1] == 0;
}

void			op_lld(t_process *process, t_inst *inst)
{
	if (inst->type[0] == IND_CODE)
		process->reg[inst->param[1] - 1] = (short int)get_intfrommem(process->pc
				+ ((short int)inst->param[0] % IDX_MOD), IND_SIZE);
	if (inst->type[1] == DIR_CODE)
		process->reg[inst->param[1] - 1] = inst->param[0];
	process->carry = process->reg[inst->param[1] - 1] == 0;
}

void			op_ldi(t_process *process, t_inst *inst)
{
	int		value;

	value = 0;
	if (inst->type[0] == REG_CODE)
		value += get_revertint(process->reg[inst->param[0] - 1]);
	else if (inst->type[0] == DIR_CODE)
		value += (short int)inst->param[0];
	else if (inst->type[0] == IND_CODE)
		value += (short int)get_intfrommem(process->pc +
				(inst->param[0] % IDX_MOD), 2);
	if (inst->type[1] == REG_CODE)
		value += get_revertint(process->reg[inst->param[1] - 1]);
	else if (inst->type[1] == DIR_CODE)
		value += (short int)inst->param[1];
	process->reg[inst->param[2] - 1] = get_intfrommem(process->pc +
			(value % IDX_MOD), 4);
	process->carry = process->reg[inst->param[2] - 1] == 0;
}

void			op_ld(t_process *process, t_inst *inst)
{
	if (inst->type[0] == IND_CODE)
		process->reg[inst->param[1] - 1] = get_intfrommem(process->pc +
					((short int)inst->param[0] % IDX_MOD), IND_SIZE);
	if (inst->type[0] == DIR_CODE)
		process->reg[inst->param[1] - 1] = inst->param[0];
	process->carry = process->reg[inst->param[1] - 1] == 0;
}
