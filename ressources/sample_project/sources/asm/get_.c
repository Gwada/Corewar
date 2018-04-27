/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 06:42:55 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/24 18:49:10 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_bigendian(int i)
{
	char tab[4];

	tab[0] = (char)((i & 0xff000000) / 0x01000000);
	tab[1] = (char)((i & 0x00ff0000) / 0x00010000);
	tab[2] = (char)((i & 0x0000ff00) / 0x00000100);
	tab[3] = (char)((i & 0x000000ff) / 0x00000001);
	return (*(int *)tab);
}

int		get_code(char *param)
{
	if (is_dir(param))
		return (DIR_CODE);
	if (is_reg(param))
		return (REG_CODE);
	if (is_ind(param) || is_lab(param))
		return (IND_CODE);
	return (0);
}

int		get_optab_index(int opcode)
{
	int		i;

	i = 0;
	while (i < 16 && g_op_tab[i].opcode != opcode)
		i++;
	return (i);
}

int		get_size(char *param, int opcode)
{
	if (is_ind(param) || is_lab(param))
		return (2);
	if (is_reg(param))
		return (1);
	if (is_dir(param))
	{
		if (opcode == 1 || opcode == 2 || opcode == 6 || opcode == 7
				|| opcode == 8 || opcode == 13)
			return (4);
		else
			return (2);
	}
	return (0);
}

int		get_value(char *param, t_data *data)
{
	t_cmd		*cmd;
	t_label		*label;

	if (is_ind(param))
		return (atoi(param));
	else if (is_reg(param))
		return (atoi(param + 1));
	if (*param == '%' && is_ind(param + 1))
		return (atoi(param + 1));
	param += *param == '%';
	cmd = data->cmd;
	while (cmd)
	{
		label = cmd->label;
		while (label && label->name)
		{
			if (ft_strequ(param + 1, label->name))
				return (cmd->index);
			label = label->next;
		}
		cmd = cmd->next;
	}
	if (data->end)
		print_error(14, data->line);
	return (0);
}
