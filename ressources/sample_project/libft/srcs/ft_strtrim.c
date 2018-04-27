/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 19:12:34 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/01 20:01:34 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s1;
	char	*s2;

	if (!s)
		return (NULL);
	while (ft_strcount(" \n\t", *s))
		s++;
	if (!(s1 = ft_strdup(s)))
		return (NULL);
	s2 = s1;
	while (*s2)
		s2++;
	if (*s1)
		s2--;
	while (ft_strcount(" \n\t", *s2) && *s2)
	{
		*s2 = '\0';
		s2--;
	}
	if (!(s2 = ft_strdup(s1)))
		return (NULL);
	free(s1);
	return (s2);
}
