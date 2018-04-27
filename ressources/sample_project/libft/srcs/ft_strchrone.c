/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:20:44 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/24 17:53:28 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrone(char *str, char *chrlst)
{
	while (*str && !ft_strcount(chrlst, *str))
		str++;
	return (str);
}
