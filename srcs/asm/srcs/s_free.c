/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:23:09 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/05/17 14:33:34 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (data == NULL)
		return ;
	data->s ? free(data->s) : 0;
	data->cor ? free(data->cor) : 0;
	data->gnl ? free(data->gnl) : 0;
	free_cmd(data->cmd);
	free(data->header);
}
