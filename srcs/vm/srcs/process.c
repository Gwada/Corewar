/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 13:56:08 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/12 19:24:52 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

t_process		*new_process(t_core *core)
{
	t_process	*new;

	if (!(new = malloc(sizeof(t_process))))
		return (NULL);
	ft_bzero(new, sizeof(t_process));
	++core->n_process;
	return (new);
}

t_process		*del_process(t_core *core, t_process *lst)
{
	t_process	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst->next;
	if (!lst->live)
	{
		ft_printf("One of the processes of the player ");//
		ft_printf("n. %u does not respond anymore.{red}", lst->rg[1]);//
		ft_printf(" FUCK THIS SHIT!!!! He must die now{eoc}\n");//
	}
	free(lst);
	core ? --core->n_process : 0;
	return (tmp);
}

t_process		*clean_process(t_process *lst)
{
	if (lst)
	{
		lst->next ? lst->next = clean_process(lst->next) : 0;
		free(lst);
	}
	return (NULL);
}

void			insert_process(t_process **lst, t_process *new)
{
	t_process	*tmp;

	tmp = *lst;
	if (!new)
		return ;
	if (!*lst && (*lst = new))
		return ;
	if (new->ins.nb_cycles <= (*lst)->ins.nb_cycles)
	{
		new->next = *lst;
		*lst = new;
		return ;
	}
	while (tmp->next)
	{
		if (new->ins.nb_cycles <= tmp->next->ins.nb_cycles)
			break ;
		tmp = tmp->next;
	}
	tmp->next ? new->next = tmp->next : 0;
	tmp->next = new;
}

t_process		*init_process(t_core *core, int i)
{
	ft_printf("{yellow}{bold}IN\tINIT_PROCESS\n{eoc}");
	t_process	*lst;
	t_process	*new;

	lst = NULL;
	while (++i < (int)core->player)
	{
		if (!(new = new_process(core)))
			return (clean_process(lst));
		*new->rg = core->p[i].oc;
		new->pc = core->p[i].oc;
		new->rg[1] = core->p[i].id;
		read_instruct(core, new);
		insert_process(&lst, new);
	}
	ft_printf("{yellow}{bold}END\tINIT_PROCESS\n\n{eoc}");
	return (lst);
}
