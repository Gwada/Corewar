/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 19:29:55 by brigoux           #+#    #+#             */
/*   Updated: 2016/01/24 19:04:58 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int		index;

	index = -1;
	while (++index < (int)n)
	{
		*((unsigned char *)dst + index) = *((unsigned char *)src + index);
		if (*((unsigned char *)src + index) == (unsigned char)c)
			return (dst + index + 1);
	}
	*((char *)dst + index) = '\0';
	return (NULL);
}
