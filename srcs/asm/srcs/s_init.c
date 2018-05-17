/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:23:51 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/05/17 14:40:49 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_label		*init_label(t_data *data)
{
	t_label	*new;

	if (!(new = malloc(sizeof(t_label))))
		handle_err(42, QUIT, data);
	new->name = NULL;
	new->next = NULL;
	return (new);
}

t_cmd		*init_cmd(t_data *data)
{
	t_cmd	*new;

	if (!(new = malloc(sizeof(t_cmd))))
		handle_err(42, QUIT, data);
	ft_bzero(new, sizeof(t_cmd));
	new->label = init_label(data);
	return (new);
}

t_header	*init_header(t_data *data)
{
	t_header *new;

	if (!(new = malloc(sizeof(t_header))))
		handle_err(42, QUIT, data);
	ft_bzero(new, sizeof(t_header));
	new->magic = swap_bigendian(COREWAR_EXEC_MAGIC);
	return (new);
}

void		init_data(t_data *new)
{
	ft_bzero(new, sizeof(t_data));
	new->cmd = init_cmd(new);
	new->header = init_header(new);
}
