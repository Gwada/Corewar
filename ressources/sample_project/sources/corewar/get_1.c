/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <brigoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 16:07:22 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/25 18:38:29 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_dirsize(int opcode)
{
	if (opcode == OPCODE_LIVE || opcode == OPCODE_LD || opcode == OPCODE_AND ||
			opcode == OPCODE_OR || opcode == OPCODE_XOR || opcode == OPCODE_LLD)
		return (4);
	else
		return (2);
}

void	get_inst(int pc, t_inst *inst)
{
	int		ocp;
	int		i;

	if (!g_op_tab[inst->opcode - 1].ocp)
	{
		inst->type[0] = DIR_CODE;
		inst->param[0] = get_intfrommem(pc, get_dirsize(inst->opcode));
		return ;
	}
	ocp = get_intfrommem(pc, 1);
	pc++;
	i = 4;
	while (--i > 0)
	{
		inst->type[3 - i] = (ocp & (3 << (i * 2))) >> (i * 2);
		if (inst->type[3 - i] == REG_CODE && (pc += 1))
			inst->param[3 - i] = get_intfrommem(pc - 1, 1);
		else if (inst->type[3 - i] == DIR_CODE)
		{
			inst->param[3 - i] = get_intfrommem(pc, get_dirsize(inst->opcode));
			pc += get_dirsize(inst->opcode);
		}
		else if (inst->type[3 - i] == IND_CODE && (pc += 2))
			inst->param[3 - i] = (short int)get_intfrommem(pc - 2, 2);
	}
}

int		get_instlen(int pc)
{
	int		opcode;
	int		paramcode;
	int		len;
	int		i;

	opcode = get_intfrommem(pc, 1);
	len = 1;
	if (!ft_inrange(opcode, 1, 17))
		return (len);
	if (!g_op_tab[opcode - 1].ocp)
		return (len + get_dirsize(opcode));
	i = -1;
	while (++i < 3)
	{
		paramcode = get_intfrommem(pc + 1, 1) & (3 << ((1 + i) * 2));
		if (paramcode >> ((1 + i) * 2) == REG_CODE)
			len += 1;
		else if (paramcode >> ((1 + i) * 2) == DIR_CODE)
			len += get_dirsize(opcode);
		else if (paramcode >> ((1 + i) * 2) == IND_CODE)
			len += 2;
	}
	return (len + 1);
}
