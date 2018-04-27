/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:06:38 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/11 18:08:45 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ptr;
	int		index;

	index = 0;
	ptr = s1;
	while (*ptr)
		ptr++;
	while (s2[index] && index < (int)n)
	{
		ptr[index] = s2[index];
		index++;
	}
	ptr[index] = '\0';
	return (s1);
}
