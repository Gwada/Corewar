/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 09:38:16 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/03 20:03:38 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

static	void	display_init(size_t code)
{
	!code ? ft_printf("op.h: PROG_NAME_LENGTH must be > 0\n") : 0;
	code == 1 ? ft_printf("op.h: COMMENT_LENGTH must be > 0\n") : 0;
	code == 2 ? ft_printf("op.h: COREWAR_EXEC_MAGIC must be >= 0\n") : 0;
	code == 3 ? ft_printf("op.h: MAX_PLAYERS must be > 0\n") : 0;
	if (code == 4)
	{
		ft_printf("op.h: MEM_SIZE (%u bytes) must be bigger than ", MEM_SIZE);
		ft_printf("MAX_PLAYERS * CHAMP_MAX_SIZE ", MEM_SIZE);
		ft_printf("(%u bytes)\n", MAX_PLAYERS * CHAMP_MAX_SIZE);
	}
	if (code == 5)
	{
		ft_printf("op.h: MEM_SIZE (%0x bytes) ", MEM_SIZE);
		ft_printf("must be < (%x bytes)\n", MAX_RAM);
	}
}

size_t		init_core(t_core *core, size_t ret)
{
	ft_bzero(core, sizeof(*core));
	PROG_NAME_LENGTH < 1 && !(ret = 0) ? display_init(0) : 0;
	COMMENT_LENGTH < 1 && !(ret = 0) ? display_init(1) : 0;
	COREWAR_EXEC_MAGIC < 0 && !(ret = 0) ? display_init(2): 0;
	MAX_PLAYERS < 1 && !(ret = 0) ? display_init(3): 0;
	if (MAX_PLAYERS * CHAMP_MAX_SIZE > MEM_SIZE && !(ret = 0))
		display_init(4);
	MEM_SIZE >= MAX_RAM && !(ret = 0) ? display_init(5) : 0;
	core->bd |= INIT;
	return (ret);
}
