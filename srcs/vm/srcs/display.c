/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:05:10 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/04 20:26:42 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void		display_usage(char *name)
{
	ft_printf("{bold}Usage: %s [-dump[nbr_cycles] -v]", name);
	ft_printf(" [[-p[number]] champion1.cor]");
	ft_printf(" [[-p[number]] champion2.cor] ...{eoc}\n");
	ft_printf("{underline}-dump[nbr_cycles]{runderline}:");
	ft_printf(" Dumps memory after N cycles then exits.\n");
	ft_printf("Value is initialized to null by default.\n");
	ft_printf("\tnbr_cycles: must be strictly positive and ");
	ft_printf("can not be bigger than %d.\n", IMAX);
	ft_printf("{underline}-v{eoc}:");
	ft_printf(" Show RAM status in a graphical interface.\n");
	ft_printf("{underline}-p[number]{eoc}: Assign id N to the next champion.");
	ft_printf(" If this value is not initialized,\n");
	ft_printf("the machine chooses the first possible value.\n");
	ft_printf("\tnumber: must be strictly positive and ");
	ft_printf("can not be bigger than %u.\n", MAX_PLAYERS);
}
