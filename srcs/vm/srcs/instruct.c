/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:44:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/05 19:25:41 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void	read_instruct(t_core *core, t_process *process)
{
	ft_printf("{bold}{blue}IN\tREAD_INSTRUCT{eoc}\n");//
	(void)core;
	(void)process;
	ft_printf("{bold}{blue}END\tREAD_INSTRUCT{eoc}\n\n");//
}
