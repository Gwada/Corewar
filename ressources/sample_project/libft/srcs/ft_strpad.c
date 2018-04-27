/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 13:48:09 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/15 18:53:19 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpad(char *str, size_t plen, char pchar, int side)
{
	char	*pad;

	if (!str)
		return (NULL);
	if (ft_strlen(str) >= plen)
		return (str);
	pad = ft_strfill(
			ft_strnew(plen - ft_strlen(str)), pchar, plen - ft_strlen(str));
	if (side > 0)
		return (ft_strjoinfree(str, pad));
	else if (side < 0)
		return (ft_strjoinfree(pad, str));
	else
		return (ft_strinsert(pad, str, (plen - ft_strlen(str)) / 2));
}
