/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 22:30:50 by brigoux           #+#    #+#             */
/*   Updated: 2016/06/18 22:27:21 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		read_source(t_data *data)
{
	int		fd;

	if (!((fd = open(data->src, O_RDONLY)) > 0))
		print_error(4, -1);
	read_name(fd, data);
	read_comment(fd, data);
	read_commands(fd, data);
	close(fd);
	data->end = 1;
	if (!data->header->prog_size)
		print_error(15, 0);
	check_labels(data);
}

void		read_name(int fd, t_data *data)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		data->line++;
		ft_strreplace(line, COMMENT_CHAR, '\0');
		ft_strfreedef(&line, ft_strstrip(line));
		if (!line)
			print_error(1, -1);
		if (!*line)
			continue;
		if (!ft_strncmp(NAME_CMD_STRING, line, ft_strlen(NAME_CMD_STRING)))
		{
			store_name(line + ft_strlen(NAME_CMD_STRING), data);
			free(line);
			return ;
		}
		free(line);
		break ;
	}
	if (ret == -1)
		print_error(1, -1);
	else
		print_error(5, data->line + !ret);
}

void		read_comment(int fd, t_data *data)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		data->line++;
		ft_strreplace(line, COMMENT_CHAR, '\0');
		if (!ft_strfreedef(&line, ft_strstrip(line)))
			print_error(1, -1);
		if (!*line)
			continue;
		if (!ft_strncmp(COMMENT_CMD_STRING, line,
					ft_strlen(COMMENT_CMD_STRING)))
		{
			store_comment(line + ft_strlen(COMMENT_CMD_STRING), data);
			free(line);
			return ;
		}
		free(line);
		break ;
	}
	if (ret == -1)
		print_error(1, -1);
	else
		print_error(7, data->line + !ret);
}

void		read_commands(int fd, t_data *data)
{
	char	*line;
	int		ret;
	t_cmd	*cmd;

	cmd = data->cmd;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		data->line++;
		ft_strreplace(line, COMMENT_CHAR, '\0');
		ft_strfreedef(&line, ft_strstrip(line));
		if (!line)
			print_error(1, -1);
		cmd->index = data->header->prog_size;
		store_label(&line, cmd);
		store_cmd(line, cmd, data);
		free(line);
		if (cmd->opcode && (cmd->next = new_cmd()))
			cmd = cmd->next;
	}
	if (ret == -1)
		print_error(1, -1);
}
