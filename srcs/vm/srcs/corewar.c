/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:42:35 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/18 20:27:44 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

static t_process	*process_up(t_core *c, t_process *lst)
{
	t_process		*tmp;

	if (c->n_process < 2)
		return (NULL);
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
/*		ft_printf("\n");
		for (int i = 1; i <= 16; ++i)//
		{//
			ft_printf("reg[%2u] = {magenta}%p{eoc}\t", i, tmp->reg[i]);//
			i == 8 ? ft_printf("\n") : 0;//
		}//
*/
		if (!tmp->ins.nb_cycles)
		{

//			ft_printf("\n2.1 opc: %hhu\t p->pc: %u", opc, tmp->pc);//

			if (opc_c((opc = c->ram[id(tmp->pc)] - 1)) && tmp->ins.name)
			{
//				ft_printf("\t2.1.1\t\tins: %s\t|", g_op_tab[opc].name);//
				if (!ft_strcmp(tmp->ins.name, g_op_tab[opc].name))
				{

//					ft_printf("\t2.1.1.1\t\tins: %s\n", g_op_tab[opc].name);//

					if (c->ft[opc](&c->ram[id(tmp->pc + 1)], tmp))
						c->ex[opc](c, tmp);
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
		ft_printf("There is no winner at the end of this game\n");//
		return ;
	}
	i = 0;
	while (i < core->player && core->p[i].id != core->last_live_player)
		++i;
	ft_printf("le joueur %u(%s) a gagne\n", core->p[i].id, core->p[i].name);//
}
void				corewar(t_core *core)
{
//	ft_printf("{bold}{red}IN\tCOREWAR{eoc}\n");//

	if (!(core->ps = init_process(core, -1)))
		return ((void)display_error(core, 0, NULL));
	int test = 0;
	while (core->n_process > 0 && core->max_cycle > 0)
	{
/*		ft_printf("{bold}{red}current cycle: %u\t", core->current_cycle);
		ft_printf("cycle_to_die: %d\t", core->max_cycle);
		ft_printf("before cycle_to_die: %d\t", core->max_cycle - core->current_cycle);
		ft_printf("current_live: %d\n{eoc}", core->current_cycle_live);
*/		check_instruct(core, 0);
		if (cycle_checker(core))
			break ;
		++core->total_cycle;
		++core->current_cycle;
		if (!(++test % 75))
		{
			system("clear");
			ft_print_mem(&core->ram, MEM_SIZE, 64, 0);
		}
	}

	ft_printf("\n%u process in progress at end\n", core->n_process);//
	ft_printf("\nend after %u cycles\n", core->total_cycle);//
	ft_printf("{bold}{red}END\tCOREWAR{eoc}\n");//

	put_champ(core);
	core->n_process ? clean_process(core->ps) : 0;
}
