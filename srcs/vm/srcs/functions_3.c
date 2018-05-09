/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/09 16:43:55 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
	if (_abs(*oct, SND))
		return ;
}

void		_fork(const unsigned char *oct, t_process *p)
{
	(void)oct;
	add_data(&p->ins, &g_op_tab[11]);
}

void		_lld(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _dir(*oct, EITH)))
		if (!(p->ins.param[0] = _ind(*oct, EITH)))
			return ;
	if (!(p->ins.param[1] = _reg(*oct, SITH)))
		return ;
	if (_abs(*oct, FOTH) || _abs(*oct, SND))
		return ;
}

void		_lldi(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _reg(*oct, EITH)))
		if (!(p->ins.param[0] = _ind(*oct, EITH)))
			if (!(p->ins.param[0] = _dir(*oct, EITH)))
				return ;
	if (!(p->ins.param[1] = _reg(*oct, SITH)))
		if (!(p->ins.param[1] = _dir(*oct, SITH)))
			return ;
	if (!(p->ins.param[2] = _reg(*oct, FOTH)))
		return ;
	if (_abs(*oct, SND))
		return ;
}

void		_lfork(const unsigned char *oct, t_process *p)
{
	(void)oct;
	add_data(&p->ins, &g_op_tab[14]);
}
