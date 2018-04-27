/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 02:10:29 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/24 19:00:58 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		store_comment(char *line, t_data *data)
{
	char	*tmp;

	tmp = ft_strstrip(line);
	if (ft_strcount(tmp, '"') != 2 ||
			*tmp != '"' || tmp[ft_strlen(tmp) - 1] != '"')
		print_error(7, data->line);
	if (ft_strlen(line) - 2 > COMMENT_LENGTH - 1)
		print_error(8, data->line);
	ft_strccpy(data->header->comment, tmp + 1, '"');
	free(tmp);
}

void		store_cmd(char *line, t_cmd *cmd, t_data *data)
{
	int		i;
	char	**tab;

	if (!*line)
		return ;
	while (ft_isspace(*line))
		line++;
	i = 16;
	while (i-- > 0)
		if (ft_strnequ(line, g_op_tab[i].op, ft_strlen(g_op_tab[i].op)))
		{
			cmd->opcode = g_op_tab[i].opcode;
			break ;
		}
	if (!cmd->opcode)
		print_error(9, data->line);
	while (*line && !ft_isspace(*line))
		line++;
	while (ft_isspace(*line))
		line++;
	tab = ft_strsplit(line, SEPARATOR_CHAR);
	if ((int)ft_tablen((void *)tab) != g_op_tab[i].nb_param)
		print_error(11, data->line);
	store_params(tab, cmd, data);
}

void		store_label(char **line, t_cmd *cmd)
{
	int		i;
	t_label	*label;

	i = 0;
	while ((*line)[i] && ft_strcount(LABEL_CHARS, (*line)[i]))
		i++;
	if ((*line)[i] != LABEL_CHAR)
		return ;
	label = (t_label *)ft_lstlast(cmd->label);
	if (label->name)
	{
		label->next = new_label();
		label = label->next;
	}
	label->name = ft_strcdup(*line, LABEL_CHAR);
	ft_strfreedef(line, ft_strdup(ft_strchr(*line, LABEL_CHAR) + 1));
	if (!*line)
		print_error(1, 0);
}

void		store_name(char *line, t_data *data)
{
	char	*tmp;

	tmp = ft_strstrip(line);
	if (ft_strcount(tmp, '"') != 2 ||
			*tmp != '"' || tmp[ft_strlen(tmp) - 1] != '"')
		print_error(5, data->line);
	if (ft_strlen(line) - 2 > PROG_NAME_LENGTH - 1)
		print_error(6, data->line);
	ft_strccpy(data->header->prog_name, tmp + 1, '"');
	free(tmp);
}

void		store_params(char **tab, t_cmd *cmd, t_data *data)
{
	int		i;

	cmd->size = 1 + g_op_tab[cmd->opcode - 1].ocp;
	i = -1;
	while (++i < 3 && tab[i])
	{
		ft_strfreedef(&tab[i], ft_strstrip(tab[i]));
		if ((is_dir(tab[i]) | is_ind(tab[i]) | is_lab(tab[i]) | is_reg(tab[i]))
				& ~g_op_tab[cmd->opcode - 1].arg_type[i])
			print_error(10, data->line);
		cmd->p_name[i] = tab[i];
		cmd->p_val[i] = get_value(tab[i], data);
		if ((is_lab(tab[i]) || (is_dir(tab[i]) && is_lab(tab[i] + 1))) &&
				cmd->p_val[i])
			cmd->p_val[i] -= cmd->index;
		cmd->ocp += get_code(tab[i]) * (1 << (3 - i) * 2);
		cmd->size += get_size(tab[i], cmd->opcode);
	}
	data->header->prog_size += cmd->size;
}
