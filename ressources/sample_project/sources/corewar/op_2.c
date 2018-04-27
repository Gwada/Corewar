/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <brigoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 11:28:25 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/25 22:16:35 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		op_aff(t_process *process, t_inst *inst)
{
	if (!g_data->mute)
		ft_putchar(process->reg[inst->param[0] - 1] % 256);
	g_data->status[process->pc] |= STAT_DELAY | STAT_AFF;
}

void		op_live(t_process *process, t_inst *inst)
{
	t_player	*player;
	int			i;

	player = NULL;
	i = -1;
	while (++i >= 0 && i < MAX_PLAYERS && g_data->player[i].file_name)
		if (g_data->player[i].number == -inst->param[0])
			player = &(g_data->player[i]);
	process->last_live = g_data->cycle;
	process->period_live++;
	if (!player)
		return ;
	if (!g_data->mute)
		ft_printf("un processus dit que le joueur %i(%s) est en vie\n",
				-inst->param[0], player->header.prog_name);
	player->last_live = g_data->cycle;
	player->period_live++;
	g_data->last_live = player->number;
	g_data->status[process->pc] |= STAT_DELAY | STAT_LIVE;
}

void		op_zjmp(t_process *process, t_inst *inst)
{
	if (process->carry)
	{
		g_data->status[process->pc] &= ~STAT_PC;
		process->pc = PC(process->pc + (short int)inst->param[0]);
		g_data->status[process->pc] |= STAT_PC;
	}
}

void		op_fork(t_process *process, t_inst *inst)
{
	init_process(process, process->pc + ((short int)inst->param[0] % IDX_MOD));
	g_data->status[process->pc] |= STAT_PC;
}

void		op_lfork(t_process *process, t_inst *inst)
{
	init_process(process, process->pc + (short int)inst->param[0]);
	g_data->status[process->pc] |= STAT_PC;
}
