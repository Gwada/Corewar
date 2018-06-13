/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:05:10 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/13 15:42:38 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void		display_usage(char *name)
{
	ft_printf("{bold}Usage: %s [-dump [nbr_cycles] -v]", name);
	ft_printf(" [[-n [number]] champion1.cor]");
	ft_printf(" [[-n [number]] champion2.cor] ...{eoc}\n");
	ft_printf("{underline}-dump [nbr_cycles]{runderline}:");
	ft_printf(" Dumps memory after N cycles then exits.\n");
	ft_printf("Value is initialized to null by default.\n");
	ft_printf("\tnbr_cycles: must be strictly positive and ");
	ft_printf("can not be bigger than %d.\n", IMAX);
	ft_printf("{underline}-v{eoc}:");
	ft_printf(" Show RAM status in a graphical interface.\n");
	ft_printf("{underline}-p [number]{eoc}: Assign id N to the next champion.");
	ft_printf(" If this value is not initialized,\n");
	ft_printf("the machine chooses the first possible value.\n");
	ft_printf("\tnumber: must be strictly positive and ");
	ft_printf("can not be bigger than %u.\n", MAX_PLAYERS);
}

int			display_error(t_core *core, int code, char *s)
{
	core->bd = ERROR;
	!code ? ft_printf("{red}MALLOC ERROR{eoc}\n") : 0;
	if (code == 1)
		ft_printf("'%s' is invalid file name or unsupported extension\n", s);
	code == 2 ? ft_printf("'%s' can not be opened\n", s) : 0;
	code == 3 ? ft_printf("'%s' can not be read\n", s) : 0;
	code == 4 ? ft_printf("{red}%d{eoc} maximum supported players\n", code) : 0;
	code == 5 ? ft_printf("missing one champion\n") : 0;
	code == 6 ? ft_printf("invalid magic number\n") : 0;
	code == 7 ? ft_printf("missing id value 1-4\n") : 0;
	code == 8 ? ft_printf("missing dump value\n") : 0;
	return (1);
}
