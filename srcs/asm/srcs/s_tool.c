/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_tool.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:42:51 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/05/16 16:28:19 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		get_optab_index(int opcode)
{
	int		i;

	i = 0;
	while (i < 16 && g_op_tab[i].op_code != opcode)
		i++;
	return (i);
}

int		get_size(char *param, int op)
{
	if (is_ind(param) || is_lab(param))
		return (2);
	if (is_reg(param))
		return (1);
	if (is_dir(param))
	{
		if (op == 1 || op == 2 || op == 6 || op == 7 || op == 8 || op == 13)
			return (4);
		return (2);
	}
	return (0);
}

int			get_code(char *param)
{
	if (is_dir(param))
		return (DIR_CODE);
	if (is_reg(param))
		return (REG_CODE);
	if (is_ind(param) || is_lab(param))
		return (IND_CODE);
	return (0);
}

int			get_param_value(char *param, t_data *data)
{
	t_cmd	*cmd;
	t_label	*label;

	if (is_ind(param))
		return (ft_atoi(param));
	if (is_reg(param))
		return (ft_atoi(param + 1));
	if (*param == '%' && is_ind(param + 1))
		return (ft_atoi(param + 1));
	param += *param == '%';
	*param == '%' ? param++ : 0;
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
//	(data->byte & 4) ? handle_err(15, data->line) : 0;//
	data->eof ? handle_err(15, data->line) : 0;
	return (0);
}
