/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 17:09:48 by sdjeghba          #+#    #+#             */
/*   Updated: 2018/05/13 17:26:51 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_free_tab(char **tab)
{
	int		i;

	i = -1;
	if (!(tab))
		return ;
	while (tab[++i])
		ft_memdel((void**)&(tab[i]));
	free(tab);
}
