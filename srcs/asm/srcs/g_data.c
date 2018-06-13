/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:24:20 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/06/13 16:58:02 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		get_params(char **tab, t_cmd *cmd, t_data *data)
{
	int		i;

	i = -1;
	cmd->size += 1 + g_op_tab[cmd->opcode - 1].ocp;
	while (++i < 3 && tab[i])
	{
		ft_strptr_replace(&tab[i], ft_strrm_borders(tab[i]));
		if ((is_dir(tab[i]) | is_ind(tab[i]) | is_lab(tab[i]) | is_reg(tab[i]))
				& ~g_op_tab[cmd->opcode - 1].param[i])
			handle_err(14, data->line, data);
		ft_strptr_replace(&tab[i], ft_strrm_borders(tab[i]));
		cmd->p_name[i] = ft_strdup(tab[i]);
		cmd->p_val[i] = get_param_value(tab[i], data);
		if ((is_lab(tab[i]) || (is_dir(tab[i]) && is_lab(tab[i] + 1))) &&
				cmd->p_val[i])
			cmd->p_val[i] -= cmd->index;
		cmd->ocp += get_code(tab[i]) * ((1 << (3 - i) * 2));
		cmd->size += get_size(tab[i], cmd->opcode);
	}
	i = 0;
	data->header->prog_size += cmd->size;
}

void		get_label(char **line, t_cmd *cmd, t_data *data)
{
	int		i;
	t_label	*label;

	i = 0;
	while ((*line)[i] && ft_count_char(LABEL_CHARS, (*line)[i]))
		i++;
	if ((*line)[i] != LABEL_CHAR)
		return ;
	label = go_lastlabel(cmd->label);
	if (label->name)
	{
		label->next = init_label(data);
		label = label->next;
	}
	label->name = ft_strcdup(*line, LABEL_CHAR);
	ft_strptr_replace(line, ft_strdup(ft_strchr(*line, LABEL_CHAR) + 1));
	!(*line) ? handle_err(42, QUIT, data) : 0;
}

void		get_cmd(char *line, t_cmd *cmd, t_data *d)
{
	int		i;
	size_t	pl;

	pl = -1;
	if ((i = 16) && !*line)
		return ;
	while (*line && ft_isblank(*line))
		line++;
	while (i-- > 0)
		if (!ft_strncmp(line, g_op_tab[i].name, ft_strlen(g_op_tab[i].name)))
		{
			cmd->opcode = g_op_tab[i].op_code;
			break ;
		}
	i < 0 ? handle_err(12, d->line, d) : 0;
	!cmd->opcode || (!ft_isblank(line[ft_strlen(g_op_tab[i].name)]) &&
			line[ft_strlen(g_op_tab[i].name)] != DIRECT_CHAR) ?
		handle_err(12, d->line, d) : 0;
	while (++pl < ft_strlen(g_op_tab[i].name))
		line++;
	while (*line && ft_isblank(*line))
		line++;
	handle_tab(line, cmd, d, i);
}

void		get_name(char *line, t_data *data, int fd)
{
	char	*s;

	s = ft_strdup(line);
	ft_count_char(s, '"') < 1 ? handle_err(8, data->line, data) : 0;
	ft_count_char(s, '"') < 2 ? ft_strdel(&data->gnl) : 0;
	while (ft_count_char(s, '"') < 2 && get_next_line(fd, &data->gnl) > 0)
	{
		data->line++;
		s = ft_strjoin_free_s1(s, "\n");
		s = ft_strjoin_free_s1(s, data->gnl);
		data->gnl ? ft_strdel(&data->gnl) : 0;
	}
	ft_strptr_replace(&s, ft_strrm_borders(s));
	ft_count_char(s, '"') != 2 || *s != '"' || s[ft_strlen(s) - 1] != '"' ?
		handle_err(8, data->line, data) : 0;
	if (ft_strlen(s) - 2 > PROG_NAME_LENGTH)
		handle_err(9, data->line, data);
	ft_strncpy(data->header->prog_name, s + 1, ft_strlen(s) - 2);
	data->name++;
	s ? ft_strdel(&s) : 0;
}

void		get_comment(char *line, t_data *data, int fd)
{
	char	*s;

	s = ft_strdup(line);
	ft_count_char(s, '"') < 2 ? ft_strdel(&data->gnl) : 0;
	ft_count_char(s, '"') < 1 ? handle_err(10, data->line, data) : 0;
	while (ft_count_char(s, '"') < 2 && get_next_line(fd, &data->gnl) > 0)
	{
		data->line++;
		s = ft_strjoin_free_s1(s, "\n");
		s = ft_strjoin_free_s1(s, data->gnl);
		data->gnl ? ft_strdel(&data->gnl) : 0;
	}
	ft_strptr_replace(&s, ft_strrm_borders(s));
	ft_count_char(s, '"') != 2 || *s != '"' || s[ft_strlen(s) - 1] != '"' ?
		handle_err(10, data->line, data) : 0;
	if (ft_strlen(s) - 2 > COMMENT_LENGTH)
		handle_err(11, data->line, data);
	ft_strncpy(data->header->comment, s + 1, ft_strlen(s) - 2);
	data->comment++;
	s ? ft_strdel(&s) : 0;
}
