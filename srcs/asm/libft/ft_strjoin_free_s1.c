/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_s1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 23:54:10 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/03/25 23:58:34 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin_free_s1(char *s1, char *s2)
{
	char	*tmp_s1;

	tmp_s1 = NULL;
	if (s1 && s2)
	{
		tmp_s1 = ft_strnew(ft_strlen(s2) + ft_strlen(s1));
		if (!tmp_s1)
			return (NULL);
		ft_strcpy(tmp_s1, s1);
		ft_strcat(tmp_s1, s2);
		s1 ? ft_strdel(&s1) : 0;
	}
	else if (!s1 && s2)
	{
		tmp_s1 = ft_strdup(s2);
		s1 ? ft_strdel(&s1) : 0;
	}
	return (tmp_s1);
}
