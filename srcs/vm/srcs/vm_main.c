/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 18:19:30 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/10 15:12:37 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"
#include "visu.h"

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
		ft_printf("('{red}%d{eoc}' bytes > ", ft_strlen((const char*)*b));
		ft_printf("%u bytes) invalid name length '%s'\n", PROG_NAME_LENGTH, *b);
		return ;
	}
	display_error(c, 6, NULL);
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
		ft_printf("('{red}%u{eoc}' bytes > ", ft_strlen((const char*)*b));
		ft_printf("%u bytes): invalid comment length for ", COMMENT_LENGTH);
		ft_printf("'%s'\n", c->p[c->player].name);
		return ;
	}
	ft_printf("'%s' prog size is invalid ", c->p[c->player].name);
	ft_printf("('{red}%u{eoc}' bytes > ", c->p[c->player].prog_size);
	ft_printf("%u bytes)\n", CHAMP_MAX_SIZE);
}

static	int			get_arg(char *s, t_core *c, int fd, int ret)
{
	unsigned char	*oct;

	oct = c->p[c->player].buff;
	if (c->player == MAX_PLAYERS)
		return (display_error(c, 4, NULL));
	if ((*s == '-') || (c->bd & GET_DUMP) || (c->bd & GET_ID))
		return (get_options((unsigned char*)s, c));
	if ((ret = ft_strlen(s)) <= 4 || ft_strcmp(&s[ret - 4], ".cor"))
		return (display_error(c, 1, s));
	if ((fd = open(s, O_RDONLY)) == -1)
		return (display_error(c, 2, s));
	ret = read(fd, c->p[c->player].buff, FILE_MAX_SIZE + 1);
	close(fd);
	if (ret == -1)
		return (display_error(c, 3, s));
	get_magic_number(&oct, c, -1);
	c->p[c->player].bd & VALID_NAME_LEN ? get_prog_size(&oct, c, -1) : 0;
	if (!(ret = 0) && !(c->p[c->player].bd & VALID_CHAMP_LEN))
		return (1);
	while (!c->p[c->player].id && ++ret < MAX_PLAYERS)
		if (!c->id[ret] && (c->id[ret] = 1))
			c->p[c->player].id = ret;
	++c->player;
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
		c.player && c.bd & GET_OPT ? display_error(&c, 5, NULL) : 0;
		c.player && !(c.bd & GET_OPT) ? put_champ(&c, 0) : 0;
		c.player && !(c.bd & GET_OPT) ? corewar(&c) : 0;
		!c.player ? display_usage(*argv) : 0;
	}
	else if (!(c.bd & INIT))
		display_usage(*argv);
	return (0);
}
