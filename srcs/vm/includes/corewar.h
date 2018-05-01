/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:40:49 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/01 13:44:02 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "op.h"

# define VALID_C_E_M		(1 << 0)
# define INVALID_C_E_M		(1 << 1)

# define FILE_MAX_SIZE (4 + 128 + 4 + 4 + 2048 + 4 + (MEM_SIZE / 6))

typedef		struct			s_core
{
	unsigned char			ram[MEM_SIZE];
	unsigned int			n_player;
	unsigned int			bd;
}							t_core;

#endif
