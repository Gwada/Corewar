/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:43:31 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/25 22:32:39 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "op.h"
# include <ncurses.h>
# include <fcntl.h>

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define PC(pc)			(((pc) + MEM_SIZE) % MEM_SIZE)
# define P_E(errmsg)	ft_putstr_fd(errmsg, 2)
# define CTD(num)		((num) < 0 ? 0 : (num))

# define COLOR_GREY		8
# define COLOR_BLUE_C	9
# define COLOR_GREEN_C	10
# define COLOR_YELLOW_C	11
# define COLOR_RED_C		12
# define COLOR_WW		13

# define STAT_PC		1
# define STAT_COPY		2
# define STAT_LIVE		4
# define STAT_AFF		8
# define STAT_NUM		112
# define STAT_DELAY		128

# define OPCODE_LIVE	1
# define OPCODE_LD		2
# define OPCODE_ST		3
# define OPCODE_ADD		4
# define OPCODE_SUB		5
# define OPCODE_AND		6
# define OPCODE_OR		7
# define OPCODE_XOR		8
# define OPCODE_ZJMP	9
# define OPCODE_LDI		10
# define OPCODE_STI		11
# define OPCODE_FORK	12
# define OPCODE_LLD		13
# define OPCODE_LLDI	14
# define OPCODE_LFORK	15
# define OPCODE_AFF		16

# define CPS_LIMIT		0

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

typedef struct			s_inst
{
	int					opcode;
	int					param[3];
	int					type[3];
}						t_inst;

typedef struct			s_process
{
	struct s_process	*next;
	int					num;
	int					player;
	int					reg[REG_NUMBER];
	int					pc;
	int					carry;
	int					timer;
	int					last_live;
	int					period_live;
}						t_process;

typedef struct			s_player
{
	int					number;
	t_header			header;
	char				*champion;
	char				*file_name;
	int					last_live;
	int					period_live;
}						t_player;

typedef struct			s_data
{
	char				status[MEM_SIZE];
	char				memory[MEM_SIZE];
	t_player			player[MAX_PLAYERS];
	int					dump;
	int					cycle;
	int					period_cycle;
	int					cycle_to_die;
	int					check;
	int					ncurses;
	int					mute;
	t_process			*process;
	int					last_live;
	int					last_pnum;
}						t_data;

typedef struct			s_nit
{
	int					i;
	int					j;
	int					x;
	int					y;
	int					w;
	int					h;
}						t_nit;

typedef struct			s_win_border_struct
{
	chtype				ls;
	chtype				rs;
	chtype				tr;
	chtype				ts;
	chtype				bs;
	chtype				bl;
	chtype				tl;
	chtype				br;
}						t_win_border;

typedef struct			s_win_content_struct
{
	int					val;
	int					x;
	int					y;
}						t_win_content;

typedef struct			s_win_struct
{
	int					startx;
	int					starty;
	int					height;
	int					width;
	t_win_border		border;
	t_win_content		content;
}						t_win;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

t_data					*g_data;

char					*g_running;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

int						check_inst(t_inst *inst);
void					check_numbers(int *n1);
void					check_playerorder(void);
void					check_process(t_process **process);
void					check_status(void);

void					do_cycle(void);
void					do_process(t_process *process);

void					get_inst(int pc, t_inst *inst);
int						get_instlen(int pc);
int						get_intfrommem(int pc, int len);
int						get_nbplayers(void);
int						get_periodlive(void);
int						get_revertint(int i);

void					init_player(int n);
void					init_process(t_process *process, int pc);
void					init_vm(void);

int						racine_carre(int val, int nb);
int						basic_status(int nb);
int						colored_status(int nb);
int						color_status(int nb);
void					color_one(void);
int						colored_status(int nb);
void					color_initialize(void);
t_win					ncurses_main_bis(void);
void					ncurses_main(void);
void					init_win_params(t_win *p_win);
void					wait_for_key(void);
int						print_winner(t_nit n, int started);
int						print_players(int x, int y, int w, t_player player[]);
void					create_box(t_win *p_win, bool flag);

void					op_add(t_process *process, t_inst *inst);
void					op_aff(t_process *process, t_inst *inst);
void					op_and(t_process *process, t_inst *inst);
void					op_fork(t_process *process, t_inst *inst);
void					op_ld(t_process *process, t_inst *inst);
void					op_ldi(t_process *process, t_inst *inst);
void					op_lfork(t_process *process, t_inst *inst);
void					op_live(t_process *process, t_inst *inst);
void					op_lld(t_process *process, t_inst *inst);
void					op_lldi(t_process *process, t_inst *inst);
void					op_st(t_process *process, t_inst *inst);
void					op_sti(t_process *process, t_inst *inst);
void					op_sub(t_process *process, t_inst *inst);
void					op_or(t_process *process, t_inst *inst);
void					op_xor(t_process *process, t_inst *inst);
void					op_zjmp(t_process *process, t_inst *inst);

void					parse_args(int argc, char **argv);
void					parse_playerinfo(int i, int argc, char **argv);

void					print_dump(void);
void					print_end(void);
void					print_error(int errnum);
void					print_help(void);
void					print_start(void);

void					run_ncurses(void);
void					run_vm(void);

void					set_memory(int pc, char *src, int len);
void					set_status(int pc, char *src, int len);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
