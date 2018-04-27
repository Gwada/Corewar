/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 18:23:48 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/02 18:23:49 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (ft_strccpy(ft_strnew(ft_strclen(s, c)), s, c));
}
