/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 20:13:58 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/09 17:14:43 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		index;

	if (!s1 || !s2)
		return (1);
	index = 0;
	while (s1[index] == s2[index] && s1[index])
		index++;
	return (s1[index] == s2[index]);
}
