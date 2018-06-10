/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 10:50:48 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/05 11:16:07 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

static int				get_id(unsigned char *opt, t_core *core)
{
	unsigned short		id;

	id = 0;
	if (!*opt)
		return (0);
	if (ft_str_is_numeric((char*)opt))
	{
		while (*opt)
			if ((id = id * 10 + *opt++ - '0') > MAX_PLAYERS)
				break ;
		if (id < 1 || id > MAX_PLAYERS)
			return (ft_printf("Player Id: (1-%u)\n", MAX_PLAYERS));
		if (core->id[id])
			return (ft_printf("Choose an other player id: %hu\n", id));
		core->bd |= GET_OPT;
		core->bd &= ~GET_ID;
		core->id[id] = 1;
		core->p[core->player].id = (unsigned char)id;
		return (0);
	}
	return (ft_printf("Invalid id player: %s\n", opt));
}

static int				get_dump(unsigned char *opt, t_core *core)
{
	unsigned long long	dump;

	dump = 0;
	if (!*opt)
		return (0);
	if (ft_str_is_numeric((char*)opt))
	{
		while (*opt)
			if ((dump = dump * 10 + *opt++ - '0') > IMAX)
				break ;
		if (dump > 0 && dump <= IMAX)
		{
			core->bd |= DUMP;
			core->bd &= ~GET_DUMP;
			core->dump = (unsigned int)dump;
			return (0);
		}
	}
	core->bd = ERROR;
	display_usage(core->first_arg);
	return (1);
}

int						get_options(unsigned char *opt, t_core *core)
{
	if (!*opt)
		return (0);
	if (core->bd & GET_ID)
		return (get_id(opt, core));
	if (core->bd & GET_DUMP)
		return (get_dump(opt, core));
	++opt;
	if (!core->player)
	{
		if (!ft_strcmp("v", (const char*)opt) && (core->bd |= VISUAL))
			return (0);
		if (!ft_strcmp("dump", (const char*)opt)
		&& !(core->bd & DUMP) && (core->bd |= GET_DUMP))
			return (0);
		if (!ft_strcmp("Debug", (const char *)opt) && (core->bd |= DEBUG))
			return (0);
	}
	if (!ft_strcmp("p", (const char*)opt)
	&& !(core->bd & GET_OPT) && (core->bd |= GET_ID))
		return (0);
	display_usage(core->first_arg);
	return (1);
}
