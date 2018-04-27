/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 20:14:27 by brigoux           #+#    #+#             */
/*   Updated: 2016/06/05 18:19:52 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, char old, char new)
{
	char	*ptr;

	ptr = str;
	while (*str)
	{
		if (*str == old)
			*str = new;
		str++;
	}
	return (ptr);
}
