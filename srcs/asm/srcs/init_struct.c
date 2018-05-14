/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 22:13:12 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/05/14 13:16:03 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/asm.h"

t_label		*init_label(void)
{
	t_label	*new;

	if (!(new = malloc(sizeof(t_label))))
		handle_err(42, -1);
	new->name = NULL;
	new->next = NULL;
	return (new);
}

t_cmd		*init_cmd(void)
{
	t_cmd	*new;

	if (!(new = malloc(sizeof(t_cmd))))
		handle_err(42, -1);
	new->index = 0;
	new->opcode = 0;
	ft_bzero(new->p_name, sizeof(char *) * 3);
	new->ocp = 0;
	ft_bzero(new->p_val, sizeof(int) * 3);
	new->size = 0;
	new->label = init_label();
	new->next = NULL;
	return (new);
}

t_header	*init_header(void)
{
	t_header *new;

	if (!(new = malloc(sizeof(t_header))))
		handle_err(42, -1);
	new->magic = swap_bigendian(COREWAR_EXEC_MAGIC);
	ft_bzero(new->prog_name, PROG_NAME_LENGTH + 1);
	new->prog_size = 0;
	ft_bzero(new->comment, COMMENT_LENGTH + 1);
	return (new);
}

t_data		*init_data(void)
{
	t_data	*new;

	if (!(new = malloc(sizeof(t_data))))
		handle_err(42, QUIT);
	new->s = NULL;
	new->cor = NULL;
	new->gnl = NULL;
	new->name = 0;
	new->comment = 0;
	new->line = 0;
	new->eof = 0;
	new->cmd = init_cmd();
	new->header = init_header();
	return (new);
}
