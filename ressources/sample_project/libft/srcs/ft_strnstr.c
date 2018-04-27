/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:32:31 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/11 18:10:34 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i1;
	int		i2;

	if (*s2 == '\0')
		return ((char *)s1);
	i1 = 0;
	while (i1 < (int)n && s1[i1])
	{
		i2 = 0;
		while (i1 + i2 < (int)n && s1[i1 + i2] && s1[i1 + i2] == s2[i2])
		{
			if (!(s2[i2]))
				return ((char *)(s1 + i1));
			i2++;
		}
		if (!(s2[i2]))
			return ((char *)(s1 + i1));
		i1++;
	}
	return (NULL);
}
