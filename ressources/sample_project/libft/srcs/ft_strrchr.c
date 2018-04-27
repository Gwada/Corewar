/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:10:04 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/01 18:50:26 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*ptr;

	ptr = s + ft_strlen(s) + 1;
	while (ptr-- != s)
		if (*ptr == c)
			return ((char *)ptr);
	return (NULL);
}
