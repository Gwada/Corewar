/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 21:46:58 by brigoux           #+#    #+#             */
/*   Updated: 2016/06/20 13:44:50 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			print_annotated(t_data *data)
{
	t_cmd		*cmd;
	t_label		*label;

	ft_printf("Dumping annotated program on standard output\n");
	ft_printf("Program size : %u bytes\n", data->header->prog_size);
	ft_printf("Name : \"%s\"\n", data->header->prog_name);
	ft_printf("Comment : \"%s\"\n\n", data->header->comment);
	cmd = data->cmd;
	while (cmd && (cmd->label->name || cmd->opcode))
	{
		label = cmd->label;
		while (label && label->name)
		{
			ft_printf("%-11i%-5s%s:\n", cmd->index, ":", label->name);
			label = label->next;
		}
		if (cmd->opcode)
			print_cmd(cmd, get_optab_index(cmd->opcode));
		cmd = cmd->next;
	}
}

void			print_cmd(t_cmd *cmd, int i)
{
	int		p;
	int		o;

	ft_printf("%-5i(%-3i) %-9s%-10s", cmd->index, cmd->size, ":",
			g_op_tab[i].op);
	p = -1;
	while (++p < 3 && cmd->p_name[p])
		ft_printf("%-18s", cmd->p_name[p]);
	g_op_tab[i].ocp ? ft_printf("\n%20s%-4i%-6i", " ", cmd->opcode, cmd->ocp) :
		ft_printf("\n%20s%-10i", " ", cmd->opcode);
	p = -1;
	while (++p < 3 && cmd->p_name[p])
	{
		o = get_size(cmd->p_name[p], cmd->opcode);
		while (o--)
			ft_printf("%-4i", (unsigned int)
					(cmd->p_val[p] & 0xff << 8 * o) / (1 << 8 * o));
		ft_putnchar(' ', ((4 - get_size(cmd->p_name[p], cmd->opcode)) * 4 + 2));
	}
	g_op_tab[i].ocp ? ft_printf("\n%20s%-4i%-6i", " ", cmd->opcode, cmd->ocp) :
		ft_printf("\n%20s%-10i", " ", cmd->opcode);
	p = -1;
	while (++p < 3 && cmd->p_name[p])
		ft_printf("%-18i", cmd->p_val[p]);
	ft_printf("\n\n");
}

static void		put_err(char *errmsg, int line)
{
	if (line > 0)
	{
		ft_putstr_fd("Error line ", 2);
		ft_putnbr_fd(line, 2);
		ft_putstr_fd(" : ", 2);
	}
	else
		ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(errmsg, 2);
	ft_putstr_fd("\n", 2);
}

void			print_error(int errnum, int line)
{
	errnum == 1 ? put_err("A memory allocation failled", line) : 0;
	errnum == 2 ? put_err("No arguments (-h for help)", line) : 0;
	errnum == 3 ? put_err("Too many arguments", line) : 0;
	errnum == 4 ? put_err("Invalid argument", line) : 0;
	errnum == 13 ? put_err("Invalid file extension", line) : 0;
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
	exit(1);
}

void			print_help(void)
{
	ft_putstr("Usage: asm [-ah] <sourcefile.s>\n");
	ft_putstr("\n");
	ft_putstr("  a : Instead of creating a .cor file, outputs a stripped and");
	ft_putstr("      annotated version of the code to the standard output\n");
	ft_putstr("  h : print this help message\n");
	exit(0);
}
