/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:19:55 by brigoux           #+#    #+#             */
/*   Updated: 2016/04/30 19:26:32 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstindex(void *list, int index)
{
	int		current;
	t_list	*elem;

	if (!list)
		return (NULL);
	elem = (t_list *)list;
	current = 0;
	while (elem && current < index)
	{
		elem = elem->next;
		current++;
	}
	return (elem);
}
