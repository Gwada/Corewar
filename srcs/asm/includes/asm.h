/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:40:49 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/14 17:47:18 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include "../libft/includes/libft.h"
#include "op.h"

#define LEFT_BM(x) ((1 << (3 - x) * 2))
#define QUIT -42
#define MALLOC_ERR 42

typedef struct		s_label
{
	char			*name;
	struct s_label	*next;
}					t_label;

typedef struct		s_cmd
{
	int				index;
	uint8_t			opcode;
	char			*p_name[3];
	int				ocp;
	int				p_val[3];
	int				size;
	t_label			*label;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_data
{
	char			*s;
	char			*cor;
	char			*gnl;
	int				name;
	int				comment;
	uint32_t		line;
	uint8_t			eof;
	t_cmd			*cmd;
	t_header		*header;
}					t_data;

void				write_cmd(int fd, t_cmd *cmd);
void				write_file(t_data *data);
void				read_cmd(int fd, t_data *data);
void				read_header(int fd, t_data *data);
void				read_file(t_data *data);

int					is_reg(char *param);
int					is_dir(char *param);
int					is_ind(char *param);
int					is_lab(char *param);

uint32_t			swap_bigendian(int var);
void				check_labels(t_data *data);
t_label				*go_lastlabel(t_label *label);
void				put_err(char *msg, int line);
void				handle_err(int num, int line);

int					get_optab_index(int opcode);
int					get_size(char *param, int op);
int					get_code(char *param);
int					get_param_value(char *param, t_data *data);

void				get_params(char **tab, t_cmd *cmd, t_data *data);
void				get_label(char **line, t_cmd *cmd);
void				get_cmd(char *line, t_cmd *cmd, t_data *data);
void				get_name(char *line, t_data *data, int fd);
void				get_comment(char *line, t_data *data, int fd);

t_label				*init_label(void);
t_cmd				*init_cmd(void);
t_header			*init_header(void);
void				init_data(t_data *data);

void				free_data(t_data *data);
void				free_cmd(t_cmd *list);
void				free_label(t_label *list);

#endif
