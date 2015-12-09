/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:51:50 by abungert          #+#    #+#             */
/*   Updated: 2015/12/09 11:43:28 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list_gnl	*lst_gnl_new(int fd)
{
	t_list_gnl *link;

	if (!(link = (t_list_gnl *)malloc(sizeof(t_list_gnl))))
		return (NULL);
	link->fd = fd;
	if (!(link->content = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	link->next = NULL;
	return (link);
}

static t_list_gnl	*check_fd(t_list_gnl *first, int fd)
{
	t_list_gnl	*link;

	while (first->next)
	{
		if (first->fd == fd)
			return (first);
		first = first->next;
	}
	if (first->fd == fd)
		return (first);
	else
	{
		link = lst_gnl_new(fd);
		first->next = link;
		return (link);
	}
}

static int			check_line(int fd, t_list_gnl **current_link, char **line)
{
	int			size;
	int			i;

	i = -1;
	size = ft_strlen((*current_link)->content);
	while (size >= 0 && ++i >= 0)
	{
		if ((*current_link)->content[i] == '\n')
		{
			*line = ft_strjoin(*line, ft_strndup((*current_link)->content, i));
			(*current_link)->content = &((*current_link)->content)[i + 1];
			return (1);
		}
		if (((*current_link)->content)[i] == '\0')
		{
			*line = ft_strjoin(*line, (*current_link)->content);
			if (!((*current_link)->content = ft_strnew(BUFF_SIZE + 1)))
				return (-1);
			size = read(fd, (*current_link)->content, BUFF_SIZE);
			if (size == -1 || size == 0)
				break ;
			i = -1;
		}
	}
	return (size);
}

int					get_next_line(int const fd, char **line)
{
	int					ret;
	static t_list_gnl	*first = NULL;
	t_list_gnl			*current_link;

	if (fd < 0 || fd == 1 || fd == 2 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!first)
	{
		first = lst_gnl_new(fd);
		if ((ret = read(fd, first->content, BUFF_SIZE)) == -1)
			return (-1);
		if (ret == 0)
			return (0);
	}
	*line = ft_strnew(1);
	current_link = check_fd(first, fd);
	ret = check_line(fd, &current_link, line);
	if (ret > 0)
		return (1);
	else if (ret == 0)
		return (0);
	else
		return (-1);
}
