/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/06 17:19:27 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void		_live(const unsigned char *oct, t_process *p)
{
	ft_printf("test _live\n");//
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	(void)p;
//	return (instruct);
}

void		_ld(const unsigned char *oct, t_process *p)
{
	ft_printf("test _ld\n");//
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	(void)p;
//	return (instruct);
}

void		_st(const unsigned char *oct, t_process *p)
{
	ft_printf("test _st\n");//
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	(void)p;
//	return (instruct);
}

void		_add(const unsigned char *oct, t_process *p)
{
	ft_printf("test _add\n");//
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	(void)p;
//	return (instruct);
}

void		_sub(const unsigned char *oct, t_process *p)
{
	ft_printf("test _sub\n");//
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	(void)p;
//	return (instruct);
}
