/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/06 21:02:50 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void		_sti(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _reg(*oct, EITH)))
		return ;
	if (!(p->ins.param[1] = _reg(*oct, SITH)))
		if (!(p->ins.param[1] = _ind(*oct, SITH)))
			if (!(p->ins.param[1] = _dir(*oct, SITH)))
				return ;
	if (!(p->ins.param[2] = _reg(*oct, FOTH)))
		if (!(p->ins.param[2] = _dir(*oct, FOTH)))
			return ;
	if (_abs(*oct))
		return ;
	add_data(&p->ins, &g_op_tab[10]);
}

void		_fork(const unsigned char *oct, t_process *p)
{
	ft_printf("test _fork\n");//
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	(void)p;
	add_data(&p->ins, &g_op_tab[11]);
}

void		_lld(const unsigned char *oct, t_process *p)
{
	ft_printf("test _lld\n");//
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	(void)p;
	add_data(&p->ins, &g_op_tab[12]);
}

void		_lldi(const unsigned char *oct, t_process *p)
{
	ft_printf("test _lldi\n");//
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	add_data(&p->ins, &g_op_tab[13]);
}

void		_lfork(const unsigned char *oct, t_process *p)
{
	ft_printf("test _lfork\n");//
	t_op	instruct;

	ft_bzero(&instruct, sizeof(instruct));
	(void)oct;
	add_data(&p->ins, &g_op_tab[14]);
}
