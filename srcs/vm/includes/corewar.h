/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:40:49 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/13 17:45:56 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

/*
**	LIBRARIES
*/

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <ncurses.h>
# include "op.h"

/*
**	BINARY MASKS
*/

# define VALID_MAG			(1 << 0)
# define VALID_NAME_LEN		(1 << 1)
# define VALID_CHAMP_LEN	(1 << 2)
# define GET_OPT			(1 << 3)
# define DUMP				(1 << 4)
# define INIT				(1 << 5)
# define ERROR				(1 << 6)
# define VISUAL				(1 << 7)
# define DEBUG				(1 << 8)

# define FST				(1 << 0)
# define SND				(1 << 1)
# define TRD				(1 << 2)
# define FOTH				(1 << 3)
# define FITH				(1 << 4)
# define SITH				(1 << 5)
# define SETH				(1 << 6)
# define EITH				(1 << 7)

/*
**	VALUES DEFINES
*/

# define MAX_RAM			(0x186a0)
# define FILE_SIZE			(4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4)
# define FILE_MAX_SIZE		(FILE_SIZE + CHAMP_MAX_SIZE)
# define INST_NB			(16)

/*
**	STRUCTURES
*/

typedef struct				s_player
{
	unsigned char			id;
	unsigned char			*name;
	unsigned char			*comment;
	unsigned char			*prog;
	unsigned int			oc;
	unsigned int			bd;
	unsigned int			magic;
	unsigned int			prog_size;
	unsigned int			total_live;
	unsigned int			current_cycle_live;
	unsigned int			total_process;
	unsigned int			current_process;
	unsigned char			buff[FILE_MAX_SIZE];

}							t_player;

typedef struct				s_process
{
	unsigned int			carry;
	unsigned int			live;
	unsigned int			pc;
	unsigned int			rg[REG_NUMBER + 1];
	t_op					ins;
	struct s_process		*next;
}							t_process;

typedef struct				s_core
{
	char					*first_arg;
	unsigned char			ram[MEM_SIZE];
	unsigned int			bd;
	unsigned int			dump;
	unsigned int			player;
	int						max_cycle;
	unsigned int			total_cycle;
	unsigned int			current_cycle;
	unsigned int			last_decr;
	unsigned int			total_live;
	unsigned int			current_cycle_live;
	unsigned int			last_live_player;
	unsigned int			n_process;
	t_player				p[MAX_PLAYERS + 1];
	unsigned char			id[MAX_PLAYERS + 1];
	unsigned int			(*ft[INST_NB])(const unsigned char *c,
							t_process *process);
	void					(*ex[INST_NB])(struct s_core *c, t_process *p);
	unsigned int			(*v[5])(struct s_core *c, t_process *p,
							unsigned int i);
	t_process				*ps;
}							t_core;

/*
**	PROTOTYPS
*/

void						corewar(t_core *core);

/*
**	INIT AND PARSE FUNCTIONS
*/

int							get_options(unsigned char *opt, t_core *c);
size_t						init_core(t_core *core, size_t ret);

/*
**	DISPLAY FUNCTIONS
*/

void						display_usage(char *name);
void						display_error(t_core *core, int code);

/*
**	CYCLE FUNCTIONS
*/

size_t						cycle_checker(t_core *core);

/*
**	PROCESS FUNCTIONS
*/

t_process					*new_process(t_core *core);
t_process					*clean_process(t_process *lst);
t_process					*del_process(t_core *core, t_process *lst);
t_process					*init_process(t_core *core, int i);
void						insert_process(t_process **lst, t_process *new);

/*
**	INSTRUCT FUNCTIONS
*/

void						read_instruct(t_core *c, t_process *process);
void						exec_instruct(t_core *c, t_process *p,
							unsigned char opc);
unsigned short				id(unsigned int id);
unsigned int				opc_c(unsigned char opc);
void						add_data(t_op *dst, t_op *src);
unsigned int				_reg(const unsigned char oct, unsigned char opt);
unsigned int				_ind(const unsigned char oct, unsigned char opt);
unsigned int				_dir(const unsigned char oct, unsigned char opt);
unsigned int				_abs(const unsigned char oct, unsigned char opt);
unsigned int				_live(const unsigned char *oct, t_process *p);
unsigned int				_ld(const unsigned char *oct, t_process *p);
unsigned int				_st(const unsigned char *oct, t_process *p);
unsigned int				_add(const unsigned char *oct, t_process *p);
unsigned int				_sub(const unsigned char *oct, t_process *p);
unsigned int				_and(const unsigned char *oct, t_process *p);
unsigned int				_or(const unsigned char *oct, t_process *p);
unsigned int				_xor(const unsigned char *oct, t_process *p);
unsigned int				_zjmp(const unsigned char *oct, t_process *p);
unsigned int				_ldi(const unsigned char *oct, t_process *p);
unsigned int				_sti(const unsigned char *oct, t_process *p);
unsigned int				_fork(const unsigned char *oct, t_process *p);
unsigned int				_lld(const unsigned char *oct, t_process *p);
unsigned int				_lldi(const unsigned char *oct, t_process *p);
unsigned int				_lfork(const unsigned char *oct, t_process *p);
unsigned int				_aff(const unsigned char *oct, t_process *p);

unsigned int				get_mem_addr(t_core *core, t_process *process,
							unsigned int reg);
unsigned int				get_reg_ind(t_core *core, t_process *process,
							unsigned int reg);
unsigned int				get_ind(t_core *core, t_process *process,
							unsigned int reg);
unsigned int				get_dir_value(t_core *core, t_process *process,
							unsigned int ind);
unsigned int				get_ind_value(t_core *core, t_process *process,
							unsigned int reg);
void						_ex_live(t_core *core, t_process *process);
void						_ex_ld(t_core *core, t_process *process);
void						_ex_st(t_core *core, t_process *process);
void						_ex_add(t_core *core, t_process *process);
void						_ex_sub(t_core *core, t_process *process);
void						_ex_and(t_core *core, t_process *process);
void						_ex_or(t_core *core, t_process *process);
void						_ex_xor(t_core *core, t_process *process);
void						_ex_zjmp(t_core *core, t_process *process);
void						_ex_ldi(t_core *core, t_process *process);
void						_ex_sti(t_core *core, t_process *process);
void						_ex_fork(t_core *core, t_process *process);
void						_ex_lld(t_core *core, t_process *process);
void						_ex_lldi(t_core *core, t_process *process);
void						_ex_lfork(t_core *core, t_process *process);
void						_ex_aff(t_core *core, t_process *process);

void	visu(t_core *c, bool s);

#endif
