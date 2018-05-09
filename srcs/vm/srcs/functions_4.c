/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/09 18:36:40 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				_aff(const unsigned char *oct, t_process *p)
{
	if (!(p->ins.param[0] = _reg(*oct, EITH)))
		return ;
	if (_abs(*oct, SITH) || _abs(*oct, FOTH) || _abs(*oct, SND))
		return ;
}

unsigned int	opc_c(unsigned char opc)
{
	return (opc && opc <= INST_NB);
}

unsigned int		id(unsigned id)
{
	return (id % MEM_SIZE);
}
