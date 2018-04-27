/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 21:24:15 by brigoux           #+#    #+#             */
/*   Updated: 2016/06/18 22:18:54 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char **argv)
{
	t_data		*data;

	data = parse_args(argc, argv);
	read_source(data);
	if (data->flag->a)
		print_annotated(data);
	else
	{
		write_file(data);
		if (data->flag->n)
			ft_putstr(data->dst);
	}
}
