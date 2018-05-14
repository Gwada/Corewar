/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 21:39:21 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/05/14 01:34:07 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h>

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
		//	printf("label: %s\t param: %s\n", label->name, param + 1);
			if (ft_strequ(param + 1, label->name))
				return (cmd->index);
			label = label->next;
		}
		cmd = cmd->next;
	}
	data->eof ? handle_err(15, data->line) : 0;
	return (0);
}

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
			handle_err(14, data->line);
		ft_strptr_replace(&tab[i], ft_strrm_borders(tab[i]));
//		printf("tab[i] : %s\t is_dir: %d\t param_value: %d\t size: %d\n", tab[i], is_dir(tab[i]), cmd->p_val[i], cmd->size);
//		printf("tab[i] : %s\t is_reg: %d\t param_value: %d\t size: %d\n", tab[i], is_reg(tab[i]), cmd->p_val[i], cmd->size);
//		printf("tab[i] : %s\t is_ind: %d\t param_value: %d\t size: %d\n", tab[i], is_ind(tab[i]), cmd->p_val[i], cmd->size);
//		printf("tab[i] : %s\t is_lab: %d\t param_value: %d\t size: %d\n", tab[i], is_lab(tab[i]), cmd->p_val[i], cmd->size);
		cmd->p_name[i] = ft_strdup(tab[i]);
		cmd->p_val[i] = get_param_value(tab[i], data);
		if ((is_lab(tab[i]) || (is_dir(tab[i]) && is_lab(tab[i] + 1))) &&
				cmd->p_val[i])
			cmd->p_val[i] -= cmd->index;
		cmd->ocp += get_code(tab[i]) * LEFT_BM(i);
		cmd->size += get_size(tab[i], cmd->opcode);
	}
//	printf("cmd->size: %d\n", cmd->size);
	data->header->prog_size += cmd->size;
}

void		get_label(char **line, t_cmd *cmd)
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
		label->next = init_label();
		label = label->next;
	}
	label->name = ft_strcdup(*line, LABEL_CHAR);
	ft_strptr_replace(line, ft_strdup(ft_strchr(*line, LABEL_CHAR) + 1));
	!(*line) ? handle_err(42, -1): 0;
}

void		get_cmd(char *line, t_cmd *cmd, t_data *data)
{
	int		i;
	//	int		j;
	char	**tab;

	//	j = 0;
	if (!*line)
		return ;
	while (*line && ft_isblank(*line))
		line++;
	i = 16;
	while (i-- > 0)
		if (!ft_strncmp(line, g_op_tab[i].name, ft_strlen(g_op_tab[i].name)))
		{
			cmd->opcode = g_op_tab[i].op_code;
//			printf("instruction name: %s\t, op_code: %d\n", g_op_tab[i].name, cmd->opcode);
			break;
		}
	!ft_isblank(line[ft_strlen(g_op_tab[i].name)]) || !cmd->opcode ?
		handle_err(12, data->line) : 0;
	while (*line && !ft_isblank(*line))
		line++;
	while (*line && ft_isblank(*line))
		line++;
	tab = ft_strsplit(line, SEPARATOR_CHAR);
	//	while (tab[j])
	//		ft_putendl(tab[j++]);
	ft_tablen(tab) != g_op_tab[i].nb_param ? handle_err(13, data->line) : 0;
	get_params(tab, cmd, data);
	tab ? ft_free_tab(tab) : 0;
}

void		get_name(char *line, t_data *data, int fd)
{
	char	*tmp;

	tmp = ft_strdup(line);
	ft_count_char(tmp, '"') < 1 ? handle_err(8, data->line) : 0;
	ft_count_char(tmp, '"') < 2 ? ft_strdel(&data->gnl) : 0;
	while (ft_count_char(tmp, '"') < 2 && get_next_line(fd, &data->gnl) > 0)
	{
		data->line++;
		ft_char_replace(tmp, COMMENT_CHAR, '\0');
//		get_next_line(fd, &data->gnl);
		tmp = ft_strjoin_free_s1(tmp, "\n");
		tmp = ft_strjoin_free_s1(tmp, data->gnl);
		data->gnl ? ft_strdel(&data->gnl) : 0;
	}
	ft_strptr_replace(&tmp, ft_strrm_borders(tmp));
	ft_count_char(tmp, '"') != 2 || *tmp != '"' || tmp[ft_strlen(tmp) -1] != '"' ?
		handle_err(8, data->line): 0;
	if (ft_strlen(tmp) - 2 > PROG_NAME_LENGTH - 1)
		handle_err(9, data->line);
	ft_strncpy(data->header->prog_name, tmp + 1, ft_strlen(tmp) - 2);
//	data->byte |= 0x01;
	data->name++;
	tmp ? ft_strdel(&tmp) : 0;
//	ft_putendl(data->header->prog_name);
//	printf(".name: %s\n", data->header->prog_name);
//	ft_putendl("get_name");
}

void		get_comment(char *line, t_data *data, int fd)
{
	char	*tmp;

	tmp = ft_strdup(line);
	ft_count_char(tmp, '"') < 2 ? ft_strdel(&data->gnl) : 0;
	ft_count_char(tmp, '"') < 1 ? handle_err(10, data->line) : 0;
	while (ft_count_char(tmp, '"') < 2 && get_next_line(fd, &data->gnl) > 0)
	{
		data->line++;
		ft_char_replace(tmp, COMMENT_CHAR, '\0');
		tmp = ft_strjoin_free_s1(tmp, "\n");
		tmp = ft_strjoin_free_s1(tmp, data->gnl);
		data->gnl ? ft_strdel(&data->gnl) : 0;
	}
	ft_strptr_replace(&tmp, ft_strrm_borders(tmp));
	ft_count_char(tmp, '"') != 2 || *tmp != '"' || tmp[ft_strlen(tmp) -1] != '"' ?
		handle_err(10, data->line): 0;
	if (ft_strlen(tmp) - 2 > PROG_NAME_LENGTH - 1)
		handle_err(11, data->line);
	ft_strncpy(data->header->comment, tmp + 1, ft_strlen(tmp) - 2);
//	data->byte |= 0x02;
	data->comment++;
	tmp ? ft_strdel(&tmp) : 0;
//	printf(".comment: %s\n", data->header->comment);
}

/*void		get_header(char *line, t_data *data)
{
	char	*t;

	t = ft_strrm_borders(line);
	if (var)
	{
		if (ft_count_char(t, '"') != 2 || *t != '"' || t[ft_strlen(t) - 1] != '"')
			handle_err(8, data->line);
		if (ft_strlen(t) - 2 > PROG_NAME_LENGTH - 1)
			handle_err(9, data->line);
		ft_strncpy(data->header->prog_name, t + 1, ft_strlen(t) - 2);
	}
	else
	{
		if (ft_count_char(t, '"') != 2 || *t != '"' || t[ft_strlen(t) - 1] != '"')
			handle_err(10, data->line);
		if (ft_strlen(t) - 2 > COMMENT_LENGTH - 1)
			handle_err(11, data->line);
		ft_strncpy(data->header->comment, t + 1, ft_strlen(t) - 2);
	}
	var ? data->name++ : data->comment++;
	ft_strlen(t) ? ft_strdel(&t) : 0;
}*/
