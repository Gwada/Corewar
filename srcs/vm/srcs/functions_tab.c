/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 20:52:36 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/06 21:02:51 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

void	(*f[INST_NUMBERS + 1])(const unsigned char *c, t_process *process) =
{
	_live, _ld, _st, _add, _sub, _and, _or, _xor, _zjmp, _ldi, _sti, _fork,
	_lld, _lldi, _lfork, _aff
};

