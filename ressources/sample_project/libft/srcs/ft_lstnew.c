/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:01:34 by brigoux           #+#    #+#             */
/*   Updated: 2015/12/02 16:12:30 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		list->content = malloc(content_size);
		list->content = ft_memcpy(list->content, content, content_size);
	}
	else
		list->content = NULL;
	list->content_size = (content ? content_size : 0);
	list->next = NULL;
	return (list);
}
