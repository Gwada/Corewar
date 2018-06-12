/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 19:59:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/18 13:38:51 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

unsigned int	_aff(const unsigned char *oct, t_process *p)
{
	if (!(*p->ins.param = _reg(*oct, EITH)))
		return (0);
	if (_abs(*oct, SITH) || _abs(*oct, FOTH) || _abs(*oct, SND))
		return (0);
	return (1);
}

unsigned int	opc_c(unsigned char opc)
{
	return (opc < 16);
}

unsigned short	id(unsigned id)
{
	return (id % MEM_SIZE);
}
