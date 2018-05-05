/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/05 20:27:46 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

t_op		_and(const unsigned char *oct)
{
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	return (instruct);
}

t_op		_or(const unsigned char *oct)
{
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	return (instruct);
}

t_op		_xor(const unsigned char *oct)
{
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	return (instruct);
}

t_op		_zjmp(const unsigned char *oct)
{
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	return (instruct);
}

t_op		_ldi(const unsigned char *oct)
{
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	return (instruct);
}
