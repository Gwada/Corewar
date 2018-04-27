/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brigoux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:33:56 by brigoux           #+#    #+#             */
/*   Updated: 2016/06/02 01:03:16 by brigoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file		*get_file(t_file *file, int fd)
{
	t_file		*new;
	int			len;

	len = 0;
	while (file->next && file->fd != fd)
	{
		file = file->next;
		len++;
	}
	if (fd == 0 && len == 0 && !file->remain)
		file->remain = ft_strnew(0);
	if (file->fd == fd)
		return (file);
	new = (t_file *)malloc(sizeof(t_file));
	new->next = NULL;
	new->fd = fd;
	new->eof = 0;
	new->remain = ft_strnew(0);
	file->next = new;
	return (new);
}

int			del_file(t_file *flist, int fd, int ret)
{
	t_file		*prev;

	if (fd == 0)
		return (ret);
	while (flist->fd != fd)
	{
		prev = flist;
		flist = flist->next;
	}
	prev->next = flist->next;
	if (flist->remain != NULL)
		free(flist->remain);
	free(flist);
	return (ret);
}

char		*extract_part(char **str, char c, int fd)
{
	char	*ptr;
	char	*tmp;
	int		len;
	int		index;

	len = 0;
	while ((*str)[len] != '\0' && (*str)[len] != c)
		len++;
	if (len == 0 && (**str == '\0' || (fd == 0 && ft_strstr(*str, "\n\n"))))
	{
		ptr = ft_strnew(0);
		free(*str);
		*str = NULL;
		return (ptr);
	}
	ptr = (char *)malloc(sizeof(char) + (len + 1));
	index = -1;
	while (++index < len)
		ptr[index] = (*str)[index];
	ptr[index] = '\0';
	tmp = ft_strdup(*str + len + (*(*str + len) == '\n'));
	free(*str);
	*str = tmp;
	return (ptr);
}

int			get_next_line(int const fd, char **line)
{
	static t_file		flist;
	t_file				*file;
	char				*buff;
	int					ret;

	if (!line)
		return (-1);
	file = get_file(&flist, fd);
	if (file->eof || ft_strchr(file->remain, '\n'))
	{
		*line = extract_part(&file->remain, '\n', fd);
		if (!file->remain)
			return (del_file(&flist, file->fd, 0));
		return (1);
	}
	buff = ft_strnew(BUFF_SIZE);
	if ((ret = read(file->fd, buff, BUFF_SIZE)) == -1)
		return (del_file(&flist, file->fd, -1));
	if ((ret < BUFF_SIZE && fd) || (!fd && ret == 0))
		file->eof = 1;
	file->remain = ft_strjoinfree(file->remain, buff);
	return (get_next_line(fd, line));
}
