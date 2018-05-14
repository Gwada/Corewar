/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 18:16:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/14 14:21:48 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/asm.h"

/*void		parse_args(int ac, char *av, t_data *data)
{
	int		i;

	i = 0;
	while (++i < ac && *av[i] == '-' && ft_strlen(av[i]) > 1)
		(av[i])++ && *av[i] && *av[i] == 'h' && (av[i])++ && !(*av[i]) ?
			handle_err(1, -1) : handle_err(2, -1);
	ft_strcmp(av[i] + ft_strlen(av[i]) - 2, ".s") ? handle_err(4, -1) : 0;
	data->s = ft_strdup(av[i]);
	data->cor = ft_strnjoin(av[i], "cor", ft_strlen(av[i]) - 1);
}*/

void		parse_args(char *av, t_data *data)
{
	int		i;

	i = 0;
	while (*av == '-' && ft_strlen(av) > 1)
		av++ && *av && *av == 'h' && av++ && !*av ?
			handle_err(1, -1) : handle_err(2, -1);
	ft_strcmp(av + ft_strlen(av) - 2, ".s") ? handle_err(4, -1) : 0;
	data->s = ft_strdup(av);
	ft_putendl("here");
	data->cor = ft_strnjoin(av, "cor", ft_strlen(av) - 1);
}

int			main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
//	data = NULL;
	ac == 1 ? handle_err(3, QUIT) : 0;
	while (++i < ac)
	{
		init_data(&data);
		parse_args(av[i], &data);
		read_file(&data);
		free_data(&data);
	//	ft_putendl("salut");
	}
	return (0);
}
