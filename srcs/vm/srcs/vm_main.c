/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 18:19:30 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/01 17:47:06 by dlavaury         ###   ########.fr       */
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
			ft_printf("{green}valid name_len {eoc}");//
			ft_printf("\t\t'%s'\t", c->p[c->player].name);//
			ft_printf("{green}valid name\n{eoc}", c->p[c->player].name);//
		}//
		else//
			ft_printf("{red}invalid name len!!{eoc}\n\n");//
	}//
	else//
		ft_printf("{red}'%s'\tmagic number ko!!{eoc}\n\n", c->p[c->player].name);//
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

		ft_printf("%u(d) ", c->p[c->player].prog_size);//
		ft_printf("%x(h)\t", c->p[c->player].prog_size);//
		ft_printf("{green}valid prog_size{eoc}\t");//
		ft_printf("\t'%s'\t", c->p[c->player].comment);//
		ft_printf("{green}valid com{eoc}\n");//
	}
	else
	{
		ft_printf("{red}'%s' invalid prog_size ", c->p[c->player].name);//
		ft_printf("(%u bytes > ", c->p[c->player].prog_size);//
		ft_printf("%u bytes)\n{eoc}", CHAMP_MAX_SIZE);//
	}
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

//		ft_printf("FILE_MAX_SIZE = %d\tret = %d\n", FILE_MAX_SIZE, ret);//

		get_magic_number(&oct, c, -1);
		c->p[c->player].bd & VALID_NAME_LEN ? get_prog_size(&oct, c, -1) : 0;
		if (!(c->p[c->player].bd & VALID_CHAMP_LEN))
			return (1);
		close(fd);
	}
	else
	{
		// get_options(param, c,); recuperation des options;
		ft_printf("{blue}IS OPTION{eoc}\n");
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	t_core	c;

	i = 0;
	if (argc > 1)
	{
		ft_bzero(&c, sizeof(c));
		while (++i < argc && argv[i])
		{
			if (get_arg(argv[i], &c)) // erreur lors du parsing
				ft_printf("{red}error parsing\n{eoc}");
		}
	}
	else //fonction de display error
		ft_printf("Usage: ./corewar <champion1.cor> <...>\n");
	return (0);
}
