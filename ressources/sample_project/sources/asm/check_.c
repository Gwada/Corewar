/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 21:17:22 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/24 19:02:29 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		check_labels(t_data *data)
{
	t_cmd		*cmd;
	int			i;

	cmd = data->cmd;
	while (cmd)
	{
		i = 0;
		while (i < 3 && cmd->p_name[i])
		{
			if (!cmd->p_val[i])
			{
				cmd->p_val[i] = get_value(cmd->p_name[i], data);
				if (is_lab(cmd->p_name[i]) ||
						(is_dir(cmd->p_name[i]) && is_lab(cmd->p_name[i] + 1)))
					cmd->p_val[i] -= cmd->index;
			}
			i++;
		}
		cmd = cmd->next;
	}
}
