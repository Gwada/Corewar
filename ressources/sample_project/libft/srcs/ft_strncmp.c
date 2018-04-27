/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:55:21 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/11 18:09:05 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		index;

	index = 0;
	while (s1[index] && index < (int)n &&
			*((unsigned char *)s1 + index) == *((unsigned char *)s2 + index))
		index++;
	if (index == (int)n)
		index--;
	return (*((unsigned char *)s1 + index) - *((unsigned char *)s2 + index));
}
