/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 00:55:03 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/05/14 13:31:33 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/asm.h"

void		free_label(t_label *label)
{
	t_label	*tmp;
	t_label	*now;

	tmp = label;
	now = label;
	while (now)
	{
		tmp = now->next;
		now->name ? ft_strdel(&now->name) : 0;
		free(now);
		now = tmp;
	}
}

void		free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	t_cmd	*now;
	int		i;

	tmp = cmd;
	now = cmd;
	i = -1;
	while (now)
	{
		tmp = now->next;
		now->index = 0;
		now->opcode = 0;
		while (++i < 3 && now->p_name[i])
			now->p_name[i] ? ft_strdel(&now->p_name[i]) : 0;
		i = -1;
		ft_bzero(now->p_val, sizeof(int) * 3);
		now->size = 0;
		free_label(now->label);
		free(now);
		now = tmp;
	}
}

void		free_data(t_data *data)
{
	ft_strlen(data->s) ? ft_strdel(&data->s) : 0;
	ft_strlen(data->cor) ? ft_strdel(&data->cor) : 0;
	data->gnl ? ft_strdel(&data->gnl) : 0;
	data->name = 0;
	data->comment = 0;
	data->line = 0;
	data->eof = 0;
	free_cmd(data->cmd);
	free(data);
}
