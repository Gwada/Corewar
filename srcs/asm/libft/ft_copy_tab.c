/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 17:25:21 by sdjeghba          #+#    #+#             */
/*   Updated: 2018/05/09 12:32:51 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		**ft_copy_tab(char **tab)
{
	char	**array;
	int		i;
	int		j;

	array = NULL;
	i = 0;
	j = 0;
	if (!(array = malloc(sizeof(char *) * ft_tablen(tab) + 1)))
		return (NULL);
	while (tab[i])
	{
		if (!tab[i])
			i++;
		array[j] = ft_strdup(tab[i]);
		i++;
		j++;
	}
	array[j] = NULL;
	return (array);
}
