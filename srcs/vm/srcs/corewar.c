/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:42:35 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/19 20:23:53 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "time.h"
#include "../../libft/includes/ft_printf.h"

static t_process	*process_up(t_core *c, t_process *lst)
{
	t_process		*tmp;

	if (c->n_process < 2)
		return (NULL);
	if ((!lst->prev || (lst->prev->ins.nb_cycles < lst->ins.nb_cycles))
	&& (!lst->next || (lst->next->ins.nb_cycles >= lst->ins.nb_cycles)))
		return (lst->next);
	c->ps == lst ? c->ps = lst->next : 0;
	tmp = lst;
	lst = (lst->next ? lst->next : NULL);
	if (tmp->next)
	{
		lst->prev = tmp->prev ? tmp->prev : NULL;
		tmp->prev ? tmp->prev->next = lst : 0;
	}
	else
		tmp->prev->next = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	insert_process(c, tmp);
	return (lst);
}

static void			check_instruct(t_core *c, unsigned char opc)
{
//	ft_printf("\n{bold}{yellow}{underline}IN\tCHECK_INSTRUCT\t");//
//	ft_printf("{red}CYCLE: %u\n{eoc}", c->total_cycle);//

	t_process		*tmp;

	tmp = c->ps;
	while (tmp)
	{
		if (!tmp->ins.nb_cycles)
		{
			if (opc_c((opc = c->ram[id(tmp->pc)] - 1)) && tmp->ins.name)
			{
				if (!ft_strcmp(tmp->ins.name, g_op_tab[opc].name))
				{
					if (c->ft[opc](&c->ram[id(tmp->pc + 1)], tmp))
					{

	system("clear");//
	ft_printf("cycle: [%5d]\tn_process: [%2d]\topc: [%2hhu]\tp->pc: [%5u]\tins: [%s]\n\n", c->total_cycle, c->n_process, opc, tmp->pc, g_op_tab[opc].name);//
	for (int i = 1; i <= 16; ++i)//
	{//
		ft_printf("reg[%2u] = {magenta}%p{eoc}\t", i, tmp->reg[i]);//
		!(i % 8) ? ft_printf("\n") : 0;//
	}//

						c->ex[opc](c, tmp);

	ft_print_mem(&c->ram, MEM_SIZE, 64, 0);//
	nanosleep((const struct timespec[]){{0, 100000000L}}, NULL);

					}
					else
						tmp->pc = id(tmp->pc + 1);
				}
			}
			else
				tmp->pc = id(tmp->pc + 1);
/*
			ft_printf("\t{magenta}tmp->ins.nb_cycles: ");//
			ft_printf("%u{eoc}\n", tmp->ins.nb_cycles);//
*/
			tmp = read_instruct(c, tmp) ? process_up(c, tmp) : tmp->next;
		}
		else
		{
/*
			ft_printf("\ntmp->ins.nb_cycles: %u\t", tmp->ins.nb_cycles);//
			ft_printf("ins.name: %s\t", tmp->ins.name);//
			ft_printf("n_process: %u\n", c->n_process);//
*/
			--tmp->ins.nb_cycles;
			tmp = tmp->next;
		}
	}

//	ft_printf("{bold}{yellow}{underline}END\tCHECK_INSTRUCT{eoc}\n");//

}
static void		put_champ(t_core *core)
{
	unsigned	i;

	if (core->dump && core->total_cycle == (int)core->dump)
		return ;
	if (!core->last_live_player)
	{
		ft_printf("There is no winner at the end of this game\n");
		return ;
	}
	i = 0;
	while (i < core->player && core->p[i].id != core->last_live_player)
		++i;
	ft_printf("le joueur %u(%s) a gagne\n", core->p[i].id, core->p[i].name);
}
void				corewar(t_core *core)
{
//	ft_printf("{bold}{red}IN\tCOREWAR{eoc}\n");//

	if (!(core->ps = init_process(core, -1)))
		return ((void)display_error(core, 0, NULL));
	while (core->n_process > 0 && core->max_cycle > 0)
	{
/*
		ft_printf("{bold}{red}current cycle: %u\tcycle_to_die: %d\tbefore cycle_to_die: %d\tcurrent_live: %d\n{eoc}",  core->current_cycle, core->max_cycle, core->max_cycle - core->current_cycle, core->current_cycle_live);
*/
		check_instruct(core, 0);
		if (cycle_checker(core))
			break ;
		++core->total_cycle;
		++core->current_cycle;
	}

	ft_printf("{bold}\n%u process in progress at end\nend after %u cycles\n{red}END\tCOREWAR{eoc}\n", core->n_process, core->total_cycle);//

	put_champ(core);
	core->n_process ? clean_process(core->ps) : 0;
}
