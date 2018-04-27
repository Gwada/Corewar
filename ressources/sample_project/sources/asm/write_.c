/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 22:12:18 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/24 18:32:07 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
		tmp = get_bigendian(cmd->p_val[i]) >>
			(8 * (4 - get_size(cmd->p_name[i], cmd->opcode)));
		write(fd, &tmp, get_size(cmd->p_name[i], cmd->opcode));
	}
}

void	write_file(t_data *data)
{
	int		fd;
	t_cmd	*cmd;

	if ((fd = open(data->dst, O_FLAGS, S_FLAGS)) <= 0)
		print_error(16, 0);
	data->header->prog_size = get_bigendian(data->header->prog_size);
	write(fd, data->header, sizeof(t_header));
	cmd = data->cmd;
	while (cmd && cmd->opcode)
	{
		write_cmd(fd, cmd);
		cmd = cmd->next;
	}
	ft_putstr(data->dst);
	ft_putchar('\n');
	close(fd);
}
