/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:44:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/11 17:43:37 by dlavaury         ###   ########.fr       */
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

void				exec_instruct(t_core *c, t_process *p, unsigned char opc)
{
	ft_printf("{bold}{magenta}IN\tEXEC_INSTRUCT{eoc}\n");//
	ft_printf("{red}{underline}go %s function{eoc}\n\n", p->ins.name);//


	if (c->ft[opc](&c->ram[id(*p->reg + 1)], p))
		c->ex[opc](c, p);

	*p->reg = id(*p->reg + 1);

	read_instruct(c, p);

	ft_print_mem(c->ram, MEM_SIZE, 64, 0);//
	ft_printf("{bold}{magenta}END\tEXEC_INSTRUCT{eoc}\n\n");//
}

void				read_instruct(t_core *c, t_process *p)
{
	ft_printf("{bold}{blue}IN\tREAD_INSTRUCT{eoc}\n");//
	unsigned char	opc;

	if (opc_c((opc = c->ram[id(*p->reg)])))
	{
		add_data(&p->ins, &g_op_tab[opc - 1]);

		ft_printf("{green}carry\t= %u\n", p->carry);//
		ft_printf("{green}id_player = %u\n\n{eoc}", p->reg[1]);//
		ft_printf("p->name\t\t= {green}%s{eoc}\n", p->ins.name);//
		ft_printf("p->nb_param\t= {green}%d{eoc}\n", p->ins.nb_param);//
		ft_printf("p->op_code\t= {green}%d{eoc}\n", p->ins.op_code);//
		ft_printf("p->nb_cycles\t= {green}%d{eoc}\n", p->ins.nb_cycles);//
		ft_printf("p->description\t= {green}%s{eoc}\n", p->ins.description);//
		ft_printf("p->ocp\t\t= {green}%d{eoc}\n", p->ins.ocp);//
		ft_printf("p->label_size\t= {green}%d{eoc}\n", p->ins.label_size);//

	}
	else//
		ft_printf("Invalid instruct\n");//
	ft_printf("{bold}{blue}END\tREAD_INSTRUCT{eoc}\n\n");//
}
