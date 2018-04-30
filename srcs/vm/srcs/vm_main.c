/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 18:19:30 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/30 13:47:14 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"
#include "../../libft/includes/ft_printf.h"

int		main(int argc, char **argv)
{
	if (argc > 1)
		ft_printf("test\n");
	else
		ft_printf("Usage: ...\n");
	(void)argv;
	return (0);
}
