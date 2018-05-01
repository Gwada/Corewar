/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 18:19:30 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/01 21:10:56 by dlavaury         ###   ########.fr       */
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
	}

/*
**	Debug Display
*/
	if (c->p[c->player].bd & VALID_MAG)//
	{//
		ft_printf("'%x'\t{green}valid magic number{eoc}\n", c->p[c->player].magic);//
		if (c->p[c->player].bd & VALID_NAME_LEN)//
		{//
			ft_printf("'%d'\t\t", ft_strlen((const char *)c->p[c->player].name));//
			ft_printf("{green}%19s{eoc}", "valid name_len ");//
			ft_printf("\t'%s'\t", c->p[c->player].name);//
			ft_printf("{green}valid name\n{eoc}", c->p[c->player].name);//
		}//
		else//
		{
			ft_printf("'%d'\t\t", ft_strlen((const char *)c->p[c->player].name));//
			ft_printf("{red}%19s{eoc}", "invalid name_len\n\n");//
		}
	}//
	else//
		ft_printf("'%x'\t{red}valid magic number{eoc}\n", c->p[c->player].magic);//
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

		ft_printf("%u(d) ", c->p[c->player].prog_size);//
		ft_printf("%x(h)\t", c->p[c->player].prog_size);//
		ft_printf("{green}%18s{eoc}\t", "valid prog_size");//
		ft_printf("'%s'\t", c->p[c->player].comment);//
		ft_printf("{green}valid com{eoc}\n");//
	}
	else//
	{//
		ft_printf("{red}'%s' invalid prog_size ", c->p[c->player].name);//
		ft_printf("(%u bytes > ", c->p[c->player].prog_size);//
		ft_printf("%u bytes)\n{eoc}", CHAMP_MAX_SIZE);//
	}//
}

static	int			get_arg(char *param, t_core *c)
{
	int				fd;
	int				ret;
	unsigned char	*oct;

	oct = c->p[c->player].buff;
	if (*param != '-')
	{
		if ((fd = open(param, O_RDONLY)) == -1)
			return (ft_printf("error open\n"));//
		if ((ret = read(fd, c->p[c->player].buff, FILE_MAX_SIZE + 1)) == -1)
		{
			close(fd);
			return (ft_printf("error read\n"));//
		}
		if (c->player == MAX_PLAYERS)
		{
			ft_printf("(%u > %d)", c->player + 1, MAX_PLAYERS);
			ft_printf(" {red}too much players{eoc}\n");
			return (1);
		}
//		ft_printf("FILE_MAX_SIZE = %d\tret = %d\n", FILE_MAX_SIZE, ret);//

		get_magic_number(&oct, c, -1);
		c->p[c->player].bd & VALID_NAME_LEN ? get_prog_size(&oct, c, -1) : 0;

		ft_printf("(hex)%hhx (dec)%hhu\n\n", *oct, *oct);


		if (!(c->p[c->player].bd & VALID_CHAMP_LEN))
			return (1);
		close(fd);
		++c->player;
	}
	else
	{
		// get_options(param, c,); recuperation des options;
		ft_printf("{blue}IS OPTION{eoc}\n");
	}
	return (0);
}

static	void		put_champ(t_core *c, unsigned int i)
{
	unsigned int	start;

	ft_printf("MEM_SIZE = %u\n", MEM_SIZE);
	start = 0;
	while (i < c->player)
	{
		start = MEM_SIZE / c->player * i;
		ft_printf("i = %u\n", start);
		ft_memcpy(&c->ram[start], &c->p[i].prog, c->p[i].prog_size);
		++i;
	}
	(void)c;
	(void)i;
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
		{
			ft_printf("{yellow}player %d{eoc}\n", c.player + 1);
			if (get_arg(argv[i], &c)) // erreur lors du parsing
				return (ft_printf("{red}error parsing\n{eoc}"));
		}
		put_champ(&c, 0);
		ft_print_memory(c.ram, MEM_SIZE, 32);
		i = 0;//
		while (i < c.player)//
		{
			ft_printf("jr %d name %s\n", i + 1, c.p[i].name);//
			++i;//
		}//
	}
	else //fonction de display error
		ft_printf("Usage: ./corewar <champion1.cor> <...>\n");
	return (0);
}
