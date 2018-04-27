/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 19:13:09 by brigoux           #+#    #+#             */
/*   Updated: 2016/02/02 20:07:07 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbwords(char const *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] == c)
			++i;
		if (s[i])
			++nb;
		while (s[i] && s[i] != c)
			++i;
	}
	return (nb);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (!s || !(tab = (char **)malloc(sizeof(char *) * (nbwords(s, c) + 1))))
		return (NULL);
	j = 0;
	k = 0;
	while (s[k])
	{
		while (s[k] == c)
			++k;
		i = k;
		while (s[k] && s[k] != c)
			++k;
		if (k > i)
		{
			tab[j] = ft_strsub(s + i, 0, k - i);
			++j;
		}
	}
	tab[j] = NULL;
	return (tab);
}
