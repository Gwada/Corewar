/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 00:55:03 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/05/14 14:20:11 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/asm.h"

void		free_label(t_label *label)
{
	if (!label)
		return ;
	free(label->name);
	free_label(label->next);
	free(label);
}

void		free_cmd(t_cmd *cmd)
{
	int		i;

	i = -1;
	if (!cmd)
		return ;
	while (++i < 3)
		cmd->p_name[i] ? free(cmd->p_name[i]) : 0;
	free_label(cmd->label);
	free_cmd(cmd->next);
	free(cmd);
}

void		free_data(t_data *data)
{
	data->s ? free(data->s) : 0;
	data->cor ? free(data->cor) : 0;
	data->gnl ? free(data->gnl) : 0;
	free_cmd(data->cmd);
	free(data->header);
}
