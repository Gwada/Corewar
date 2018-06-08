#include "corewar.h"
#include "time.h"
#include "../../libft/includes/ft_printf.h"

void	display_corewar(t_core *c, t_process *p, unsigned char opc, int state)
{
	if (!state)
	{
	   system("clear");//

		ft_printf("{bold}{yellow}IN\tDISPLAY_COREWAR part 1\n{eoc}");//

		ft_printf("{bold}{magenta}cycle:\t\t[%5d]\t{green}current_cycle:\t[%4d]\t{green}current_live:\t[%4d]\tmax_cycle:\t[%4d]\t{red}last_decr:\t[%2d]\nn_process:\t[%3d]\t{yellow}p->pc:\t\t[%5u]\topc:\t\t[%2hhu]\n\n{eoc}", c->total_cycle, c->current_cycle, c->current_cycle_live, c->max_cycle, c->last_decr, c->n_process, p->pc, opc);//
		for (int i = 1; i <= 16; ++i)//
		{//
			ft_printf("reg[%2u] = {magenta}%10#x{eoc}\t", i, p->reg[i]);//
			!(i % 8) ? ft_printf("\n") : 0;//
		}//

		ft_printf("{bold}{yellow}END\tDISPLAY_COREWAR part 1\n\n{eoc}");//

	}
	else if (state == 1)
	{
		ft_printf("{bold}{yellow}\nIN\tDISPLAY_COREWAR part 2\n{eoc}");//
//		ft_print_mem(&c->ram, MEM_SIZE, 64, 0);//
		nanosleep((const struct timespec[]){{0, 200000000L}}, NULL);//

		ft_printf("{bold}{yellow}END\tDISPLAY_COREWAR part 2\n{eoc}");//

	}

}
