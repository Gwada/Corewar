/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 18:52:44 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/11 18:08:01 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	int		i;
	int		j;

	j = 0;
	while (dst[j] && j < (int)n)
		j++;
	i = 0;
	while ((src[i]) && ((j + i + 1) < (int)n))
	{
		dst[j + i] = src[i];
		++i;
	}
	if (j != (int)n)
		dst[j + i] = '\0';
	return (j + ft_strlen(src));
}
