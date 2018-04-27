/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 18:19:46 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/09 17:13:11 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		index;

	if (!s || !f || !(str = ft_strdup(s)))
		return (NULL);
	index = 0;
	while (str[index] && ++index)
		str[index - 1] = f(index - 1, str[index - 1]);
	return (str);
}
