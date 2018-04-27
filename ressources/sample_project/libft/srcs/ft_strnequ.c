/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 21:04:30 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/09 17:14:38 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		index;

	if (!s1 || !s2 || n == 0)
		return (1);
	index = 0;
	while (s1[index] == s2[index] && s1[index] && index < (int)n)
		index++;
	if (index == (int)n)
		index--;
	return (s1[index] == s2[index]);
}
