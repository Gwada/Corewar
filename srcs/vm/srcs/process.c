/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 13:56:08 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/05 18:44:23 by dlavaury         ###   ########.fr       */
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

t_process		*del_process(t_process *lst)
{
	t_process	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst->next ? lst->next : NULL;
	free(lst);
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

/*void			insert_process(t_process *lst, t_process *new, t_core *core)
{
	t_process	*tmp;

	tmp = lst;
}*/
