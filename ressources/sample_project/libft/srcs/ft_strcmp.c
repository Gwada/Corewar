/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 18:47:34 by brigoux           #+#    #+#             */
/*   Updated: 2016/04/22 19:13:02 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *((unsigned char *)s1) == *((unsigned char *)s2))
		s1++ && s2++;
	return (*(unsigned char *)s1) - *((unsigned char *)s2);
}
