/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/05 20:50:11 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

t_op		_sti(const unsigned char *oct)
{
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	return (instruct);
}

t_op		_fork(const unsigned char *oct)
{
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	return (instruct);
}

t_op		_lld(const unsigned char *oct)
{
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	return (instruct);
}

t_op		_lldi(const unsigned char *oct)
{
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	return (instruct);
}

t_op		_lfork(const unsigned char *oct)
{
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	return (instruct);
}
