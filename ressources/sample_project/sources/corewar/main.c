/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <brigoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 18:02:27 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/25 16:35:47 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int argc, char **argv)
{
	if (!(g_data = (t_data *)ft_memalloc(sizeof(t_data))))
		print_error(1);
	parse_args(argc, argv);
	init_vm();
	if (g_data->ncurses)
		run_ncurses();
	else
		run_vm();
}
