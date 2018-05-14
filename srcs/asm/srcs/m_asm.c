/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_asm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:srcs/asm/srcs/asm_main.c
/*   Created: 2018/04/29 18:16:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/14 14:22:52 by dlavaury         ###   ########.fr       */
=======
/*   Created: 2018/05/14 17:23:25 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/05/14 17:48:40 by salemdjeg        ###   ########.fr       */
>>>>>>> 66350cd2aa5e6605bd77b745a6151bb3a28e4f1a:srcs/asm/srcs/m_asm.c
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		parse_args(char *av, t_data *data)
{
	int		i;

	i = 0;
	while (*av == '-' && ft_strlen(av) > 1)
		av++ && *av && *av == 'h' && av++ && !*av ?
			handle_err(1, QUIT) : handle_err(2, QUIT);
	ft_strcmp(av + ft_strlen(av) - 2, ".s") ? handle_err(4, QUIT) : 0;
	data->s = ft_strdup(av);
	data->cor = ft_strnjoin(av, "cor", ft_strlen(av) - 1);
}

int			main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
	ac == 1 ? handle_err(3, QUIT) : 0;
	while (++i < ac && i < 5)
	{
		init_data(&data);
		parse_args(av[i], &data);
		read_file(&data);
		free_data(&data);
	}
	return (0);
}
