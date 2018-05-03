/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 09:38:16 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/03 16:09:22 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

static	void	display_init(size_t value_code)
{
	!value_code ? ft_printf("op.h: PROG_NAME_LENGTH must be > 0\n") : 0;
	value_code == 1 ? ft_printf("op.h: COMMENT_LENGTH must be > 0\n") : 0;
	value_code == 2 ? ft_printf("op.h: COREWAR_EXEC_MAGIC must be >= 0\n") : 0;
	value_code == 3 ? ft_printf("op.h: MAX_PLAYERS must be > 0\n") : 0;
	if (value_code == 4)
	{
		ft_printf("op.h: MEM_SIZE (%u bytes) must be bigger than ", MEM_SIZE);
		ft_printf("MAX_PLAYERS * CHAMP_MAX_SIZE ", MEM_SIZE);
		ft_printf("(%u bytes)\n", MAX_PLAYERS * CHAMP_MAX_SIZE);
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
	core->bd |= INIT;
	return (ret);
}
