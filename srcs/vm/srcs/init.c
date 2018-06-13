/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 09:38:16 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/13 15:28:02 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

static	void	display_init(size_t code)
{
	!code ? ft_printf("op.h: PROG_NAME_LENGTH must be 128\n") : 0;
	code == 1 ? ft_printf("op.h: COMMENT_LENGTH must be 2048\n") : 0;
	code == 2 ? ft_printf("op.h: COREWAR_EXEC_MAGIC must be 0xea83f3\n") : 0;
	code == 3 ? ft_printf("op.h: MAX_PLAYERS must be 4\n") : 0;
	code == 4 ? ft_printf("op.h: MEM_SIZE must be 4 * 1024\n") : 0;
	code == 5 ? ft_printf("op.h: IDX_MOD must be MEM_SIZE / 8\n") : 0;
	code == 6 ? ft_printf("op.h: CHAMP_MAX_SIZE must be MEM_SIZE / 6\n") : 0;
	code == 7 ? ft_printf("op.h: REG_SIZE must be 4\n") : 0;
	code == 8 ? ft_printf("op.h: IND_SIZE must be 2\n") : 0;
	code == 9 ? ft_printf("op.h: DIR_SIZE must be equal to REG_SIZE\n") : 0;
	code == 10 ? ft_printf("op.h: REG_CODE must be 1\n") : 0;
	code == 11 ? ft_printf("op.h: DIR_CODE must be 2\n") : 0;
	code == 12 ? ft_printf("op.h: IND_CODE must be 3\n") : 0;
	code == 13 ? ft_printf("op.h: REG_NUMBER must be 16\n") : 0;
	code == 14 ? ft_printf("op.h: T_REG must be 1\n") : 0;
	code == 15 ? ft_printf("op.h: T_DIR must be 2\n") : 0;
	code == 16 ? ft_printf("op.h: T_IND must be 4\n") : 0;
	code == 17 ? ft_printf("op.h: T_LAB must be 8\n") : 0;
	code == 18 ? ft_printf("op.h: MAX_ARGS_NUMBER must be 4\n") : 0;
}

static void		init_tab_functions(t_core *core)
{
	core->ft[0] = live_;
	core->ft[1] = ld_;
	core->ft[2] = st_;
	core->ft[3] = add_;
	core->ft[4] = sub_;
	core->ft[5] = and_;
	core->ft[6] = or_;
	core->ft[7] = xor_;
	core->ft[8] = zjmp_;
	core->ft[9] = ldi_;
	core->ft[10] = sti_;
	core->ft[11] = fork_;
	core->ft[12] = lld_;
	core->ft[13] = lldi_;
	core->ft[14] = lfork_;
	core->ft[15] = aff_;
	core->v[0] = get_mem_addr;
	core->v[1] = get_reg_ind;
	core->v[2] = get_dir_value;
	core->v[3] = get_ind;
	core->v[4] = get_ind_value;
	core->v[5] = get_len;
}

static void		init_tab_ex_functions(t_core *core)
{
	core->ex[0] = ex_live;
	core->ex[1] = ex_ld;
	core->ex[2] = ex_st;
	core->ex[3] = ex_add;
	core->ex[4] = ex_sub;
	core->ex[5] = ex_and;
	core->ex[6] = ex_or;
	core->ex[7] = ex_xor;
	core->ex[8] = ex_zjmp;
	core->ex[9] = ex_ldi;
	core->ex[10] = ex_sti;
	core->ex[11] = ex_fork;
	core->ex[12] = ex_lld;
	core->ex[13] = ex_lldi;
	core->ex[14] = ex_lfork;
	core->ex[15] = ex_aff;
}

size_t			init_core(t_core *core, size_t ret)
{
	ft_bzero(core, sizeof(*core));
	PROG_NAME_LENGTH != 128 && !(ret = 0) ? display_init(0) : 0;
	COMMENT_LENGTH != 2048 && !(ret = 0) ? display_init(1) : 0;
	COREWAR_EXEC_MAGIC != 0xea83f3 && !(ret = 0) ? display_init(2) : 0;
	MAX_PLAYERS != 4 && !(ret = 0) ? display_init(3) : 0;
	MEM_SIZE != 4 * 1024 && !(ret = 0) ? display_init(4) : 0;
	IDX_MOD != MEM_SIZE / 8 && !(ret = 0) ? display_init(5) : 0;
	CHAMP_MAX_SIZE != MEM_SIZE / 6 && !(ret = 0) ? display_init(6) : 0;
	REG_SIZE != 4 && !(ret = 0) ? display_init(7) : 0;
	IND_SIZE != 2 && !(ret = 0) ? display_init(8) : 0;
	DIR_SIZE != REG_SIZE && !(ret = 0) ? display_init(9) : 0;
	REG_CODE != 1 && !(ret = 0) ? display_init(10) : 0;
	DIR_CODE != 2 && !(ret = 0) ? display_init(11) : 0;
	IND_CODE != 3 && !(ret = 0) ? display_init(12) : 0;
	REG_NUMBER != 16 && !(ret = 0) ? display_init(13) : 0;
	T_REG != 1 && !(ret = 0) ? display_init(14) : 0;
	T_DIR != 2 && !(ret = 0) ? display_init(15) : 0;
	T_IND != 4 && !(ret = 0) ? display_init(16) : 0;
	T_LAB != 8 && !(ret = 0) ? display_init(17) : 0;
	MAX_ARGS_NUMBER != 4 && !(ret = 0) ? display_init(18) : 0;
	ret ? init_tab_functions(core) : 0;
	ret ? init_tab_ex_functions(core) : 0;
	core->bd |= INIT;
	core->max_cycle = CYCLE_TO_DIE;
	return (ret);
}
