/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:38:46 by sdjeghba          #+#    #+#             */
/*   Updated: 2018/05/17 15:17:02 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrealloc(char *str, int size)
{
	char *s;

	if (!str)
	{
		s = ft_strnew(size);
		return (s);
	}
	s = ft_strnew(ft_strlen(str) + size);
	ft_strcpy(s, str);
	ft_strdel(&str);
	return (s);
}
