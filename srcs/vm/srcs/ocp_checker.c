/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 17:52:52 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/06 20:59:06 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "../../libft/includes/ft_printf.h"

int		_reg(const unsigned char oct, unsigned char opt)
{
	if (opt == EITH && !(oct & EITH) && oct & SETH)
		return (T_REG);
	if (opt == SITH && !(oct & SITH) && oct & FITH)
		return (T_REG);
	if (opt == FOTH && !(oct & FOTH) && oct & TRD)
		return (T_REG);
	return (0);
}

int		_ind(const unsigned char oct, unsigned char opt)
{
	if (opt == EITH && oct & EITH && oct & SETH)
		return (T_IND);
	if (opt == SITH && oct & SITH && oct & FITH)
		return (T_IND);
	if (opt == FOTH && oct & FOTH && oct & TRD)
		return (T_IND);
	return (0);
}

int		_dir(const unsigned char oct, unsigned char opt)
{
	if (opt == EITH && !(oct & SETH) && oct & EITH)
		return (T_DIR);
	if (opt == SITH && !(oct & FITH) && oct & SITH)
		return (T_DIR);
	if  (opt == FOTH && !(oct & TRD) && oct & FOTH)
		return (T_DIR);
	return (0);
}

int		_abs(const unsigned char oct)
{
	return ((oct & SND) || (oct & FST));
}