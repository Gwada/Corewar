/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/11 12:26:02 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	_and(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _reg(*oct, EITH)))
		if (!(p->ins.param[0] = _dir(*oct, EITH)))
			if (!(p->ins.param[0] = _ind(*oct, EITH)))
				return (0);
	if (!(p->ins.param[1] = _reg(*oct, SITH)))
		if (!(p->ins.param[1] = _ind(*oct, SITH)))
			if (!(p->ins.param[1] = _dir(*oct, SITH)))
				return (0);
	if (!(p->ins.param[2] = _reg(*oct, FOTH)))
		return (0);
	if (_abs(*oct, SND))
		return (0);
	return (1);
}

unsigned int	_or(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _reg(*oct, EITH)))
		if (!(p->ins.param[0] = _dir(*oct, EITH)))
			if (!(p->ins.param[0] = _ind(*oct, EITH)))
				return (0);
	if (!(p->ins.param[1] = _reg(*oct, SITH)))
		if (!(p->ins.param[1] = _ind(*oct, SITH)))
			if (!(p->ins.param[1] = _dir(*oct, SITH)))
				return (0);
	if (!(p->ins.param[2] = _reg(*oct, FOTH)))
		return (0);
	if (_abs(*oct, SND))
		return (0);
	return (1);
}

unsigned int	_xor(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _reg(*oct, EITH)))
		if (!(p->ins.param[0] = _dir(*oct, EITH)))
			if (!(p->ins.param[0] = _ind(*oct, EITH)))
				return (0);
	if (!(p->ins.param[1] = _reg(*oct, SITH)))
		if (!(p->ins.param[1] = _ind(*oct, SITH)))
			if (!(p->ins.param[1] = _dir(*oct, SITH)))
				return (0);
	if (!(p->ins.param[2] = _reg(*oct, FOTH)))
		return (0);
	if (_abs(*oct, SND))
		return (0);
	return (1);
}

unsigned int	_zjmp(const unsigned char *oct, t_process *p)
{
	(void)oct;
	(void)p;
	return (1);
}

unsigned int	_ldi(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _reg(*oct, EITH)))
		if (!(p->ins.param[0] = _dir(*oct, EITH)))
			if (!(p->ins.param[0] = _ind(*oct, EITH)))
				return (0);
	if (!(p->ins.param[1] = _dir(*oct, SITH)))
		if (!(p->ins.param[1] = _reg(*oct, SITH)))
			return (0);
	if (!(p->ins.param[2] = _reg(*oct, FOTH)))
		return (0);
	if (_abs(*oct, SND))
		return (0);
	return (1);
}
