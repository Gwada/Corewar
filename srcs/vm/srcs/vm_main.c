/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 18:19:30 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/02 17:03:56 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

static	void		get_magic_number(unsigned char **oct, t_core *c, int i)
{
	while (++i < 4)
	{
		c->p[c->player].magic <<= 8;
		c->p[c->player].magic |= *(*oct)++;
	}
	c->p[c->player].name = *oct;
	if (c->p[c->player].magic == COREWAR_EXEC_MAGIC)
	{
		c->p[c->player].bd |= VALID_MAG;
		if (ft_strlen((const char*)*oct) <= PROG_NAME_LENGTH)
		{
			c->p[c->player].bd |= VALID_NAME_LEN;
			*oct += PROG_NAME_LENGTH + 4;
		}
		else
		{
			ft_printf("('{red}%d{eoc}' > ", ft_strlen((const char*)*oct));
			ft_printf("%u) invalid name length\n", PROG_NAME_LENGTH);
		}
	}
	else
	{
		ft_printf("'%s' magic number is invalid: ", *oct);
		ft_printf("'{red}%x{eoc}'\n", c->p[c->player].magic);
	}
}

static void			get_prog_size(unsigned char **oct, t_core *c, int i)
{
	while (++i < 4)
	{
		c->p[c->player].prog_size <<= 8;
		c->p[c->player].prog_size |= *(*oct)++;
	}
	if (c->p[c->player].prog_size <= CHAMP_MAX_SIZE)
	{
		c->p[c->player].bd |= VALID_CHAMP_LEN;
		c->p[c->player].comment = *oct;
		*oct += COMMENT_LENGTH + 4;
		c->p[c->player].prog = *oct;
	}
	else
	{
		ft_printf("'%s' prog size is invalid ", c->p[c->player].name);
		ft_printf("({red}%u bytes{eoc} > ", c->p[c->player].prog_size);
		ft_printf("%u bytes)\n", CHAMP_MAX_SIZE);
	}
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
			return (ft_printf("error open\n"));//
		ret = read(fd, c->p[c->player].buff, FILE_MAX_SIZE + 1);
		close(fd);
		if (ret == -1)
			return (ft_printf("error read\n"));//
		get_magic_number(&oct, c, -1);
		c->p[c->player].bd & VALID_NAME_LEN ? get_prog_size(&oct, c, -1) : 0;
		if (!(c->p[c->player].bd & VALID_CHAMP_LEN))
			return (1);
		++c->player;
	}
	else
	{
		// get_options(param, c,); recuperation des options;
		ft_printf("{blue}IS OPTION{eoc}\n");//
	}
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
		++i;
	}
	i = 0;//
	while (i < c->player)//
	{
		ft_printf("jr %d: '{blue}%s{eoc}'\n", i + 1, c->p[i].name);//
		++i;//
	}//
}

int					main(int argc, char **argv)
{
	unsigned int	i;
	t_core			c;

	i = 0;
	if (argc > 1)
	{
		ft_bzero(&c, sizeof(c));
		while (++i < (unsigned int)argc && argv[i])
			if (get_arg(argv[i], &c, 0, 0))
				return (ft_printf("{red}error parsing\n{eoc}"));
		put_champ(&c, 0);
		ft_print_mem(c.ram, MEM_SIZE, 64);//
		corewar(&c);
	}
	else //fonction de display error
		ft_printf("Usage: ./corewar <champion1.cor> <...>\n");
	return (0);
}
