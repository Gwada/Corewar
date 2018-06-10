#include "corewar.h"
#include "time.h"
#include "../../libft/includes/ft_printf.h"

static void	put_general(t_core *c, t_process *p, unsigned char opc, int i_1)
{
	char	buff[512];

	ft_bzero(buff, 512);
	i_1 += ft_psprintf(&buff[i_1], "{bold}{yellow}GENERAL\tSTATES{eoc}\n");//
	i_1 += ft_psprintf(&buff[i_1], "{bold}cycle:\t\t[{magenta}");//
	i_1 += ft_psprintf(&buff[i_1], "%5d{eoc}{bold}]\t", c->total_cycle);//
	i_1 += ft_psprintf(&buff[i_1], "current_cycle:\t[{green}");//
	i_1 += ft_psprintf(&buff[i_1], "%4d{eoc}{bold}]\t", c->current_cycle);//
	i_1 += ft_psprintf(&buff[i_1], "current_live:\t[{green}");//
	i_1 += ft_psprintf(&buff[i_1], "%5d{eoc}{bold}]\t", c->current_cycle_live);
	i_1 += ft_psprintf(&buff[i_1], "cycle_to_die:\t[{green}");
	i_1 += ft_psprintf(&buff[i_1], "%4d{eoc}{bold}]\t", c->max_cycle);//
	i_1 += ft_psprintf(&buff[i_1], "last_decr:\t[{red}");
	i_1 += ft_psprintf(&buff[i_1], "%2d{eoc}{bold}]\n", c->last_decr);//
	i_1 += ft_psprintf(&buff[i_1], "n_process:\t[{magenta}");
	i_1 += ft_psprintf(&buff[i_1], "%5d{eoc}{bold}]\t", c->n_process);//
	i_1 += ft_psprintf(&buff[i_1], "p->pc:\t\t[{yellow}");
	i_1 += ft_psprintf(&buff[i_1], "%4u{eoc}{bold}]\t", p->pc);//
	i_1 += ft_psprintf(&buff[i_1], "opc:\t\t[{yellow}");
	i_1 += ft_psprintf(&buff[i_1], "%5hhu{eoc}{bold}]\n\n{eoc}", opc);//
	i_1 += ft_psprintf(&buff[i_1], "{bold}{yellow}PROCESS\tSTATES{eoc}\n");//
	ft_printf("%s", buff);
//	ft_printf("%s\nsize: %d\n", buff, i_1);//
}

static void	put_process(t_process *p, int i_1, int reg)
{
	char	buff[1024];

	ft_bzero(buff, 1024);
	while (++reg < 17)
	{
		i_1 += ft_psprintf(&buff[i_1], "{bold}reg[%2u] = ", reg);//
		i_1 += ft_psprintf(&buff[i_1], "{magenta}%10#x{eoc}\t", p->reg[reg]);//
		!(reg % 8) ? i_1 += ft_psprintf(&buff[i_1], "\n") : 0;//
	}
	i_1 += ft_psprintf(&buff[i_1], "\nprocess name\t: \"{green}{bold}");//
	i_1 += ft_psprintf(&buff[i_1], "%50s{bold}{eoc}\"\n", p->ins.description);//
	i_1 += ft_psprintf(&buff[i_1], "description\t: \"");//

	ft_printf("%s", buff);
//	ft_printf("%s\nsize: %d\n", buff, i_1);//
}

static void	put_corewar(t_core *c, t_process *p, int i, int l)
{
	char	buff[2048];
	char	*hex;
	int		j;

	hex = "0x";
	ft_bzero(buff, 2048);
	ft_printf("%s\n", c->buff);
	while (i < MEM_SIZE && (j = -1) && !(l = 0))
	{
		l += ft_psprintf(&buff[l], "{bold}{cyan}%s%04x{eoc} : ", hex, i);//
		while (++j < 64 && i + j < MEM_SIZE)
		{
			if (c->r_2[i + j] & FST)
				l += ft_psprintf(&buff[l], "{green}");//
			else if (c->r_2[i + j] & SND)
				l += ft_psprintf(&buff[l], "{yellow}");//
			else if (c->r_2[i + j] & TRD)
				l += ft_psprintf(&buff[l], "{magenta}");//
			else if (c->r_2[i + j] & FOTH)
				l += ft_psprintf(&buff[l], "{red}");//
			if (c->r_2[i + j] & NEW)
			{
				l += ft_psprintf(&buff[l], "{dim}");//
				c->r_2[i + j] &= ~NEW;
			}
			if (c->r_2[i + j] & OPC)
				l += ft_psprintf(&buff[l], "{inverted}");//
			l += ft_psprintf(&buff[l], "%02hhx", c->ram[i + j]);//
			c->r_2[i + j] ? l += ft_psprintf(&buff[l], "{eoc}") : 0;//
			l += ft_psprintf(&buff[l], " ");//
		}
		ft_printf("%s\n", buff);
		ft_bzero(buff, 2048);
		i += 64;
	}
	(void)p;
}

void		display_cw(t_core *c, t_process *p, unsigned char opc, int state)
{
	if (!state)
	{
		system("clear");//
		put_general(c, p, opc, 0);
	}
	else if (state == 1)
	{
		put_process(p, 0, 0);
		ft_bzero(c->buff, 512);
		ft_printf("\n{bold}{yellow}COREWAR\tSTATES{eoc}\n");//
		put_corewar(c, p, 0, 0);
		nanosleep((const struct timespec[]){{0, 100000000L}}, NULL);//
	}
}
