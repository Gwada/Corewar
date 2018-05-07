/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 13:56:08 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/07 21:30:07 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

t_process		*new_process(void)
{
	t_process	*new;

	if (!(new = malloc(sizeof(t_process))))
		return (NULL);
	ft_bzero(new, sizeof(t_process));
	return (new);
}

t_process		*del_process(t_core *core, t_process *lst)
{
	t_process	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst->next;
	if (!lst->n_live)
	{
		ft_printf("after %u lives, ", lst->live);//
		ft_printf("player n. %u does not respond anymore.{red}", lst->reg[1]);//
		ft_printf(" FUCK THIS SHIT!!!! He must die now{eoc}\n", *lst->reg);//
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

void			insert_process(t_core *core, t_process **lst, t_process *new)
{
	t_process	*tmp;

	tmp = *lst;
	if (!new)
		return ;
	core->n_process++;
	if (!*lst && (*lst = new))
		return ;
	if (((new->ins.nb_cycles < (*lst)->ins.nb_cycles)
				|| (new->ins.nb_cycles == (*lst)->ins.nb_cycles
					&& new->reg[1] > (*lst)->reg[1]))
			&& (new->next = *lst))
		return ((void)(*lst = new));
	while (tmp->next)
	{
		if (new->ins.nb_cycles < tmp->next->ins.nb_cycles)
			break ;
		if (new->ins.nb_cycles == tmp->next->ins.nb_cycles)
			if (new->reg[1] > tmp->next->reg[1])
				break ;
		tmp = tmp->next;
	}
	tmp->next ? new->next = tmp->next->next : 0;
	tmp->next = new;
}

t_process		*init_process(t_core *core, int i)
{
	t_process	*lst;
	t_process	*new;

	lst = NULL;
	while (++i < (int)core->player)
	{
		if (!(new = new_process()))
			return (clean_process(lst));
		*new->reg = core->p[i].oc;
		new->reg[1] = core->p[i].id;
		read_instruct(core, new) ? new = del_process(NULL, new) : 0;
		new ? insert_process(core, &lst, new) : 0;
	}
	return (lst);
}
