/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 22:12:23 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/05/13 22:14:24 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/asm.h"

int			is_reg(char *param)
{
	if (*param == 'r' && ft_strisdigit(param + 1) &&
			ft_intrange(ft_atoi(param + 1), 1, REG_NUMBER))
		return (T_REG);
	return (0);
}

int			is_dir(char *param)
{
	if (*param == DIRECT_CHAR && (is_lab(param + 1) || is_ind(param + 1)))
		return(T_DIR);
	return (0);
}

int			is_ind(char *param)
{
	if (*param == '-')
		param++;
	if (ft_strisdigit(param))
		return (T_IND);
	return (0);
}

int			is_lab(char *param)
{
	if (*param != LABEL_CHAR)
		return (0);
	param++;
	while (*param && ft_count_char(LABEL_CHARS, *param))
		param++;
	if (!*param)
		return (T_IND);
	return (0);
}
