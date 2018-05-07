/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:44:34 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/06 20:52:19 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

unsigned int	id(unsigned id)
{
	return (id % MEM_SIZE);
}

void			add_data(t_op *dst, t_op *src)
{
	dst->name = src->name;
	dst->nb_param = src->nb_param;
	dst->description = src->description;
	dst->nb_cycles = src->nb_cycles;
	dst->op_code = src->op_code;
	dst->ocp = src->ocp;
	dst->label_size = src->label_size;
}

int				read_instruct(t_core *c, t_process *p)
{
	ft_printf("{bold}{blue}IN\tREAD_INSTRUCT{eoc}\n");//

	*p->reg = id(*p->reg + 1);
	if (c->ram[*p->reg - 1] <= INST_NUMBERS)
	{
		c->ft[c->ram[*p->reg - 1]](&c->ram[*p->reg], p);




		ft_printf("{green}carry\t= %u\n", p->carry);//
		ft_printf("{green}id_player = %u\n\n{eoc}", p->reg[1]);//
		ft_printf("p->name\t\t= {green}%s{eoc}\n", p->ins.name);//
		ft_printf("p->nb_param\t= {green}%d{eoc}\n", p->ins.nb_param);//
		int i = -1;//
		while (++i < 3)//
		{//
			ft_printf("p->param[%d]\t= {green}%d\t", i + 1, p->ins.param[i]);//
			if (p->ins.param[i])//
			{//
				p->ins.param[i] == T_REG ? ft_printf("T_REG") : 0;//
				p->ins.param[i] == T_DIR ? ft_printf("T_DIR") : 0;//
				p->ins.param[i] == T_IND ? ft_printf("T_IND") : 0;//
			}//
			else//
				ft_printf("{red}NULL");//
			ft_printf("\n{eoc}");//
		}//
		ft_printf("p->op_code\t= {green}%d{eoc}\n", p->ins.op_code);//
		ft_printf("p->nb_cycles\t= {green}%d{eoc}\n", p->ins.nb_cycles);//
		ft_printf("p->description\t= {green}%s{eoc}\n", p->ins.description);//
		ft_printf("p->ocp\t\t= {green}%d{eoc}\n", p->ins.ocp);//
		ft_printf("p->label_size\t= {green}%d{eoc}\n", p->ins.label_size);//

	}
	else//
		ft_printf("Invalid instruct\n");//
	ft_printf("{bold}{blue}END\tREAD_INSTRUCT{eoc}\n\n");//
	return (0);
}
