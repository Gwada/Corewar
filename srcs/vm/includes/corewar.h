/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:40:49 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/07 21:30:30 by dlavaury         ###   ########.fr       */
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
# define INST_NUMBERS		(16)

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
	unsigned char			buff[FILE_MAX_SIZE];

}							t_player;

typedef struct				s_process
{
	unsigned int			carry;
	unsigned int			live;
	unsigned int			n_live;
	unsigned int			reg[REG_NUMBER + 1];
	t_op					ins;
	struct s_process		*next;
}							t_process;

typedef struct				s_core
{
	char					*first_arg;
	unsigned char			ram[MEM_SIZE];
	unsigned int			bd;
	unsigned int			dump;
	unsigned int			player; // nombre de player
	unsigned int			cycle;
	unsigned int			live;
	unsigned int			n_cycle;
	unsigned int			n_live;
	unsigned int			last_live_player;
	unsigned int			last_decr;
	unsigned int			max_cycle;
	unsigned int			n_process;
	t_player				p[MAX_PLAYERS + 1];
	unsigned char			id[MAX_PLAYERS + 1];
	void					(*ft[INST_NUMBERS + 1])(const unsigned char *c,
							t_process *process);
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
**	PROCESS FUNCTIONS
*/

t_process					*new_process(void);
t_process					*clean_process(t_process *lst);
t_process					*del_process(t_core *core, t_process *lst);
t_process					*init_process(t_core *core, int i);
void						insert_process(t_core *core, t_process **lst,
							t_process *new);

/*
**	INSTRUCT FUNCTIONS
*/

int							read_instruct(t_core *c, t_process *process);
unsigned int				id(unsigned int id);
void						add_data(t_op *dst, t_op *src);
int							_reg(const unsigned char oct, unsigned char opt);
int							_ind(const unsigned char oct, unsigned char opt);
int							_dir(const unsigned char oct, unsigned char opt);
int							_abs(const unsigned char oct, unsigned char opt);
void						_live(const unsigned char *oct, t_process *p);
void						_ld(const unsigned char *oct, t_process *p);
void						_st(const unsigned char *oct, t_process *p);
void						_add(const unsigned char *oct, t_process *p);
void						_sub(const unsigned char *oct, t_process *p);
void						_and(const unsigned char *oct, t_process *p);
void						_or(const unsigned char *oct, t_process *p);
void						_xor(const unsigned char *oct, t_process *p);
void						_zjmp(const unsigned char *oct, t_process *p);
void						_ldi(const unsigned char *oct, t_process *p);
void						_sti(const unsigned char *oct, t_process *p);
void						_fork(const unsigned char *oct, t_process *p);
void						_lld(const unsigned char *oct, t_process *p);
void						_lldi(const unsigned char *oct, t_process *p);
void						_lfork(const unsigned char *oct, t_process *p);
void						_aff(const unsigned char *oct, t_process *p);

void	visu(t_core *c, bool s);

#endif
