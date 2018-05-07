/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/07 21:30:21 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		_live(const unsigned char *oct, t_process *p)
{
	(void)oct;
	add_data(&p->ins, &g_op_tab[0]);
}

void		_ld(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _dir(*oct, EITH)))
		if (!(p->ins.param[0] = _ind(*oct, EITH)))
			return ;
	if (!(p->ins.param[1] = _reg(*oct, SITH)))
		return ;
	if (_abs(*oct, FOTH) || _abs(*oct, SND))
		return ;
	add_data(&p->ins, &g_op_tab[1]);
}

void		_st(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _reg(*oct, EITH)))
		return ;
	if (!(p->ins.param[1] = _ind(*oct, SITH)))
		if (!(p->ins.param[1] = _reg(*oct, SITH)))
			return ;
	if (_abs(*oct, FOTH) || _abs(*oct, SND))
		return ;
	add_data(&p->ins, &g_op_tab[2]);
}

void		_add(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _reg(*oct, EITH)))
		return ;
	if (!(p->ins.param[1] = _reg(*oct, SITH)))
		return ;
	if (!(p->ins.param[2] = _reg(*oct, FOTH)))
		return ;
	if (_abs(*oct, SND))
		return ;
	add_data(&p->ins, &g_op_tab[3]);
}

void		_sub(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _reg(*oct, EITH)))
		return ;
	if (!(p->ins.param[1] = _reg(*oct, SITH)))
		return ;
	if (!(p->ins.param[2] = _reg(*oct, FOTH)))
		return ;
	if (_abs(*oct, SND))
		return ;
	add_data(&p->ins, &g_op_tab[4]);
}
