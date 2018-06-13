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
	new->next = NULL;
	new->prev = NULL;
	++core->n_process;
	return (new);
}

t_process			*del_process(t_core *core, t_process *lst)
{
	t_process	*tmp;

	if (!lst)
		return (NULL);
	core->r_2[lst->pc] &= ~(OPC);
	tmp = lst;
	lst = lst->next;
	if (--core->n_process < 1)
		core->ps = NULL;
	else if (core->ps == tmp || !tmp->prev)
	{
		core->ps = core->ps->next;
		core->ps->prev = NULL;
	}
	else
	{
		tmp->prev->next = lst ? lst : NULL;
		lst ? lst->prev = tmp->prev : 0;
	}
	free(tmp);
	return (lst);
}

t_process			*clean_process(t_process *lst)
{
	t_process		*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (NULL);
}

void				insert_process(t_core *c, t_process *new)
{
	if (!c->ps)
	{
		new->next = NULL;
		new->prev = NULL;
		c->ps = new;
	}
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
	t_process		*new;

	while (++i < (int)core->player)
	{
		if (!(new = new_process(core)))
			return (clean_process(core->ps));
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
	return (core->ps);
}
