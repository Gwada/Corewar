/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/05 20:26:02 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

t_op		_live(const unsigned char *oct)
{
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	return (instruct);
}

t_op		_ld(const unsigned char *oct)
{
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	return (instruct);
}

t_op		_st(const unsigned char *oct)
{
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	return (instruct);
}

t_op		_add(const unsigned char *oct)
{
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	return (instruct);
}

t_op		_sub(const unsigned char *oct)
{
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	return (instruct);
}
