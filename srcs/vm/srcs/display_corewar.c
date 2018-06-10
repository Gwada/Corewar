#include "corewar.h"
#include "time.h"
#include "../../libft/includes/ft_printf.h"

void		put_header(t_core *c, t_process *p, unsigned char opc)
{
	char	h[1024];
	int		i_1;
	int		i_2;

	i_1 = 0;
	i_2 = 0;
	ft_bzero(h, 1024);

	i_1 += ft_psprintf(&h[i_1], "{bold}cycle:\t\t[{magenta}");//
	i_1 += ft_psprintf(&h[i_1], "%5d{eoc}{bold}]\t", c->total_cycle);//
	i_1 += ft_psprintf(&h[i_1], "current_cycle:\t[{green}");//
	i_1 += ft_psprintf(&h[i_1], "%4d{eoc}{bold}]\t", c->current_cycle);//
	i_1 += ft_psprintf(&h[i_1], "current_live:\t[{green}");//
	i_1 += ft_psprintf(&h[i_1], "%5d{eoc}{bold}]\t", c->current_cycle_live);

	i_1 += ft_psprintf(&h[i_1], "cycle_to_die:\t[%4d]\t{red}last_decr:\t[%2d]\nn_process:\t[%5d]\t{yellow}p->pc:\t\t[%4u]\topc:\t\t[%2hhu]\n\n{eoc}", c->current_cycle_live, c->max_cycle, c->last_decr, c->n_process, p->pc, opc);//
//	i_1 += ft_psprintf(&h[i_1], "{bold}{magenta}cycle:\t\t[%5d]\t{green}current_cycle:\t[%4d]\t{green}current_live:\t[%5d]\tcycle_to_die:\t[%4d]\t{red}last_decr:\t[%2d]\nn_process:\t[%5d]\t{yellow}p->pc:\t\t[%4u]\topc:\t\t[%2hhu]\n\n{eoc}", c->total_cycle, c->current_cycle, c->current_cycle_live, c->max_cycle, c->last_decr, c->n_process, p->pc, opc);//
		ft_printf("%s\n", h);
/*		for (int i = 1; i <= 16; ++i)//
		{//
			i_2 += ft_printf("reg[%2u] = {magenta}%10#x{eoc}\t", i, p->reg[i]);//
			!(i % 8) ? i_2 += ft_printf("\n") : 0;//
		}//
*/		ft_printf("i_1 = %d\ti_2 = %d\n", i_1, i_2);


}

void		display_cw(t_core *c, t_process *p, unsigned char opc, int state)
{
	if (!state)
	{
//		system("clear");//

		ft_printf("{bold}{yellow}IN\tDISPLAY_COREWAR part 1\n{eoc}");//
		put_header(c, p, opc);
		ft_printf("{bold}{yellow}END\tDISPLAY_COREWAR part 1\n\n{eoc}");//

	}
	else if (state == 1)
	{
//		ft_printf("{bold}{yellow}\nIN\tDISPLAY_COREWAR part 2\n{eoc}");//
	//	ft_print_mem(&c->ram, MEM_SIZE, 64, 0);//
	//	nanosleep((const struct timespec[]){{0, 100000000L}}, NULL);//

//		ft_printf("{bold}{yellow}END\tDISPLAY_COREWAR part 2\n{eoc}");//

	}
}
