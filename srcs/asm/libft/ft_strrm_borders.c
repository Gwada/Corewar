/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrm_borders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 23:25:40 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/05/06 17:28:22 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strrm_borders(char *str)
{
	int     i;

	if (!str)
		return (NULL);
	while (*str && ft_isblank(*str))
		str++;
	i = ft_strlen(str);
	while (i-- && ft_isblank(str[i]))
		continue;
	return (ft_strncpy(ft_strnew(i + 1), str, i + 1));
}
