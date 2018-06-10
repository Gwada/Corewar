/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:44:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/10 20:32:55 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

void				add_data(t_op *dst, t_op *src)
{
	dst->name = src->name;
	dst->nb_param = src->nb_param;
	dst->description = src->description;
	dst->nb_cycles = src->nb_cycles;
	dst->op_code = src->op_code;
	dst->ocp = src->ocp;
	dst->label_size = src->label_size;
	!src->ocp ? *dst->param = *src->param : 0;
}

unsigned int		read_instruct(t_core *c, t_process *p)
{

	ft_printf("\t{bold}{blue}IN\tREAD_INSTRUCT");//
	ft_printf("\tOPC: %p P->C: %u{eoc}\n", c->ram[id(p->pc)], p->pc);//
	ft_printf("\t\t{green}carry\t= %u\t\tid_player = %u\n{eoc}", p->carry, -p->reg[1]);//

	unsigned char	opc;

	if (opc_c((opc = c->ram[id(p->pc)]) - 1))
	{
		add_data(&p->ins, &g_op_tab[opc - 1]);

		ft_printf("\t\tp->name\t\t= {green}%s{eoc}\n", p->ins.name);//
//		ft_printf("\t\tp->nb_param\t= {green}%d{eoc}\n", p->ins.nb_param);//
//		ft_printf("\t\tp->op_code\t= {green}%d{eoc}\n", p->ins.op_code);//
		ft_printf("\t\tp->nb_cycles\t= {green}%d{eoc}\n", p->ins.nb_cycles);//
//		ft_printf("\t\tp->description\t= {green}%s{eoc}\n", p->ins.description);//
//		ft_printf("\t\tp->ocp\t\t= {green}%d{eoc}\n", p->ins.ocp);//
//		ft_printf("\t\tp->label_size\t= {green}%d{eoc}\n", p->ins.label_size);//
		ft_printf("\t{bold}{blue}1 END\tREAD_INSTRUCT{eoc}\n");//

		return (1);
	}
	p->ins.name = NULL;
	p->ins.nb_cycles = 0;

//	ft_printf("\t{bold}{blue}2 END\tREAD_INSTRUCT{eoc}\n");//

	return (0);
}

int					moov_opc(t_core *c, t_process *p, int new_pc)
{
	new_pc = id(p->pc + new_pc);
	c->r_2[p->pc] &= ~OPC;
	c->r_2[new_pc] |= OPC;
	return (new_pc);
}

int					get_ind(t_core *core, t_process *process, int ind)
{

	int				i;
	short			n;

	i = 0;
	n = 0;
	while (i < 2)
		n = (n << 8) | (core->ram[id(process->pc + ind + i++)]);
	(void)process;
//	ft_printf("\t\t{red}direct (short){eoc}\t\tvalue = %#hx\t%hd\n", n, n);//
	return (n);
}

int					get_len(t_core *core, t_process *p, int ind)
{
	*p->l = p->ins.ocp ? 1 : 0;
	p->l[1] = *p->l + 1;
	if (*p->ins.param & T_REG || (*p->ins.param & T_DIR && !p->ins.label_size))
		*p->l += *p->ins.param & T_REG ? 1 : 4;
	else
		*p->l += 2;
	if (p->ins.nb_param > 1 && (p->l[2] = *p->l + 1))
	{
		if (p->ins.param[1] & T_REG
		|| (p->ins.param[1] & T_DIR && !p->ins.label_size))
			*p->l += p->ins.param[1] & T_REG ? 1 : 4;
		else
			*p->l += 2;
		if (p->ins.nb_param > 2 && (p->l[3] = *p->l + 1))
		{
			if (p->ins.param[2] & T_REG
			|| (p->ins.param[2] & T_DIR && !p->ins.label_size))
				*p->l += p->ins.param[2] & T_REG ? 1 : 4;
			else
				*p->l += 2;
		}
	}
	++*p->l;
	(void)core;
	return (ind);
}
