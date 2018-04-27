/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:17:59 by brigoux           #+#    #+#             */
/*   Updated: 2015/11/26 18:27:36 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i1;
	int		i2;

	i1 = 0;
	while (s1[i1])
	{
		i2 = 0;
		while (s2[i2] && s1[i1 + i2] == s2[i2])
			i2++;
		if (!(s2[i2]))
			return ((char *)s1 + i1);
		i1++;
	}
	if (*s2 == '\0')
		return ((char *)s1);
	return (NULL);
}
