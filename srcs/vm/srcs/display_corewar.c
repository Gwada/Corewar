/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_corewar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:01:19 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/13 16:30:28 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "time.h"
#include "../../libft/includes/ft_printf.h"

static void	put_general(t_core *c, t_process *p, unsigned char opc, int i_1)
{
	char	buff[512];

	i_1 += ft_psprintf(&buff[i_1], "{bold}{yellow}GENERAL\tSTATES{eoc}\n");
	i_1 += ft_psprintf(&buff[i_1], "{bold}cycle:\t\t[{magenta}");
	i_1 += ft_psprintf(&buff[i_1], "%5d{eoc}{bold}]\t", c->total_cycle);
	i_1 += ft_psprintf(&buff[i_1], "current_cycle:\t[{green}");
	i_1 += ft_psprintf(&buff[i_1], "%4d{eoc}{bold}]\t", c->current_cycle);
	i_1 += ft_psprintf(&buff[i_1], "current_live:\t[{green}");
	i_1 += ft_psprintf(&buff[i_1], "%5d{eoc}{bold}]\t", c->current_cycle_live);
	i_1 += ft_psprintf(&buff[i_1], "cycle_to_die:\t[{green}");
	i_1 += ft_psprintf(&buff[i_1], "%4d{eoc}{bold}]\t", c->max_cycle);
	i_1 += ft_psprintf(&buff[i_1], "last_decr:\t[{red}");
	i_1 += ft_psprintf(&buff[i_1], "%2d{eoc}{bold}]\n", c->last_decr);
	i_1 += ft_psprintf(&buff[i_1], "n_process:\t[{magenta}");
	i_1 += ft_psprintf(&buff[i_1], "%5d{eoc}{bold}]\t", c->n_process);
	i_1 += ft_psprintf(&buff[i_1], "p->pc:\t\t[{yellow}");
	i_1 += ft_psprintf(&buff[i_1], "%4u{eoc}{bold}]\t", p->pc);
	i_1 += ft_psprintf(&buff[i_1], "opc:\t\t[{yellow}");
	i_1 += ft_psprintf(&buff[i_1], "%5hhu{eoc}{bold}]\n\n{eoc}", opc);
	i_1 += ft_psprintf(&buff[i_1], "{bold}{yellow}PROCESS\tSTATES{eoc}\n");
	write(1, buff, i_1);
}

static void	put_process(t_core *c, t_process *p, int i_1, int reg)
{
	while (++reg < 17)
	{
		i_1 += ft_psprintf(&c->buff[i_1], "{bold}reg[%2u] = {magenta}", reg);
		i_1 += ft_psprintf(&c->buff[i_1], "%10#x{eoc}\t", p->reg[reg]);
		!(reg % 8) ? i_1 += ft_psprintf(&c->buff[i_1], "\n") : 0;
	}
	i_1 += ft_psprintf(&c->buff[i_1], "\nprocess name\t: {green}{bold}");
	i_1 += ft_psprintf(&c->buff[i_1], "%s{bold}", p->ins.description);
	i_1 += ft_psprintf(&c->buff[i_1], "{eoc}\ndescription\t: ");
	write(1, c->buff, i_1);
}

static void	get_state(t_core *c, int i, int j, int *l)
{
	if (c->r_2[i + j] & FST)
		*l += ft_psprintf(&c->buff[*l], "{green}");
	else if (c->r_2[i + j] & SND)
		*l += ft_psprintf(&c->buff[*l], "{yellow}");
	else if (c->r_2[i + j] & TRD)
		*l += ft_psprintf(&c->buff[*l], "{magenta}");
	else if (c->r_2[i + j] & FOTH)
		*l += ft_psprintf(&c->buff[*l], "{red}");
	if (c->r_2[i + j] & NEW)
	{
		*l += ft_psprintf(&c->buff[*l], "{dim}");
		c->r_2[i + j] &= ~NEW;
	}
	if (c->r_2[i + j] & OPC)
		*l += ft_psprintf(&c->buff[*l], "{inverted}");
}

static void	put_corewar(t_core *c, int i, int l)
{
	char	*hex;
	int		j;

	hex = "0123456789abcdef";
	while (i < MEM_SIZE)
	{
		j = -1;
		l = 0;
		l += ft_psprintf(&c->buff[l], "{bold}{cyan}%05#X{eoc} : ", i);
		while (++j < 64 && i + j < MEM_SIZE)
		{
			get_state(c, i, j, &l);
			c->buff[l++] = hex[c->ram[i + j] / 16 % 16];
			c->buff[l++] = hex[c->ram[i + j] % 16];
			c->r_2[i + j] ? l += ft_psprintf(&c->buff[l], "{eoc}") : 0;
			c->buff[l++] = ' ';
		}
		c->buff[l++] = '\n';
		write(1, c->buff, l);
		i += 64;
	}
}

void		display_cw(t_core *c, t_process *p, unsigned char opc, int state)
{
	if (c->total_cycle < c->debug)
		return ;
	if (!state)
	{
		system("clear");
		put_general(c, p, opc, 0);
		put_process(c, p, 0, 0);
	}
	else if (state == 1)
	{
		ft_printf("\n{bold}{yellow}COREWAR\tSTATES{eoc}\n");
		put_corewar(c, 0, 0);
		nanosleep((const struct timespec[]){{0, 80000000L}}, NULL);
	}
}
