/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 13:56:08 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/19 20:23:51 by dlavaury         ###   ########.fr       */
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
	tmp = NULL;
	if (core->ps == lst)
	{
		core->ps = core->ps->next;
		core->ps->prev = NULL;
	}
	if (!lst->live)
	{
		ft_printf("One of the processes of the player ");//
		ft_printf("n. %d does not respond anymore.{red}", lst->reg[1]);//
		ft_printf(" FUCK THIS SHIT!!!! He must die now{eoc}\n");//
	}
	lst->next ? lst->next->prev = lst->prev : 0;
	lst->prev ? lst->prev->next = lst->next : 0;
	if (lst->prev)
		tmp = lst->prev;
	else if (lst->next)
		tmp = lst->next;;
	free(lst);
	core ? --core->n_process : 0;
	return (tmp);
}

t_process		*clean_process(t_process *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next)
	{
		lst->next->prev = NULL;
		lst->next = clean_process(lst->next);
	}
	if (lst->prev)
	{
		lst->prev->next = NULL;
		lst->prev = clean_process(lst->prev);
	}
	free(lst);
	return (NULL);
}

void			insert_process(t_core *c, t_process *new)
{
	t_process	*tmp;

	if (!c || !new || (!c->ps && (c->ps = new)))
		return ;
	tmp = c->ps;
	while (tmp->next && new->ins.nb_cycles > tmp->ins.nb_cycles)
		tmp = tmp->next;
	if (new->ins.nb_cycles <= tmp->ins.nb_cycles)
	{
		new->next = tmp;
		new->prev = tmp->prev;
		tmp->prev ? tmp->prev->next = new : 0;
		tmp->prev = new;
	}
	else
	{
		new->prev = tmp;
		new->next = tmp->next;
		tmp->next ? tmp->next->prev = new : 0;
		tmp->next = new;
	}
	tmp->prev && c->ps == tmp->prev ? c->ps = tmp->prev : 0;
}

t_process		*init_process(t_core *core, int i)
{
	t_process	*lst;
	t_process	*new;

	lst = NULL;
	while (++i < (int)core->player)
	{
		if (!(new = new_process(core)))
			return (clean_process(lst));
		new->pc = core->p[i].oc;
		new->reg[1] = core->p[i].id;
		read_instruct(core, new);
		insert_process(core, new);
	}
	lst = core->ps;
	return (lst);
}
