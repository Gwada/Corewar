/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 18:19:30 by dlavaury          #+#    #+#             */
/*   Updated: 2018/04/30 20:21:08 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"
#include "../../libft/includes/ft_printf.h"

static	void	put_usage(void)
{
	ft_printf("Usage: ./corewar <champion1.cor> <...>\n");
}

static	int			get_file(char **param)
{
	int				i;
	int				fd;
	unsigned char	s;

	ft_printf("|%s|\n\n", param[1]);
	if ((fd = open(param[1], O_RDONLY)) == -1)
	{
		ft_printf("error open\n");
		return (1);
	}
	i = -1;
	while (++i < 4)
	{
		read(fd, &s, 1);
		if (i > 0)
		{
			ft_printf("%d)\t|%hhb|\n", i, s);
			ft_printf("|%d| |%x|\n", (unsigned int)s, (unsigned int)s);
		}
	}
	close(fd);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (get_file(argv))
			ft_printf("error\n");
	}
	else
		put_usage();
	return (0);
}
