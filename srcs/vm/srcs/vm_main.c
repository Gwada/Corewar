/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 18:19:30 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/06 11:53:48 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

static	void		get_magic_number(unsigned char **b, t_core *c, int i)
{
	while (++i < 4)
		c->p[c->player].magic = (c->p[c->player].magic << 8) | *(*b)++;
	c->p[c->player].name = *b;
	if (c->p[c->player].magic == COREWAR_EXEC_MAGIC)
	{
		c->p[c->player].bd |= VALID_MAG;
		if (ft_strlen((const char*)*b) <= PROG_NAME_LENGTH)
		{
			c->p[c->player].bd |= VALID_NAME_LEN;
			*b += PROG_NAME_LENGTH + 4;
			return ;
		}
		ft_printf("('{red}%d{eoc}' > ", ft_strlen((const char*)*b));
		ft_printf("%u) invalid name length '%s'\n", PROG_NAME_LENGTH, *b);
		return ;
	}
	ft_printf("'%s' magic number is invalid: ", *b);
	ft_printf("'{red}%x{eoc}' != ", c->p[c->player].magic);
	ft_printf("%x\n", COREWAR_EXEC_MAGIC);
}

static void			get_prog_size(unsigned char **b, t_core *c, int i)
{
	while (++i < 4)
		c->p[c->player].prog_size = (c->p[c->player].prog_size << 8) | *(*b)++;
	if (c->p[c->player].prog_size <= CHAMP_MAX_SIZE)
	{
		if (ft_strlen((const char *)*b) <= COMMENT_LENGTH)
		{
			c->p[c->player].bd |= VALID_CHAMP_LEN;
			c->p[c->player].comment = *b;
			*b += COMMENT_LENGTH + 4;
			c->p[c->player].prog = *b;
			c->bd &= ~GET_OPT;
			return ;
		}
		ft_printf("'%s' comment length is invalid ", c->p[c->player].name);
		ft_printf("({red}%u{eoc} bytes > ", ft_strlen((const char*)*b));
		ft_printf("%u bytes)\n", COMMENT_LENGTH);
		return ;
	}
	ft_printf("'%s' prog size is invalid ", c->p[c->player].name);
	ft_printf("({red}%u{eoc} bytes > ", c->p[c->player].prog_size);
	ft_printf("%u bytes)\n", CHAMP_MAX_SIZE);
}

static	int			get_arg(char *param, t_core *c, int fd, int ret)
{
	unsigned char	*oct;

	oct = c->p[c->player].buff;
	if (c->player == MAX_PLAYERS)
		return (ft_printf("1 - %d max players\n", MAX_PLAYERS));
	if (*param != '-')
	{
		if ((fd = open(param, O_RDONLY)) == -1)
			return (ft_printf("{red}%s{eoc} is invalid file\n", param));
		ret = read(fd, c->p[c->player].buff, FILE_MAX_SIZE + 1);
		close(fd);
		if (ret == -1)
			return (ft_printf("'%s' file can not be read\n", param));
		get_magic_number(&oct, c, -1);
		c->p[c->player].bd & VALID_NAME_LEN ? get_prog_size(&oct, c, -1) : 0;
		if (!(ret = 0) && !(c->p[c->player].bd & VALID_CHAMP_LEN))
			return (1);
		while (!c->p[c->player].id && ++ret < MAX_PLAYERS)
			if (!c->id[ret] && (c->id[ret] = 1))
				c->p[c->player].id = ret;
		++c->player;
	}
	else
		return (get_options((unsigned char*)param + 1, c));
	return (0);
}

static	void		put_champ(t_core *c, unsigned int i)
{
	unsigned int	start;

	start = 0;
	while (i < c->player)
	{
		start = MEM_SIZE / c->player * i;
		ft_memcpy(&c->ram[start], c->p[i].prog, c->p[i].prog_size);
		c->p[i].oc = start;
		!c->p[i].id ? c->p[i].id = i + 1 : 0;
		++i;
	}
}

int					main(int argc, char **argv)
{
	unsigned int	i;
	t_core			c;

	i = 0;
	if (argc > 1 && init_core(&c, 1))
	{
		c.first_arg = *argv;
		while (++i < (unsigned int)argc && argv[i])
			if (get_arg(argv[i], &c, i, 0) || c.bd == ERROR)
				return (0);
		c.player && c.bd & GET_OPT ? ft_printf("Missing one champion\n") : 0;
		c.player && !(c.bd & GET_OPT) ? put_champ(&c, 0) : 0;
		c.player && !(c.bd & GET_OPT) ? corewar(&c) : 0;
		!c.player ? display_usage(*argv) : 0;
	}
	else if (!(c.bd & INIT))
		display_usage(*argv);
	return (0);
}
