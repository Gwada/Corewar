/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 00:41:52 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/05/17 15:44:33 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

char		*ft_char_replace(char *str, char old, char new)
{
	char	*ptr;

	ptr = str;
	while (*str)
	{
		if (*str == old)
			*str = new;
		str++;
	}
	return (ptr);
}
