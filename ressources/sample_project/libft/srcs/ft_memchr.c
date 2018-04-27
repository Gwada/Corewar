/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:00:02 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/11 18:07:10 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		index;

	index = 0;
	while (index < (int)n)
	{
		if (*((char *)s + index) == (char)c)
			return ((void *)(s + index));
		index++;
	}
	return (NULL);
}
