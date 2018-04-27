/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <brigoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 16:54:31 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/25 22:32:12 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_memory(int pc, char *src, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		g_data->memory[PC(pc + i)] = src[i];
}

void	set_status(int pc, char *src, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		g_data->status[PC(pc + i)] = src[i];
}

void	wait_for_key(void)
{
	int		ch;

	ch = 0;
	while (!ch)
		ch = getch();
}
