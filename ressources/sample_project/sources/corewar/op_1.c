/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <brigoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 11:27:54 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/25 22:18:05 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			op_or(t_process *process, t_inst *inst)
{
	int arg0;
	int arg1;

	arg0 = 0;
	arg1 = 0;
	if (inst->type[0] == REG_CODE)
		arg0 = get_revertint(process->reg[inst->param[0] - 1]);
	else if (inst->type[0] == DIR_CODE)
		arg0 = inst->param[0];
	else if (inst->type[0] == IND_CODE)
		arg0 = (short int)get_intfrommem(process->pc +
				((short int)inst->param[0] % IDX_MOD), IND_SIZE);
	if (inst->type[1] == REG_CODE)
		arg1 = get_revertint(process->reg[inst->param[1] - 1]);
	else if (inst->type[1] == DIR_CODE)
		arg1 = inst->param[1];
	else if (inst->type[1] == IND_CODE)
		arg1 = (short int)get_intfrommem(process->pc +
				((short int)inst->param[1] % IDX_MOD), IND_SIZE);
	process->reg[inst->param[1] - 1] = arg0 | arg1;
	process->carry = process->reg[inst->param[1] - 1] == 0;
}

void			op_xor(t_process *process, t_inst *inst)
{
	int arg0;
	int arg1;

	arg0 = 0;
	arg1 = 0;
	if (inst->type[0] == REG_CODE)
		arg0 = get_revertint(process->reg[inst->param[0] - 1]);
	else if (inst->type[0] == DIR_CODE)
		arg0 = inst->param[0];
	else if (inst->type[0] == IND_CODE)
		arg0 = (short int)get_intfrommem(process->pc +
				((short int)inst->param[0] % IDX_MOD), IND_SIZE);
	if (inst->type[1] == REG_CODE)
		arg1 = get_revertint(process->reg[inst->param[1] - 1]);
	else if (inst->type[1] == DIR_CODE)
		arg1 = inst->param[1];
	else if (inst->type[1] == IND_CODE)
		arg1 = (short int)get_intfrommem(process->pc +
				((short int)inst->param[1] % IDX_MOD), IND_SIZE);
	process->reg[inst->param[1] - 1] = arg0 ^ arg1;
	process->carry = process->reg[inst->param[1] - 1] == 0;
}

void			op_and(t_process *process, t_inst *inst)
{
	int arg0;
	int arg1;

	arg0 = 0;
	arg1 = 0;
	if (inst->type[0] == REG_CODE)
		arg0 = get_revertint(process->reg[inst->param[0] - 1]);
	else if (inst->type[0] == DIR_CODE)
		arg0 = inst->param[0];
	else if (inst->type[0] == IND_CODE)
		arg0 = (short int)get_intfrommem(process->pc +
				((short int)inst->param[0] % IDX_MOD), IND_SIZE);
	if (inst->type[1] == REG_CODE)
		arg1 = get_revertint(process->reg[inst->param[1] - 1]);
	else if (inst->type[1] == DIR_CODE)
		arg1 = inst->param[1];
	else if (inst->type[1] == IND_CODE)
		arg1 = (short int)get_intfrommem(process->pc +
				((short int)inst->param[1] % IDX_MOD), IND_SIZE);
	process->reg[inst->param[1] - 1] = arg0 & arg1;
	process->carry = process->reg[inst->param[1] - 1] == 0;
}

void			op_sub(t_process *process, t_inst *inst)
{
	process->reg[inst->param[2] - 1] = process->reg[inst->param[1] - 1] +
			process->reg[inst->param[0] - 1];
	process->carry = process->reg[inst->param[2] - 1] == 0;
}

void			op_add(t_process *process, t_inst *inst)
{
	process->reg[inst->param[2] - 1] = process->reg[inst->param[1] - 1] -
			process->reg[inst->param[0] - 1];
	process->carry = process->reg[inst->param[2] - 1] == 0;
}
