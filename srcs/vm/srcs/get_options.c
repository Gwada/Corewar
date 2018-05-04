/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 10:50:48 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/04 20:31:22 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

static size_t			get_id(unsigned char *oct, t_core *core)
{
	unsigned short		id;

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

static void				get_prog_opt(unsigned char *opt, t_core *core)
{
	unsigned long long	dump;

	dump = 0;
	if (!*opt)
		return ;
	if (*opt == 'v' && (core->bd |= VISUAL))
		return (get_prog_opt(++opt, core));
	if (!ft_strncmp((const char*)opt, "dump", 4) && !(core->bd & DUMP))
	{
		opt += 4;
		while (*opt && ft_isdigit(*opt))
			if ((dump = dump * 10 + *opt++ - '0') > IMAX)
				break ;
		if ((!dump || dump > IMAX) && (core->bd = ERROR))
			return (display_usage(core->first_arg));
		core->bd |= DUMP;
		core->dump = (unsigned int)dump;
		return (*opt ? get_prog_opt(opt, core) : (void)0);
	}
	core->bd = ERROR;
	display_usage(core->first_arg);
}

int						get_options(unsigned char *opt, t_core *core)
{
	if (!*opt)
		return (0);
	if (ft_strchr("dv", *opt) && !core->player)
		get_prog_opt(opt, core);
	else if (*opt == 'p' && ft_isdigit(*++opt))
	{
		if (get_id(opt, core))
			return (ft_printf("Invalid player id: %s\n", opt - 2));
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
