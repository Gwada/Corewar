/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:09:49 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/09 17:10:48 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*ptr;

	if (!s || !f)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (NULL);
	ptr = str;
	while (*ptr && ptr++)
		*(ptr - 1) = f(*(ptr - 1));
	return (str);
}
