/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <brigoux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 18:17:29 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/23 14:03:21 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		parse_args(int argc, char **argv)
{
	int		i;

	i = 1;
	if (i < argc && ft_strequ(argv[i], "-h"))
		print_help();
	if (i < argc && (ft_strequ(argv[i], "-M") || ft_strequ(argv[i], "-N")))
	{
		g_data->mute = 1;
		if (i++ && argv[i - 1][1] == 'N')
			g_data->ncurses = 1;
	}
	g_data->dump = -1;
	if (i < argc && ft_strequ(argv[i], "-dump"))
	{
		if ((i += 2) - 1 < argc && ft_strisdigit(argv[i - 1]))
			g_data->dump = ft_atoi(argv[i - 1]);
		else
			print_error(3);
	}
	if (i == argc)
		print_error(2);
	parse_playerinfo(i, argc, argv);
}

void		parse_playerinfo(int i, int argc, char **argv)
{
	int		a;
	int		n[MAX_PLAYERS];
	int		p_num;

	ft_bzero(n, MAX_PLAYERS * sizeof(int));
	a = -1;
	p_num = 0;
	while (i < argc && ++a < MAX_ARGS_NUMBER)
	{
		if (ft_strequ(argv[i], "-n") && ++i)
		{
			if (!(i++ < argc && (ft_strisdigit(argv[i - 1]) || (*argv[i - 1] ==
								'-' && ft_strisdigit(argv[i - 1] + 1)))))
				print_error(4);
			g_data->player[a].number = ft_atoi(argv[i - 1]);
		}
		else
			n[a] = (++p_num);
		if (i++ >= argc)
			print_error(5);
		g_data->player[a].file_name = ft_strdup(argv[i - 1]);
	}
	if (a >= MAX_ARGS_NUMBER)
		print_error(6);
	check_numbers(n);
}
