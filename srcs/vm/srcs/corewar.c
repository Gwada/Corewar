/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:42:35 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/14 21:36:21 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

static t_process	*process_up(t_core *c, t_process *lst)
{
	ft_printf("{bold}{red}IN\tPROCESS_UP{eoc}\n");//
	t_process		*tmp;

	if (c->n_process < 2)
	{
		ft_printf("{bold}{red}1 END\tPROCESS_UP{eoc}\n");//
		return (NULL);
	}
	c->ps == lst ? c->ps = lst->next : 0;
	tmp = lst;

	lst = (lst->next ? lst->next : NULL);

/*
	ft_printf("1 {red}tmp->ins.name = %s\n{eoc}", tmp->ins.name);//
	ft_printf("%s\n", tmp->prev ? "prev" : "prev is null");//
	ft_printf("%s\n\n", tmp->next ? "next" : "next is null");//
	ft_printf("1 {red}lst->ins.name = %s\n{eoc}", lst->ins.name);//
	ft_printf("%s\n", lst->prev ? "prev" : "prev is null");//
	ft_printf("%s\n\n", lst->next ? "next" : "next is null");//
*/

	if (tmp->next)
	{
		lst->prev = tmp->prev ? tmp->prev : NULL;
		tmp->prev ? tmp->prev->next = lst : 0;
	}
	else
		tmp->prev->next = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;

/*
	ft_printf("2 {red}tmp->ins.name = %s\n{eoc}", tmp->ins.name);//
	ft_printf("%s\n", tmp->prev ? "prev" : "prev is null");//
	ft_printf("%s\n\n", tmp->next ? "next" : "next is null");//
	ft_printf("2 {red}lst->ins.name = %s\n{eoc}", lst->ins.name);//
	ft_printf("%s\n", lst->prev ? "prev" : "prev is null");//
	ft_printf("%s\n\n", lst->next ? "next" : "next is null");//
*/

	insert_process(c, tmp);

	int i = 0;
	tmp = c->ps;
	ft_printf("core->n_process: %u\n", c->n_process);
	while (tmp)
	{
		ft_printf("process: %d\nins.name: %s\n\n", ++i, tmp->ins.name);
		tmp = tmp->next;
		if (i > 30)
			break ;
	}
	ft_printf("{bold}{red}2 END\tPROCESS_UP{eoc}\n");//
	if (i > 30)
		exit (EXIT_FAILURE);
	return (lst);
}

static void			check_instruct(t_core *c, unsigned char opc)
{
	ft_printf("{bold}{yellow}IN\tCHECK_INSTRUCT{eoc}\n");//
	t_process		*tmp;

	tmp = c->ps;
	while (tmp)
	{
		if (!tmp->ins.nb_cycles)
		{
//			ft_printf("2\n");

			opc = c->ram[id(tmp->opc)] - 1;
//			ft_printf("2.1\t\topc = %hhu\n", opc - 1);

			if (opc_c(opc) && tmp->ins.name)
			{
//				ft_printf("2.1.1\n");

				if (!ft_strcmp(tmp->ins.name, g_op_tab[opc].name))
				{
					ft_printf("2.1.1.1\t\tins: %s\n", g_op_tab[opc].name);

					if (c->ft[opc](&c->ram[id(tmp->opc + 1)], tmp))
					{
//						ft_printf("2.1.1.1.1\n");

						c->ex[opc](c, tmp);
						int i = -1;
						while (++i < 16)
							ft_printf("reg[%u] = %p\t", i, tmp->reg[i]);
						ft_printf("\n2.1.1.1.2\n");
					}
				}
			}
			ft_printf("2.2 tmp->ins.nb_cycles: %u\n", tmp->ins.nb_cycles);

			tmp->opc = id(tmp->opc + 1);
			ft_printf("2.3\n");

			tmp = read_instruct(c, tmp) ? process_up(c, tmp) : tmp->next;
		}
		else
		{
			ft_printf("1\tins.nb_cycles: %u\t", tmp->ins.nb_cycles - 1);
			ft_printf("n_process: %u\n", c->n_process);
			--tmp->ins.nb_cycles;
			tmp = tmp->next;
		}
	}
	ft_printf("\n{bold}{yellow}END\tCHECK_INSTRUCT{eoc}\n\n");//
}
static void		put_champ(t_core *core)
{
	unsigned	i;

	if (core->dump && core->total_cycle == core->dump)
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
	ft_printf("{bold}{red}IN\tCOREWAR{eoc}\n");//

	if (!(core->ps = init_process(core, -1)))
		return (display_error(core, 0));
	while (core->n_process > 0)
	{
		ft_printf("cycle: %05u\n", core->total_cycle);
		if (cycle_checker(core))
			break ;
		check_instruct(core, 0);
		++core->total_cycle;
		++core->current_cycle;
	}

	ft_printf("\nthere are %u total cycles\n", core->total_cycle);//
	ft_printf("%u process in progress\n", core->n_process);//
	ft_printf("{bold}{red}END\tCOREWAR{eoc}\n");//

	put_champ(core);
	core->n_process ? clean_process(core->ps) : 0;
}
