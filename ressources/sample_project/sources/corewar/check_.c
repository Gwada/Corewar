/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <brigoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 16:31:49 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/25 19:29:32 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			check_inst(t_inst *inst)
{
	int		i;

	i = -1;
	while (++i < 3)
	{
		if ((inst->type[i] == REG_CODE &&
					!(g_op_tab[inst->opcode - 1].arg_type[i] | T_REG)) ||
				(inst->type[i] == DIR_CODE &&
					!(g_op_tab[inst->opcode - 1].arg_type[i] | T_DIR)) ||
				(inst->type[i] == IND_CODE &&
					!(g_op_tab[inst->opcode - 1].arg_type[i] | T_IND)) ||
				(g_op_tab[inst->opcode - 1].arg_type[i] && !inst->type[i]) ||
				(!g_op_tab[inst->opcode - 1].arg_type[i] && inst->type[i]) ||
				(inst->type[i] != REG_CODE && inst->type[i] != DIR_CODE &&
					inst->type[i] != IND_CODE &&
					g_op_tab[inst->opcode - 1].arg_type[i]) ||
				(inst->type[i] == REG_CODE &&
					!ft_inrange(inst->param[i], 1, REG_NUMBER + 1)))
			return (0);
	}
	return (1);
}

void		check_numbers(int *n1)
{
	int		n2[MAX_PLAYERS];
	int		i1;
	int		i2;
	int		n;

	i2 = -1;
	while (++i2 < MAX_PLAYERS)
		n2[i2] = g_data->player[i2].number;
	n = 0;
	while (++n <= MAX_PLAYERS)
	{
		i2 = -1;
		while (++i2 < MAX_PLAYERS)
			if (n2[i2] == n)
			{
				i1 = -1;
				while (++i1 < MAX_PLAYERS)
					if (n1[i1] >= n)
						n1[i1]++;
			}
	}
	n = -1;
	while (++n < MAX_PLAYERS)
		if (n1[n])
			g_data->player[n].number = n1[n];
}

void		check_playerorder(void)
{
	int			i;
	t_player	tmp;

	i = 0;
	while (++i < MAX_PLAYERS && g_data->player[i].file_name)
		if (g_data->player[i].number < g_data->player[i - 1].number)
		{
			ft_memcpy(&tmp, &g_data->player[i], sizeof(t_player));
			ft_memcpy(&g_data->player[i], &g_data->player[i - 1],
					sizeof(t_player));
			ft_memcpy(&g_data->player[i - 1], &tmp, sizeof(t_player));
			i = 0;
		}
}

void		check_process(t_process **process)
{
	while (process && *process)
	{
		if ((*process)->period_live)
		{
			(*process)->period_live = 0;
			process = &(*process)->next;
		}
		else
			ft_strfreedef((char **)process, (char *)(*process)->next);
	}
}

void		check_status(void)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (g_data->status[i] & (STAT_LIVE | STAT_AFF | STAT_COPY))
		{
			if (g_data->status[i] & STAT_DELAY)
				g_data->status[i] &= ~STAT_DELAY;
			else
				g_data->status[i] &= ~(STAT_LIVE | STAT_AFF | STAT_COPY);
		}
		i++;
	}
}
