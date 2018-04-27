/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 22:43:13 by brigoux           #+#    #+#             */
/*   Updated: 2016/03/05 22:04:06 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		end;
	char	tmp;

	i = 0;
	end = ft_strlen(str) - 1;
	while (i < end)
	{
		tmp = str[i];
		str[i] = str[end];
		str[end] = tmp;
		i++;
		end--;
	}
	return (str);
}
