/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 17:52:52 by dlavaury          #+#    #+#             */
/*   Updated: 2018/06/13 15:27:29 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

unsigned int	reg_(const unsigned char oct, unsigned char opt)
{
	if (opt == EITH && !(oct & EITH) && oct & SETH)
		return (T_REG);
	else if (opt == SITH && !(oct & SITH) && oct & FITH)
		return (T_REG);
	else if (opt == FOTH && !(oct & FOTH) && oct & TRD)
		return (T_REG);
	return (0);
}

unsigned int	ind_(const unsigned char oct, unsigned char opt)
{
	if (opt == EITH && oct & EITH && oct & SETH)
		return (T_IND);
	else if (opt == SITH && oct & SITH && oct & FITH)
		return (T_IND);
	else if (opt == FOTH && oct & FOTH && oct & TRD)
		return (T_IND);
	return (0);
}

unsigned int	dir_(const unsigned char oct, unsigned char opt)
{
	if (opt == EITH && !(oct & SETH) && oct & EITH)
		return (T_DIR);
	if (opt == SITH && !(oct & FITH) && oct & SITH)
		return (T_DIR);
	if (opt == FOTH && !(oct & TRD) && oct & FOTH)
		return (T_DIR);
	return (0);
}

unsigned int	abs_(const unsigned char oct, unsigned char opt)
{
	if (opt == EITH)
		return ((oct & EITH) || (oct & SETH));
	if (opt == SITH)
		return ((oct & SITH) || (oct & FITH));
	if (opt == FOTH)
		return ((oct & FOTH) || (oct & TRD));
	if (opt == SND)
		return ((oct & SND) || (oct & FST));
	return (1);
}
