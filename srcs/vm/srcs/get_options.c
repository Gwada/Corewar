/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 10:50:48 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/04 17:49:00 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

static size_t		get_id(unsigned char *oct, t_core *core)
{
	unsigned short	id;

	id = 0;
	while (ft_isdigit(*oct))
		if ((id = id * 10 + *oct++ - '0') > MAX_PLAYERS)
			break ;
	if (id < 1 || id > MAX_PLAYERS)
		return (ft_printf("Player Id: (1-%u)\n", MAX_PLAYERS));
	if (core->id[id])
		return (ft_printf("Choose an other player id: {red}%hu{eoc}\n", id));
	core->bd |= GET_OPT;
	core->id[id] = 1;
	core->p[core->player].id = (unsigned char)id;
	return (0);
}

static void			get_prog_opt(unsigned char *opt, t_core *core)
{
	int				i;
	unsigned long	dump;

	i = -1;
	dump = 0;
	if ((!*opt || !ft_str_is_numeric((char*)opt)) && (core->bd = ERROR))
	{
		display_usage(core->first_arg);
		return ;
	}
	while (ft_isdigit(opt[++i]))
		if ((dump = dump * 10 + opt[i] - '0') > IMAX)
		{
			display_usage(core->first_arg);
			core->bd = ERROR;
			return ;
		}
	core->bd |= DUMP;
	return ;
}

int					get_options(unsigned char *opt, t_core *core, int n)
{
	if (!*opt)
		return (0);
	if (n == 1 && *opt == 'd')
		get_prog_opt(++opt, core);
	else if (ft_isdigit(*opt))
	{
		if (get_id(opt, core))
			return (ft_printf("Invalid player id: %s\n", opt - 1));
		while (ft_isdigit(*opt))
			++opt;
	}
	else
	{
		display_usage(core->first_arg);
		return (1);
	}
	return (0);
}
