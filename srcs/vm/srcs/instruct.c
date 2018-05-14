/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:44:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/14 21:41:05 by dlavaury         ###   ########.fr       */
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
	ft_printf("{bold}{blue}IN\tREAD_INSTRUCT{eoc}\n");//
	unsigned char	opc;

	if (opc_c((opc = c->ram[id(p->pc)])))
	{
		add_data(&p->ins, &g_op_tab[opc - 1]);

		ft_printf("instruct: opc = %p ind = %u\n", opc, p->pc);//
		ft_printf("{green}carry\t= %u\n", p->carry);//
		ft_printf("{green}id_player = %u\n\n{eoc}", *p->reg);//
		ft_printf("p->name\t\t= {green}%s{eoc}\n", p->ins.name);//
		ft_printf("p->nb_param\t= {green}%d{eoc}\n", p->ins.nb_param);//
		ft_printf("p->op_code\t= {green}%d{eoc}\n", p->ins.op_code);//
		ft_printf("p->nb_cycles\t= {green}%d{eoc}\n", p->ins.nb_cycles);//
		ft_printf("p->description\t= {green}%s{eoc}\n", p->ins.description);//
		ft_printf("p->ocp\t\t= {green}%d{eoc}\n", p->ins.ocp);//
		ft_printf("p->label_size\t= {green}%d{eoc}\n", p->ins.label_size);//
		ft_printf("{bold}{blue}1 END\tREAD_INSTRUCT{eoc}\n\n");//
		return (1);
	}
	p->ins.name = NULL;
	p->ins.nb_cycles = 0;
	ft_printf("Invalid instruct: opc = %p ind = %u\n", opc, p->pc);//
	ft_printf("{bold}{blue}2 END\tREAD_INSTRUCT{eoc}\n\n");//
	return (0);
}

unsigned int		get_ind(t_core *core, t_process *process, unsigned int ind)
{
	ft_printf("direct 2\n");
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	while (i < 2)
		n = (n << 8) | (core->ram[id(process->pc + ind + i++)]);
	return (n);
}
