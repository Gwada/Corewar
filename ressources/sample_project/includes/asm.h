/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 21:26:21 by brigoux           #+#    #+#             */
/*   Updated: 2016/06/18 22:24:07 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# include "op.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# include <fcntl.h>

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

# define O_FLAGS	O_RDWR | O_CREAT | O_TRUNC
# define S_FLAGS	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

typedef struct		s_flag
{
	int				a;
	int				h;
	int				n;
}					t_flag;

typedef struct		s_cmd
{
	struct s_cmd	*next;
	struct s_label	*label;
	int				index;
	int				opcode;
	char			*p_name[3];
	int				ocp;
	int				p_val[3];
	int				size;
}					t_cmd;

typedef struct		s_data
{
	t_header		*header;
	t_flag			*flag;
	char			*src;
	char			*dst;
	int				line;
	t_cmd			*cmd;
	int				end;
}					t_data;

typedef struct		s_label
{
	struct s_label	*next;
	char			*name;
}					t_label;

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

void				check_labels(t_data *data);

int					get_bigendian(int i);
int					get_code(char *param);
int					get_optab_index(int opcode);
int					get_size(char *param, int opcode);
int					get_value(char *param, t_data *data);

int					is_dir(char *param);
int					is_ind(char *param);
int					is_lab(char *param);
int					is_reg(char *param);

t_cmd				*new_cmd(void);
t_data				*new_data(void);
t_flag				*new_flag(void);
t_header			*new_header(void);
t_label				*new_label(void);

t_data				*parse_args(int argc, char **argv);
t_flag				*parse_flag(char *str, t_flag *flag);

void				print_annotated(t_data *data);
void				print_cmd(t_cmd *cmd, int i);
void				print_error(int errnum, int line);
void				print_help(void);

void				read_source(t_data *data);
void				read_name(int fd, t_data *data);
void				read_comment(int fd, t_data *data);
void				read_commands(int fd, t_data *data);

void				store_comment(char *line, t_data *data);
void				store_cmd(char *line, t_cmd *cmd, t_data *data);
void				store_label(char **line, t_cmd *cmd);
void				store_name(char *line, t_data *data);
void				store_params(char **tab, t_cmd *cmd, t_data *data);

void				write_cmd(int fd, t_cmd *cmd);
void				write_file(t_data *data);

/*
** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
*/

#endif
