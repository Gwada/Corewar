/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_tool.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:42:51 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/06/13 17:19:08 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		handle_tab(char *l, t_cmd *cmd, t_data *d, int i)
{
	char	**tab;

	(tab = ft_strsplit(l, SEPARATOR_CHAR)) ? 0 : handle_err(13, QUIT, d);
	ft_tablen(tab) != g_op_tab[i].nb_param ? handle_err(13, d->line, d) : 0;
	get_params(tab, cmd, d);
	l[ft_strlen(l) - 1] == SEPARATOR_CHAR ? handle_err(13, d->line, d) : 0;
	ft_free_tab(tab);
}

int			get_optab_index(int opcode)
{
	int		i;

	i = 0;
	while (i < 16 && g_op_tab[i].op_code != opcode)
		i++;
	return (i);
}

int			get_size(char *param, int op)
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
	*param == '%' && !*(param + 1) ? handle_err(14, data->line, data) : 0;
	if (*param == '%' && is_ind(param + 1))
		return (ft_atoi(param + 1));
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
	data->eof ? handle_err(15, data->line, data) : 0;
	return (0);
}
