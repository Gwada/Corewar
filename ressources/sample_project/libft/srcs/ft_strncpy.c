/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:45:22 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/11 18:10:05 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	int	index;

	index = 0;
	while (src[index] && index < (int)n)
	{
		dst[index] = src[index];
		index++;
	}
	ft_bzero(dst + index, n - index);
	return (dst);
}
