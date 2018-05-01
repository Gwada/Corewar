/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 18:19:30 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/01 13:43:59 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"
#include "../../libft/includes/ft_printf.h"

static	void		get_magic_num(unsigned char **oct, t_core *c)
{
	int				i;
	unsigned int	n;

	i = -1;
	n = 0;
	while (++i < 4)
	{
		i ? n <<= 8 : 0;
		n |= *(*oct)++;
	}
	c->bd |= n == COREWAR_EXEC_MAGIC ? VALID_C_E_M : INVALID_C_E_M;
	if (n == COREWAR_EXEC_MAGIC)
		ft_printf("{green}%s COREWAR_EXEC_MAGIC IS CORRECT{eoc}\n\n", *oct);
	else
		ft_printf("{red}%s COREWAR_EXEC_MAGIC INCORRECT{eoc}\n\n", *oct);
}

static	int			get_arg(char *param, t_core *c)
{
	int				fd;
	int				ret;
	unsigned char	*oct;
	unsigned char	buff[FILE_MAX_SIZE];

	oct = buff;
	if (*param != '-')
	{
		if ((fd = open(param, O_RDONLY)) == -1)
			return (ft_printf("error open\n"));
		if ((ret = read(fd, buff, FILE_MAX_SIZE + 1)) == -1)
		{
			close(fd);
			return (ft_printf("error read\n"));
		}
		ft_printf("FILE_MAX_SIZE = %d\tret = %d\n", FILE_MAX_SIZE, ret);
		get_magic_num(&oct, c);
		ft_printf("|%hhu| |%hhx|\n", *oct, *oct);
		close(fd);
	}
	else
	{
		// get_options(param, c,); recuperation des options;
		ft_printf("{blue}IS OPTION{eoc}\n");
	}
	(void)c;
	(void)buff;
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	t_core	core;

	i = 0;
	if (argc > 1)
	{
		ft_bzero(&core, sizeof(core));
		while (++i < argc && argv[i])
			if (get_arg(argv[i], &core)) // erreur lors du parsing
				ft_printf("error\n");
	}
	else //fonction de display error
		ft_printf("Usage: ./corewar <champion1.cor> <...>\n");
	return (0);
}
