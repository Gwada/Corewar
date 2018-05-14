/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:56:18 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/05/13 22:49:19 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h>

# define O_FLAGS    O_RDWR | O_CREAT | O_TRUNC
# define S_FLAGS    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

int		get_optab_index(int opcode)
{
	int		i;

	i = 0;
	while (i < 16 && g_op_tab[i].op_code != opcode)
		i++;
	return (i);
}

uint32_t		swap_bigendian(int var)
{
	uint32_t	r;

	r = var;
	r = (r >> 24) | ((r << 8) & 0x00ff0000) |
		((r >> 8) & 0x0000ff00) | (r << 24);
	return (r);
}

void	write_cmd(int fd, t_cmd *cmd)
{
	int		i;
	int		tmp;

	write(fd, &cmd->opcode, 1);
	if (g_op_tab[get_optab_index(cmd->opcode)].ocp)
		write(fd, &cmd->ocp, 1);
	i = -1;
	while (++i < 3 && cmd->p_name[i])
	{
		tmp = swap_bigendian(cmd->p_val[i]) >>
			(8 * (4 - get_size(cmd->p_name[i], cmd->opcode)));
		write(fd, &tmp, get_size(cmd->p_name[i], cmd->opcode));
	}
}

void	write_file(t_data *data)
{
	int		fd;
	t_cmd	*cmd;

	if ((fd = open(data->cor, O_FLAGS, S_FLAGS)) <= 0)
		handle_err(16, 0);
	data->header->prog_size = swap_bigendian(data->header->prog_size);
	write(fd, data->header, sizeof(t_header));
	cmd = data->cmd;
	while (cmd && cmd->opcode)
	{
		write_cmd(fd, cmd);
		cmd = cmd->next;
	}
	ft_putstr(data->cor);
	ft_putchar('\n');
	close(fd);
}

void		read_cmd(int fd, t_data *data)
{
	int		ret;
	t_cmd	*cmd;

	cmd = data->cmd;
	data->gnl ? ft_strdel(&data->gnl) : 0;
	while ((ret = get_next_line(fd, &data->gnl)) > 0)
	{
		data->line++;
		ft_char_replace(data->gnl, COMMENT_CHAR, '\0');
		ft_strptr_replace(&data->gnl, ft_strrm_borders(data->gnl));
		!data->line ? handle_err(MALLOC_ERR, QUIT) : 0;
		cmd->index = data->header->prog_size;
		get_label(&data->gnl, cmd);
		get_cmd(data->gnl, cmd, data);
		data->gnl ? ft_strdel(&data->gnl) : 0;
		if (cmd->opcode && (cmd->next = init_cmd()))
			cmd = cmd->next;
	}
	printf("data->prog_size: %d\n", data->header->prog_size);
	data->gnl ? ft_strdel(&data->gnl) : 0;
	ret == -1 ? handle_err(5, QUIT) : 0;
}

void		read_header(int fd, t_data *data)
{
	int		ret;

	while ((ret = get_next_line(fd, &data->gnl)) > 0)
	{
		data->line++;
		ft_char_replace(data->gnl, COMMENT_CHAR, '\0');
		ft_strptr_replace(&data->gnl, ft_strrm_borders(data->gnl));
		!data->line ? handle_err(MALLOC_ERR, QUIT) : 0;
		if (!*data->gnl)
			data->gnl ? ft_strdel(&data->gnl) : 0;
		else if (!(ft_strncmp(data->gnl, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING))))
			get_name(data->gnl + ft_strlen(NAME_CMD_STRING), data, fd);
		else if (!(ft_strncmp(data->gnl, COMMENT_CMD_STRING,
			ft_strlen(COMMENT_CMD_STRING))))
			get_comment(data->gnl + ft_strlen(COMMENT_CMD_STRING), data, fd);
		else if (*data->gnl && ft_strncmp(data->gnl, NAME_CMD_STRING,
			ft_strlen(NAME_CMD_STRING)) && ft_strncmp(data->gnl,
			COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
			break;
		data->gnl ? ft_strdel(&data->gnl) : 0;
		if (data->name && data->comment)
			return ;
	}
	ret == -1 ? handle_err(5, QUIT) : 0;
}

void		read_file(t_data *data)
{
	int		fd;
	int		i;

	i = -1;
	(fd = open(data->s, O_RDONLY)) < 0 ? handle_err(5, -1) : 0;
	read_header(fd, data);
	!data->name ? handle_err(6, data->line) : 0;
	!data->comment ? handle_err(7, data->line) : 0;
	read_cmd(fd, data);
	close(fd);
	!data->header->prog_size ? handle_err(16, QUIT) : 0;
	data->eof = 1;
	check_labels(data);
	write_file(data);
//	free_data(data);
}
