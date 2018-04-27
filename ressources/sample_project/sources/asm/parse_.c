/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 21:44:47 by brigoux           #+#    #+#             */
/*   Updated: 2016/06/07 18:52:20 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_data		*parse_args(int argc, char **argv)
{
	t_data	*data;
	int		i;

	data = new_data();
	i = 0;
	while (++i < argc && *argv[i] == '-' && ft_strlen(argv[i]) > 1)
		data->flag = parse_flag(argv[i], data->flag);
	if (i == argc)
		print_error(2, -1);
	if (i + 1 != argc)
		print_error(3, -1);
	if (ft_strcmp(argv[argc - 1] + ft_strlen(argv[argc - 1]) - 2, ".s"))
		print_error(13, -1);
	data->src = ft_strdup(argv[argc - 1]);
	data->dst = ft_strcat(ft_strncpy(ft_strnew(ft_strlen(argv[argc - 1]) + 2),
				argv[argc - 1], ft_strlen(argv[argc - 1]) - 1), "cor");
	if (!data->src || !data->dst)
		print_error(1, -1);
	return (data);
}

t_flag		*parse_flag(char *str, t_flag *flag)
{
	int		i;

	i = 0;
	while (++i && str[i])
	{
		if (str[i] == 'h')
			print_help();
		else if (str[i] == 'n')
			flag->n += 1;
		else if (str[i] == 'a')
			flag->a += 1;
		else
			print_error(2, -1);
	}
	return (flag);
}
