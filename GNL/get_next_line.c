/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:14:13 by abungert          #+#    #+#             */
/*   Updated: 2015/12/30 15:00:24 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list_gnl	*lst_gnl_new(int fd)
{
	t_list_gnl		*link;
	int				ret;

	if (!(link = (t_list_gnl *)malloc(sizeof(t_list_gnl))))
		return (NULL);
	link->fd = fd;
	if (!(link->str = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	ret = read(fd, link->str, BUFF_SIZE);
	if (ret == -1)
		return (NULL);
	link->next = NULL;
	return (link);
}

static t_list_gnl	*check_fd(t_list_gnl *first, int fd)
{
	t_list_gnl	*link;

	while (first)
	{
		if (first->fd == fd)
			return (first);
		if (!(first->next))
			break ;
		first = first->next;
	}
	if (!(link = lst_gnl_new(fd)))
		return (NULL);
	first->next = link;
	return (link);
}

static void			put_in_line(t_list_gnl *link, char **line, char *end)
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;

	tmp1 = *line;
	tmp2 = ft_strsub(link->str, 0, end - link->str);
	tmp3 = ft_strsub(link->str, (end - link->str) + 1, ft_strlen(link->str));
	*line = ft_strjoin(*line, tmp2);
	ft_memdel((void **)&tmp1);
	ft_memdel((void **)&tmp2);
	ft_memdel((void **)&(link->str));
	link->str = tmp3;
}

static int			check_line(int fd, t_list_gnl *link, char **line)
{
	int			size;
	int			len;
	char		*end;
	char		*tmp1;

	size = 1;
	while (size > 0)
	{
		if ((end = ft_strchr(link->str, '\n')))
		{
			put_in_line(link, line, end);
			return (1);
		}
		tmp1 = *line;
		*line = ft_strjoin(*line, link->str);
		ft_memdel((void **)&tmp1);
		len = ft_strlen(link->str);
		ft_memdel((void **)&(link->str));
		if (!(link->str = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
		size = read(fd, link->str, BUFF_SIZE);
		if (!len && !size)
			return (0);
	}
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	int					ret;
	static t_list_gnl	*first;
	t_list_gnl			*current_link;

	if (fd < 0 || fd == 1 || fd == 2 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!first)
	{
		if (!(first = lst_gnl_new(fd)))
			return (-1);
	}
	*line = ft_strnew(1);
	if (!(current_link = check_fd(first, fd)))
		return (-1);
	ret = check_line(fd, current_link, line);
	if (ret > 0)
		return (1);
	else if (ret == 0)
		return (0);
	else
		return (-1);
}
