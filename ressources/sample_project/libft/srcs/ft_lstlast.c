/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 13:02:10 by brigoux           #+#    #+#             */
/*   Updated: 2016/04/21 13:06:08 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstlast(void *list)
{
	t_list		*elem;

	elem = list;
	while (elem->next)
		elem = elem->next;
	return (elem);
}
