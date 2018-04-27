/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 19:53:45 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/15 16:20:01 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinsert(char *s1, char *s2, int index)
{
	char	*str;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	str = ft_strncpy(str, s1, index);
	str = ft_strcat(str, s2);
	str = ft_strcat(str, s1 + index);
	free(s1);
	free(s2);
	return (str);
}
