/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:35:23 by brigoux           #+#    #+#             */
/*   Updated: 2016/03/24 16:12:04 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"

# define BUFF_SIZE 42

typedef struct		s_file
{
	struct s_file	*next;
	int				fd;
	int				eof;
	char			*remain;
}					t_file;

int					get_next_line(int const fd, char **line);

#endif
