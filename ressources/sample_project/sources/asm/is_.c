/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 05:38:25 by brigoux           #+#    #+#             */
/*   Updated: 2016/07/24 18:51:08 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_dir(char *param)
{
	if (*param == DIRECT_CHAR && (is_ind(param + 1) || is_lab(param + 1)))
		return (T_DIR);
	return (0);
}

int		is_ind(char *param)
{
	if (ft_strisdigit(param + (*param == '-')))
		return (T_IND);
	return (0);
}

int		is_lab(char *param)
{
	if (*param != LABEL_CHAR)
		return (0);
	param++;
	while (*param && ft_strcount(LABEL_CHARS, *param))
		param++;
	if (!*param)
		return (T_IND);
	return (0);
}

int		is_reg(char *param)
{
	if (*param == 'r' && ft_strisdigit(param + 1) &&
			ft_inrange(ft_atoi(param + 1), 1, REG_NUMBER + 1))
		return (T_REG);
	return (0);
}
