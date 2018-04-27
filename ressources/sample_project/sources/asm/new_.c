/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 21:32:20 by brigoux           #+#    #+#             */
/*   Updated: 2016/06/18 20:23:16 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_cmd		*new_cmd(void)
{
	t_cmd		*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		print_error(1, -1);
	cmd->next = NULL;
	cmd->label = new_label();
	cmd->index = 0;
	cmd->opcode = 0;
	ft_bzero(cmd->p_name, sizeof(char *) * 3);
	cmd->ocp = 0;
	ft_bzero(cmd->p_val, sizeof(int) * 3);
	return (cmd);
}

t_data		*new_data(void)
{
	t_data		*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		print_error(1, -1);
	data->header = new_header();
	data->flag = new_flag();
	data->src = NULL;
	data->dst = NULL;
	data->line = 0;
	data->cmd = new_cmd();
	data->end = 0;
	return (data);
}

t_flag		*new_flag(void)
{
	t_flag		*flag;

	flag = (t_flag *)malloc(sizeof(t_flag));
	if (!flag)
		print_error(1, -1);
	flag->a = 0;
	flag->h = 0;
	flag->n = 0;
	return (flag);
}

t_header	*new_header(void)
{
	t_header		*header;

	header = (t_header *)malloc(sizeof(t_header));
	if (!header)
		print_error(1, -1);
	header->magic = get_bigendian(COREWAR_EXEC_MAGIC);
	ft_bzero(header->prog_name, PROG_NAME_LENGTH + 1);
	header->prog_size = 0;
	ft_bzero(header->comment, COMMENT_LENGTH + 1);
	return (header);
}

t_label		*new_label(void)
{
	t_label		*label;

	label = (t_label *)malloc(sizeof(t_label));
	if (!label)
		print_error(1, -1);
	label->next = NULL;
	label->name = NULL;
	return (label);
}
