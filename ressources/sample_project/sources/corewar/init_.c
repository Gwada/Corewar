/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <brigoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 11:55:40 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/25 21:48:02 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		init_player(int n)
{
	int			fd;
	t_player	*p;

	p = &g_data->player[n];
	if (!ft_strequ(p->file_name + ft_strlen(p->file_name) - 4, ".cor"))
		print_error(8);
	if ((fd = open(p->file_name, O_RDONLY)) < 0)
		print_error(7);
	if (read(fd, &p->header, sizeof(t_header)) != sizeof(t_header))
		print_error(9);
	p->header.prog_size = get_revertint(p->header.prog_size);
	if (p->header.prog_size > CHAMP_MAX_SIZE)
		print_error(10);
	p->header.magic = get_revertint(p->header.magic);
	if (p->header.magic != COREWAR_EXEC_MAGIC)
		print_error(9);
	p->champion = ft_strnew(p->header.prog_size);
	if (read(fd, p->champion, p->header.prog_size) != p->header.prog_size)
		print_error(9);
	if (read(fd, p->champion + p->header.prog_size, 1))
		print_error(9);
	close(fd);
}

void		init_process(t_process *old, int pc)
{
	t_process		*new;

	if (!(new = (t_process *)malloc(sizeof(t_process))))
		print_error(1);
	ft_memcpy(new, old, sizeof(t_process));
	if (ft_inrange(get_intfrommem(pc, 1), 1, 17))
		new->timer = g_op_tab[get_intfrommem(pc, 1) - 1].timer - 1;
	new->pc = pc;
	g_data->last_pnum++;
	new->num = g_data->last_pnum;
	g_data->status[pc] |= STAT_PC;
	new->next = g_data->process;
	g_data->process = new;
}

void		init_vm(void)
{
	t_process	process;
	int			p;

	ft_bzero(&process, sizeof(t_process));
	p = -1;
	while (++p < MAX_PLAYERS && g_data->player[p].file_name)
		init_player(p);
	check_playerorder();
	p = -1;
	while (++p < MAX_PLAYERS && g_data->player[p].file_name)
	{
		set_memory(p * MEM_SIZE / get_nbplayers(), g_data->player[p].champion,
				g_data->player[p].header.prog_size);
		ft_memset(g_data->status + p * MEM_SIZE / get_nbplayers(), (p + 1) << 4,
			g_data->player[p].header.prog_size);
		process.reg[0] = -g_data->player[p].number;
		process.player = p;
		init_process(&process, p * MEM_SIZE / get_nbplayers());
	}
	g_data->cycle_to_die = CYCLE_TO_DIE;
	g_data->cycle = 1;
	g_data->last_live = 1;
}
