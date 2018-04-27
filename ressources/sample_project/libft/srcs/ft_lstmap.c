/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:58:00 by brigoux           #+#    #+#             */
/*   Updated: 2015/12/02 16:14:57 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	if (!lst || !f || !(tmp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	tmp = f(lst);
	if (lst->next)
		tmp->next = ft_lstmap(lst->next, f);
	return (tmp);
}
