/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 00:17:03 by brigoux           #+#    #+#             */
/*   Updated: 2016/06/03 16:18:15 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstrip(char *str)
{
	int		i;

	while (*str && ft_isspace(*str))
		str++;
	i = ft_strlen(str);
	while (i-- && ft_isspace(str[i]))
		continue ;
	return (ft_strndup(str, i + 1));
}
