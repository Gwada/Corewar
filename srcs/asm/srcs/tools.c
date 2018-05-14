/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 22:13:48 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/05/13 22:17:36 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h>

void		check_labels(t_data *data)
{
	t_cmd		*cmd;
	int			i;

	cmd = data->cmd;
	while (cmd)
	{
		i = 0;
		while (i < 3 && cmd->p_name[i])
		{
			if (!cmd->p_val[i])
			{
				cmd->p_val[i] = get_param_value(cmd->p_name[i], data);
				if (is_lab(cmd->p_name[i]) ||
						(is_dir(cmd->p_name[i]) && is_lab(cmd->p_name[i] + 1)))
					cmd->p_val[i] -= cmd->index;
			}
			i++;
		}
		cmd = cmd->next;
	}
}

t_label		*go_lastlabel(t_label *label)
{
	t_label	*tmp;

	tmp = label;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void		put_err(char *msg, int line)
{
	if (line > 0)
		//	{
		printf("Error line %d : %s\n", line, msg);
	//		ft_putstr_fd("Error line ", 2);
	//		ft_putnbr_fd(line, 2);
	//		ft_putstr_fd(" : ", 2);
	//	}
	else
		printf("Error : %s\n", msg);
	//	ft_putstr_fd(errmsg, 2);
	//	ft_putstr_fd("\n", 2);
}

void			handle_err(int num, int line)
{
	num == 1 ? ft_putendl_fd("Usage: ./asm imput_file.s\n", 2) : 0;
	num == 2 ? put_err("Wrong name/flag [-h] for help", line) : 0;
	num == 3 ? put_err("Too many or no arguments [-h] for help", line) : 0;
	num == 4 ? put_err("Invalid file extension, .s requiered", line) : 0;
	num == 5 ? put_err("Invalid argument, can not open the file", line) : 0;
	num == 6 ? put_err("Champion's name expected", line) : 0;
	num == 7 ? put_err("Champions's comment expected", line) : 0;
	num == 8 ? put_err("Error in Champion's name format", line) : 0;
	num == 9 ? put_err("Champion's name is too long", line) : 0;
	num == 10 ? put_err("Error in Champion's comment format", line) : 0;
	num == 11 ? put_err("Champion's comment is too long", line) : 0;
	num == 12 ? put_err("Unknow instruction", line) : 0;
	num == 13 ? put_err("Invalid number of parameters", line) : 0;
	num == 14 ? put_err("Invalid parameter(s)", line) : 0;
	num == 15 ? put_err("Label used as parameter does not exist", line) : 0;
	num == 42 ? put_err("A memory allocation failed", line) : 0;
	/*	errnum == 4 ? put_err("Invalid argument", line) : 0;
		errnum == 5 ? put_err("Champion name expected", line) : 0;
		errnum == 6 ? put_err("Champion name is too long", line) : 0;
		errnum == 7 ? put_err("Champion comment expected", line) : 0;
		errnum == 8 ? put_err("Champion comment is too long", line) : 0;
		errnum == 9 ? put_err("Unknow instruction", line) : 0;
		errnum == 10 ? put_err("Invalid parameter(s)", line) : 0;
		errnum == 11 ? put_err("Invalid number of parameters", line) : 0;
		errnum == 14 ? put_err("Label used as parameter does not exist", line) : 0;
		errnum == 15 ? put_err("There is no instruction", line) : 0;
		errnum == 16 ? put_err("Creating the output file failed", line) : 0;
		errnum == 17 ? put_err("A memory allocation failled", line) : 0;*/
	exit(0);
}
