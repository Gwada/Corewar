/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:21:37 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/05/05 17:28:36 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, int len)
{
	char	*tmp_s1;

	tmp_s1 = NULL;
	if (s1 && s2 && len)
	{
		tmp_s1 = ft_strnew(len + ft_strlen(s2));
		if (!tmp_s1)
			return (NULL);
		ft_strncpy(tmp_s1, s1, len);
		ft_strcat(tmp_s1, s2);
	}
	else if (!s1 && s2)
		tmp_s1 = ft_strdup(s2);
	return (tmp_s1);
}
