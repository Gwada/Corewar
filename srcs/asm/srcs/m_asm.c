/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_asm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 18:16:20 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/17 16:48:05 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		parse_args(char *av, t_data *data)
{
	int		i;

	i = 0;
	while (*av == '-' && ft_strlen(av) > 1)
		av++ && *av && *av == 'h' && av++ && !*av ?
			handle_err(1, QUIT, data) : handle_err(2, QUIT, data);
	ft_strcmp(av + ft_strlen(av) - 2, ".s") ? handle_err(4, QUIT, data) : 0;
	data->s = ft_strdup(av);
	data->cor = ft_strnjoin(av, "cor", ft_strlen(av) - 1);
}

int			main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
	ac == 1 ? handle_err(3, QUIT, NULL) : 0;
	while (++i < ac)
	{
		init_data(&data);
		parse_args(av[i], &data);
		read_file(&data);
		free_data(&data);
	}
	return (0);
}
