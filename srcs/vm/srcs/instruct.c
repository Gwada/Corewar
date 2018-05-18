/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:44:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/17 16:21:48 by dlavaury         ###   ########.fr       */
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
/*	ft_printf("\t{bold}{blue}IN\tREAD_INSTRUCT");//
	ft_printf("\tOPC: %p P->C: %u{eoc}\n", c->ram[id(p->pc)], p->pc);//
	ft_printf("\t\t{green}carry\t= %u\n", p->carry);//
	ft_printf("\t\tid_player = %u\n\n{eoc}", *p->reg);//
*/
	unsigned char	opc;

	if (opc_c((opc = c->ram[id(p->pc)]) - 1))
	{
		add_data(&p->ins, &g_op_tab[opc - 1]);
/*
		ft_printf("\t\tp->name\t\t= {green}%s{eoc}\n", p->ins.name);//
		ft_printf("\t\tp->nb_param\t= {green}%d{eoc}\n", p->ins.nb_param);//
		ft_printf("\t\tp->op_code\t= {green}%d{eoc}\n", p->ins.op_code);//
		ft_printf("\t\tp->nb_cycles\t= {green}%d{eoc}\n", p->ins.nb_cycles);//
		ft_printf("\t\tp->description\t= {green}%s{eoc}\n", p->ins.description);//
		ft_printf("\t\tp->ocp\t\t= {green}%d{eoc}\n", p->ins.ocp);//
		ft_printf("\t\tp->label_size\t= {green}%d{eoc}\n", p->ins.label_size);//
		ft_printf("\t{bold}{blue}1 END\tREAD_INSTRUCT{eoc}\n");//
*/
		return (1);
	}
	p->ins.name = NULL;
	p->ins.nb_cycles = 0;

//	ft_printf("\t{bold}{blue}2 END\tREAD_INSTRUCT{eoc}\n");//

	return (0);
}

int					get_ind(t_core *core, t_process *process, int ind)
{
//	ft_printf("\t\t{red}direct (short){eoc}\n");//
	unsigned int	i;
	short			n;

	i = 0;
	n = 0;
	while (i < 2)
		n = (n << 8) | (core->ram[id(process->pc + ind + i++)]);
	(void)process;
	return (n);
}

int					get_len(t_core *core, t_process *p, int ind)
{
//	ft_printf("{bold}{underline}{black}\t\tIN\tGET_LEN{eoc}\n");//

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
	(void)ind;

/*	int i = -1;//
	ft_printf("\t\t\t");//
	while (++i <= p->ins.nb_param)//
		ft_printf("p->l[%d]: %u\t", i, p->l[i]);//
	ft_printf("\n{bold}{underline}{black}\t\tEND\tGET_LEN{eoc}\n");//
*/
	return (0);
}
