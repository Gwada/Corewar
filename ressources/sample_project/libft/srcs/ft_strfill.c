/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 20:14:44 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/14 19:47:56 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfill(char *str, char c, size_t len)
{
	int		index;

	index = 0;
	while (index < (int)len)
	{
		str[index] = c;
		index++;
	}
	return (str);
}
