/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:42:35 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/07 15:50:54 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

static t_process	*init_process(t_core *core)
{
	t_process		*lst;
	t_process		*new;
	unsigned int	i;

	i = 0;
	lst = NULL;
	while (i < core->player)
	{
		if (!(new = new_process()))
			return (clean_process(lst));
		ft_bzero(new, sizeof(t_process));
		new->carry = 0;
		*new->reg = core->p[i].oc;
		new->reg[1] = core->p[i].id;
		if (read_instruct(core, new))
		{
			free(new);
			new = NULL;
		}
		new ? insert_process(&lst, new) : 0;
		++i;
	}
	return (lst);
}

void				corewar(t_core *c)
{
	ft_printf("{bold}{red}IN\tCOREWAR{eoc}\n");//


	if (!(c->ps = init_process(c)))
		return (display_error(c, 0));

	ft_printf("id player = %u\n", c->ps->reg[1]);
	ft_printf("instruct name = %s\n", c->ps->ins.name);
	ft_print_mem(c->ram, MEM_SIZE, 64, 0);


	clean_process(c->ps);
	ft_printf("{bold}{red}END\tCOREWAR{eoc}\n");//
}
