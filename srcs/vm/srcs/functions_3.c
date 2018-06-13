/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/13 15:23:38 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	sti_(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = reg_(*oct, EITH)))
		return (0);
	if (!(p->ins.param[1] = reg_(*oct, SITH)))
		if (!(p->ins.param[1] = ind_(*oct, SITH)))
			if (!(p->ins.param[1] = dir_(*oct, SITH)))
				return (0);
	if (!(p->ins.param[2] = reg_(*oct, FOTH)))
		if (!(p->ins.param[2] = dir_(*oct, FOTH)))
			return (0);
	if (abs_(*oct, SND))
		return (0);
	return (1);
}

unsigned int	fork_(const unsigned char *oct, t_process *p)
{
	(void)oct;
	(void)p;
	return (1);
}

unsigned int	lld_(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = dir_(*oct, EITH)))
		if (!(p->ins.param[0] = ind_(*oct, EITH)))
			return (0);
	if (!(p->ins.param[1] = reg_(*oct, SITH)))
		return (0);
	if (abs_(*oct, FOTH) || abs_(*oct, SND))
		return (0);
	return (1);
}

unsigned int	lldi_(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = reg_(*oct, EITH)))
		if (!(p->ins.param[0] = ind_(*oct, EITH)))
			if (!(p->ins.param[0] = dir_(*oct, EITH)))
				return (0);
	if (!(p->ins.param[1] = reg_(*oct, SITH)))
		if (!(p->ins.param[1] = dir_(*oct, SITH)))
			return (0);
	if (!(p->ins.param[2] = reg_(*oct, FOTH)))
		return (0);
	if (abs_(*oct, SND))
		return (0);
	return (1);
}

unsigned int	lfork_(const unsigned char *oct, t_process *p)
{
	(void)oct;
	(void)p;
	return (1);
}
