/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/07 15:14:42 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void		_and(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _reg(*oct, EITH)))
		if (!(p->ins.param[0] = _dir(*oct, EITH)))
			if (!(p->ins.param[0] = _ind(*oct, EITH)))
				return ;
	if (!(p->ins.param[1] = _reg(*oct, SITH)))
		if (!(p->ins.param[1] = _ind(*oct, SITH)))
			if (!(p->ins.param[1] = _dir(*oct, SITH)))
				return ;
	if (!(p->ins.param[2] = _reg(*oct, FOTH)))
		return ;
	if (_abs(*oct, SND))
		return ;
	add_data(&p->ins, &g_op_tab[5]);
}

void		_or(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _reg(*oct, EITH)))
		if (!(p->ins.param[0] = _dir(*oct, EITH)))
			if (!(p->ins.param[0] = _ind(*oct, EITH)))
				return ;
	if (!(p->ins.param[1] = _reg(*oct, SITH)))
		if (!(p->ins.param[1] = _ind(*oct, SITH)))
			if (!(p->ins.param[1] = _dir(*oct, SITH)))
				return ;
	if (!(p->ins.param[2] = _reg(*oct, FOTH)))
		return ;
	if (_abs(*oct, SND))
		return ;
	add_data(&p->ins, &g_op_tab[6]);
}

void		_xor(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _reg(*oct, EITH)))
		if (!(p->ins.param[0] = _dir(*oct, EITH)))
			if (!(p->ins.param[0] = _ind(*oct, EITH)))
				return ;
	if (!(p->ins.param[1] = _reg(*oct, SITH)))
		if (!(p->ins.param[1] = _ind(*oct, SITH)))
			if (!(p->ins.param[1] = _dir(*oct, SITH)))
				return ;
	if (!(p->ins.param[2] = _reg(*oct, FOTH)))
		return ;
	if (_abs(*oct, SND))
		return ;
	add_data(&p->ins, &g_op_tab[7]);
}

void		_zjmp(const unsigned char *oct, t_process *p)
{
	(void)oct;
	add_data(&p->ins, &g_op_tab[8]);
}

void		_ldi(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _reg(*oct, EITH)))
		if (!(p->ins.param[0] = _dir(*oct, EITH)))
			if (!(p->ins.param[0] = _ind(*oct, EITH)))
				return ;
	if (!(p->ins.param[1] = _dir(*oct, SITH)))
		if (!(p->ins.param[1] = _reg(*oct, SITH)))
			return ;
	if (!(p->ins.param[2] = _reg(*oct, FOTH)))
		return ;
	if (_abs(*oct, SND))
		return ;
	add_data(&p->ins, &g_op_tab[9]);
}
