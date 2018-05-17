/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsortbyname.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 21:11:23 by salemdje          #+#    #+#             */
/*   Updated: 2017/09/13 13:33:28 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	ft_lstswap(t_list *dest, t_list *src)
{
	dest->content = src->content;
	dest->content_size = src->content_size;
}

void		ft_lstsortbyname(t_list **list)
{
	t_list	*tmp;
	t_list	swap;
	int		lstlen;
	int		i;

	i = 0;
	lstlen = ft_lstlen(list);
	while (i++ < lstlen)
	{
		tmp = *list;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->content, tmp->next->content) > 0)
			{
				ft_lstswap(&swap, tmp->next);
				ft_lstswap(tmp->next, tmp);
				ft_lstswap(tmp, &swap);
			}
			tmp = tmp->next;
		}
	}
}
