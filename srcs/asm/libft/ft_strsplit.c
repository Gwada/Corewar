/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:35:23 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/17 18:05:51 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int     ft_countwords(const char *s, const char c, size_t state)
{
	if (!s || !*s)
		return (0);
	if (*s != c)
	{
		if (!state)
			return (ft_countwords(s + 1, c, 1) + 1);
		return (ft_countwords(s + 1, c, 1));
	}
	return (ft_countwords(s + 1, c, 0));
}

char	**ft_strsplit(char const *s, char c)
{
	int		nbwords;
	int		nbletter;
	char	**words;

	if (!s)
		return (NULL);
	nbwords = ft_countwords(s, c, 0);
	if (!(words = (char**)malloc(sizeof(char*) * nbwords + 1)))
		return (NULL);
	words[nbwords] = NULL;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		nbletter = 0;
		while (*s && *s != c)
		{
			nbletter++;
			s++;
		}
		if (nbletter)
			*words++ = ft_strsub(s - nbletter, 0, nbletter);
	}
	return (words - nbwords);
}
