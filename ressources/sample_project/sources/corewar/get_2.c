/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <brigoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 14:19:58 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/25 17:51:34 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_intfrommem(int pc, int len)
{
	char	tab[4];
	int		i;

	ft_bzero(tab, sizeof(char) * 4);
	i = 0;
	while (len--)
	{
		tab[i] = g_data->memory[PC(pc + len)];
		i++;
	}
	return (*(int *)tab);
}

int		get_nbplayers(void)
{
	int		nb;

	nb = 0;
	while (g_data->player[nb].file_name)
		nb++;
	return (nb);
}

int		get_periodlive(void)
{
	int			count;
	int			i;
	t_process	*process;

	i = -1;
	while (++i < MAX_PLAYERS && g_data->player[i].file_name)
		g_data->player[i].period_live = 0;
	count = 0;
	process = g_data->process;
	while (process)
	{
		count += process->period_live;
		process = process->next;
	}
	return (count);
}

int		get_revertint(int i)
{
	char tab[4];

	tab[0] = (char)((i & 0xff000000) / 0x01000000);
	tab[1] = (char)((i & 0x00ff0000) / 0x00010000);
	tab[2] = (char)((i & 0x0000ff00) / 0x00000100);
	tab[3] = (char)((i & 0x000000ff) / 0x00000001);
	return (*(int *)tab);
}
