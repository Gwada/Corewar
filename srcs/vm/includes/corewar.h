/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:40:49 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/03 21:07:21 by dlavaury         ###   ########.fr       */
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
# define INIT				(1 << 31)

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
	unsigned char			ram[MEM_SIZE];
	unsigned int			bd;
	unsigned int			player;
	t_player				p[MAX_PLAYERS + 1];
}							t_core;

void						corewar(t_core *core);
size_t						init_core(t_core *core, size_t ret);

#endif
