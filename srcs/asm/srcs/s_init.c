/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:23:51 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/05/14 17:49:19 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_label		*init_label(void)
{
	t_label	*new;

	if (!(new = malloc(sizeof(t_label))))
		handle_err(42, QUIT);
	new->name = NULL;
	new->next = NULL;
	return (new);
}

t_cmd		*init_cmd(void)
{
	t_cmd	*new;

	if (!(new = malloc(sizeof(t_cmd))))
		handle_err(42, QUIT);
	ft_bzero(new, sizeof(t_cmd));
	new->label = init_label();
	return (new);
}

t_header	*init_header(void)
{
	t_header *new;

	if (!(new = malloc(sizeof(t_header))))
		handle_err(42, QUIT);
	ft_bzero(new, sizeof(t_header));
	new->magic = swap_bigendian(COREWAR_EXEC_MAGIC);
	return (new);
}

void		init_data(t_data *new)
{
	ft_bzero(new, sizeof(t_data));
	new->cmd = init_cmd();
	new->header = init_header();
}
