/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/15 22:00:09 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	_sti(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _reg(*oct, EITH)))
		return (0);
	if (!(p->ins.param[1] = _reg(*oct, SITH)))
		if (!(p->ins.param[1] = _ind(*oct, SITH)))
			if (!(p->ins.param[1] = _dir(*oct, SITH)))
				return (0);
	if (!(p->ins.param[2] = _reg(*oct, FOTH)))
		if (!(p->ins.param[2] = _dir(*oct, FOTH)))
			return (0);
	if (_abs(*oct, SND))
		return (0);
	return (1);
}

unsigned int	_fork(const unsigned char *oct, t_process *p)
{
	(void)oct;
	(void)p;
	return (1);
}

unsigned int	_lld(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _dir(*oct, EITH)))
		if (!(p->ins.param[0] = _ind(*oct, EITH)))
			return (0);
	if (!(p->ins.param[1] = _reg(*oct, SITH)))
		return (0);
	if (_abs(*oct, FOTH) || _abs(*oct, SND))
		return (0);
	return (1);
}

unsigned int	_lldi(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _reg(*oct, EITH)))
		if (!(p->ins.param[0] = _ind(*oct, EITH)))
			if (!(p->ins.param[0] = _dir(*oct, EITH)))
				return (0);
	if (!(p->ins.param[1] = _reg(*oct, SITH)))
		if (!(p->ins.param[1] = _dir(*oct, SITH)))
			return (0);
	if (!(p->ins.param[2] = _reg(*oct, FOTH)))
		return (0);
	if (_abs(*oct, SND))
		return (0);
	return (1);
}

unsigned int	_lfork(const unsigned char *oct, t_process *p)
{
	(void)oct;
	(void)p;
	return (1);
}
