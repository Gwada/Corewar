/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/14 13:40:04 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	_aff(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _reg(*oct, EITH)))
		return (0);
	if (_abs(*oct, SITH) || _abs(*oct, FOTH) || _abs(*oct, SND))
		return (0);
	return (1);
}

unsigned int	opc_c(unsigned char opc)
{
	return (opc < INST_NB);
}

unsigned short	id(unsigned id)
{
	return (id % MEM_SIZE);
}
