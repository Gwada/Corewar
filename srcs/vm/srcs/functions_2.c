/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/06 17:18:46 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void		_and(const unsigned char *oct, t_process *p)
{
	ft_printf("test _and\n");//
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	(void)p;
//	return (instruct);
}

void		_or(const unsigned char *oct, t_process *p)
{
	ft_printf("test _or\n");//
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	(void)p;
//	return (instruct);
}

void		_xor(const unsigned char *oct, t_process *p)
{
	ft_printf("test _xor\n");//
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	(void)p;
//	return (instruct);
}

void		_zjmp(const unsigned char *oct, t_process *p)
{
	ft_printf("test _zjmp\n");//
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	(void)p;
//	return (instruct);
}

void		_ldi(const unsigned char *oct, t_process *p)
{
	ft_printf("test _ldi\n");//
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	(void)p;
//	return (instruct);
}
