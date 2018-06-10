#include "corewar.h"
#include "time.h"
#include "../../libft/includes/ft_printf.h"

void		put_header(t_core *c, t_process *p, unsigned char opc, int i_1)
{
	char	h[512];

	ft_bzero(h, 512);
	i_1 += ft_psprintf(&h[i_1], "{bold}{yellow}DISPLAY_COREWAR STATES\n");//
	i_1 += ft_psprintf(&h[i_1], "{eoc}{bold}cycle:\t\t[{magenta}");//
	i_1 += ft_psprintf(&h[i_1], "%5d{eoc}{bold}]\t", c->total_cycle);//
	i_1 += ft_psprintf(&h[i_1], "current_cycle:\t[{green}");//
	i_1 += ft_psprintf(&h[i_1], "%4d{eoc}{bold}]\t", c->current_cycle);//
	i_1 += ft_psprintf(&h[i_1], "current_live:\t[{green}");//
	i_1 += ft_psprintf(&h[i_1], "%5d{eoc}{bold}]\t", c->current_cycle_live);
	i_1 += ft_psprintf(&h[i_1], "cycle_to_die:\t[{green}");
	i_1 += ft_psprintf(&h[i_1], "%4d{eoc}{bold}]\t", c->max_cycle);//
	i_1 += ft_psprintf(&h[i_1], "last_decr:\t[{red}");
	i_1 += ft_psprintf(&h[i_1], "%2d{eoc}{bold}]\n", c->last_decr);//
	i_1 += ft_psprintf(&h[i_1], "n_process:\t[{magenta}");
	i_1 += ft_psprintf(&h[i_1], "%5d{eoc}{bold}]\t", c->n_process);//
	i_1 += ft_psprintf(&h[i_1], "p->pc:\t\t[{yellow}");
	i_1 += ft_psprintf(&h[i_1], "%4u{eoc}{bold}]\t", p->pc);//
	i_1 += ft_psprintf(&h[i_1], "opc:\t\t[{yellow}");
	i_1 += ft_psprintf(&h[i_1], "%5hhu{eoc}{bold}]\n\n{eoc}", opc);//
	ft_printf("%s", h);
//	ft_printf("%s\nsize: %d\n", h, i_1);//
}

void		put_process(t_process *p, int i_1, int reg)
{
	char	h[1024];

	ft_bzero(h, 1024);
	i_1 += ft_psprintf(&h[i_1], "{bold}{yellow}PROCESS STATES{eoc}\n");//
	while (++reg < 17)
	{
		i_1 += ft_psprintf(&h[i_1], "{bold}reg[%2u] = ", reg);//
		i_1 += ft_psprintf(&h[i_1], "{magenta}%10#x{eoc}\t", p->reg[reg]);//
		!(reg % 8) ? i_1 += ft_psprintf(&h[i_1], "\n") : 0;//
	}
//	i_1 += ft_psprintf(&h[i_1], "\nprocess name: %s\n", p->ins.description);//
//	ft_printf("%s", h);
	ft_printf("%s\nsize: %d\n", h, i_1);//
}

void		display_cw(t_core *c, t_process *p, unsigned char opc, int state)
{
	if (!state)
	{
		system("clear");//
		put_header(c, p, opc, 0);
		put_process(p, 0, 0);
	}
	else if (state == 1)
	{
//		ft_printf("{bold}{yellow}\nIN\tDISPLAY_COREWAR part 2\n{eoc}");//
	//	ft_print_mem(&c->ram, MEM_SIZE, 64, 0);//
		nanosleep((const struct timespec[]){{0, 100000000L}}, NULL);//

//		ft_printf("{bold}{yellow}END\tDISPLAY_COREWAR part 2\n{eoc}");//

	}
}
