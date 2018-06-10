/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 13:56:08 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/10 18:25:50 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

t_process			*new_process(t_core *core)
{
	t_process	*new;

	if (!(new = malloc(sizeof(t_process))))
		return (NULL);
	ft_bzero(new, sizeof(t_process));
	++core->n_process;
	return (new);
}

t_process			*del_process(t_core *core, t_process *lst)
{
	t_process	*tmp;

	if (!lst || !core)
		return (NULL);
//	ft_printf("dp1\n"); //
	core->r_2[lst->pc] &= ~(OPC);
	tmp = lst;
	lst = lst->next;
	if (--core->n_process < 1)
	{
//		ft_printf("dp2\n"); //
		core->ps = NULL;
	}
	else if (core->ps == tmp || !tmp->prev)
	{
//		ft_printf("dp3\n"); //
		core->ps = core->ps->next;
		core->ps->prev = NULL;
	}
	else
	{
//		ft_printf("dp4\n"); //
		tmp->prev->next = tmp->next;
//		ft_printf("dp4.1\n"); //
		tmp->next ? tmp->next->prev = tmp->prev : 0;
//		ft_printf("dp4.2\n"); //
	}
//	ft_printf("dp5\n"); 
	free(tmp);
//	ft_printf("dp6\n"); 
	return (lst);
}

t_process			*clean_process(t_process *lst)
{
//	ft_printf("test10\n");
	if (!lst)
		return (NULL);
//	ft_printf("test11\n");
	if (lst->next)
	{
//	ft_printf("test12\n");
		lst->next->prev = NULL;
		lst->next = clean_process(lst->next);
	}
	if (lst->prev)
	{
//	ft_printf("test13\n");
		lst->prev->next = NULL;
		lst->prev = clean_process(lst->prev);
	}
//	ft_printf("test14\n");
	free(lst);
	return (NULL);
}

void				insert_process(t_core *c, t_process *new)
{
/*	t_process		*tmp;

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
	*/
	if (!c->ps)
		c->ps = new;
	else
	{
		new->next = c->ps;
		c->ps->prev = new;
		c->ps = new;
	}
}

t_process			*init_process(t_core *core, int i)
{
	unsigned int	process;
	t_process		*lst;
	t_process		*new;

	lst = NULL;
	while (++i < (int)core->player)
	{
		if (!(new = new_process(core)))
			return (clean_process(lst));
		new->pc = core->p[i].oc;
		core->r_2[new->pc] |= OPC;
		*new->reg = core->p[i].id;
		core->p[i].id = -core->p[i].id;
		new->reg[1] = core->p[i].id;
		read_instruct(core, new);
		insert_process(core, new);
		process = 0;
		while (process < core->p[i].prog_size)
			core->r_2[new->pc + process++] |= 1 << (*new->reg - 1);
	}
	lst = core->ps;
	return (lst);
}
