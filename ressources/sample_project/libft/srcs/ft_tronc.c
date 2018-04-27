/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tronc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 20:57:36 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/24 21:57:30 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_tronc(char *str, t_conv *conv, char fts)
{
	char	*s;
	int		len;

	len = ft_strlen(str);
	if (ft_strcount("xX", fts))
	{
		if (((!conv->l && !conv->h) || conv->l == 1) && ft_strlen(str) > 8)
			s = ft_strdup(str + ft_strlen(str) - 8);
		else if (conv->h == 1 && ft_strlen(str) > 4)
			s = ft_strdup(str + ft_strlen(str) - 4);
		else if (conv->h == 2 && ft_strlen(str) > 2)
			s = ft_strdup(str + ft_strlen(str) - 2);
		else
			s = ft_strdup(str);
	}
	else
		s = ft_strdup(str);
	if (ft_strcount(s, '0') == (int)ft_strlen(s))
		ft_strfreedef(&s, ft_strdup("0"));
	free(str);
	return (s);
}
