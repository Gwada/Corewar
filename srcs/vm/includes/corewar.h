/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:40:49 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/04 20:31:49 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "op.h"

# define VALID_MAG			(1 << 0)
# define VALID_NAME_LEN		(1 << 1)
# define VALID_CHAMP_LEN	(1 << 2)
# define GET_OPT			(1 << 3)
# define DUMP				(1 << 4)
# define INIT				(1 << 5)
# define ERROR				(1 << 6)
# define VISUAL				(1 << 7)

# define MAX_RAM			(0x186a0)
# define FILE_SIZE			(4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4)
# define FILE_MAX_SIZE		(FILE_SIZE + CHAMP_MAX_SIZE)

typedef struct				s_player
{
	unsigned char			id;
	unsigned char			*name;
	unsigned char			*comment;
	unsigned char			*prog;
	unsigned int			bd;
	unsigned int			magic;
	unsigned int			prog_size;
	unsigned char			buff[FILE_MAX_SIZE];

}							t_player;

typedef struct				s_core
{
	char					*first_arg;
	unsigned char			ram[MEM_SIZE];
	unsigned int			bd;
	unsigned int			dump;
	unsigned int			player;
	t_player				p[MAX_PLAYERS + 1];
	unsigned char			id[MAX_PLAYERS + 1];
}							t_core;

void						corewar(t_core *core);
void						display_usage(char *name);
int							get_options(unsigned char *opt, t_core *c);
size_t						init_core(t_core *core, size_t ret);

#endif
