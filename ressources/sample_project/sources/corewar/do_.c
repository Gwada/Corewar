/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <brigoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 16:46:51 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/25 20:16:17 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		do_cycle(void)
{
	t_process	*process;

	process = g_data->process;
	while (process)
	{
		if (process->timer)
			process->timer--;
		else
			do_process(process);
		process = process->next;
	}
}

void		do_op(t_process *process, t_inst *inst)
{
	if (!check_inst(inst))
		return ;
	inst->opcode == OPCODE_LIVE ? op_live(process, inst) : NULL;
	inst->opcode == OPCODE_LD ? op_ld(process, inst) : NULL;
	inst->opcode == OPCODE_ST ? op_st(process, inst) : NULL;
	inst->opcode == OPCODE_ADD ? op_add(process, inst) : NULL;
	inst->opcode == OPCODE_SUB ? op_sub(process, inst) : NULL;
	inst->opcode == OPCODE_AND ? op_and(process, inst) : NULL;
	inst->opcode == OPCODE_OR ? op_or(process, inst) : NULL;
	inst->opcode == OPCODE_XOR ? op_xor(process, inst) : NULL;
	inst->opcode == OPCODE_ZJMP ? op_zjmp(process, inst) : NULL;
	inst->opcode == OPCODE_LDI ? op_ldi(process, inst) : NULL;
	inst->opcode == OPCODE_STI ? op_sti(process, inst) : NULL;
	inst->opcode == OPCODE_FORK ? op_fork(process, inst) : NULL;
	inst->opcode == OPCODE_LLD ? op_lld(process, inst) : NULL;
	inst->opcode == OPCODE_LLDI ? op_lldi(process, inst) : NULL;
	inst->opcode == OPCODE_LFORK ? op_lfork(process, inst) : NULL;
	inst->opcode == OPCODE_AFF ? op_aff(process, inst) : NULL;
}

void		do_process(t_process *process)
{
	t_inst		inst;

	ft_bzero(&inst, sizeof(t_inst));
	inst.opcode = get_intfrommem(process->pc, 1);
	if (ft_inrange(inst.opcode, 1, 17))
	{
		get_inst(process->pc + 1, &inst);
		if (!(g_op_tab[inst.opcode - 1].ocp &&
					get_intfrommem(process->pc + 1, 1) & 3))
			do_op(process, &inst);
	}
	if (!(inst.opcode == OPCODE_ZJMP && process->carry))
	{
		g_data->status[process->pc] &= ~STAT_PC;
		process->pc = PC(process->pc + get_instlen(process->pc));
		g_data->status[process->pc] |= STAT_PC;
	}
	if (ft_inrange(inst.opcode, 1, 17))
		process->timer = g_op_tab[get_intfrommem(process->pc, 1) - 1].timer - 1;
}
