/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 11:40:03 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/18 12:15:21 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

t_list		*get_t_fd(t_list **begi_all, size_t fd)
{
	t_list		*cur_all;
	t_list		*new;

	cur_all = *begi_all;
	if (cur_all)
	{
		while (cur_all->next)
		{
			if (cur_all->content_size == fd)
				return (cur_all);
			cur_all = cur_all->next;
		}
		if (cur_all->content_size == fd)
			return (cur_all);
	}
	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	new->content_size = fd;
	new->next = NULL;
	new->content = NULL;
	if (*begi_all)
		return ((cur_all->next = new));
	return ((*begi_all = new));
}

int			sbar(char **content, char *buf, int got_n)
{
	char *s;

	if (got_n >= 0)
	{
		if (got_n >= 0 && ft_strlen(buf) > 0)
		{
			s = *content;
			*content = ft_strdup(buf);
			ft_memdel((void**)&s);
			return (1);
		}
		else
			ft_memdel((void**)&(*content));
	}
	return (0);
}

int			read_put(char *b, int *rd, int *g, char **l)
{
	while (b[++(*g)] && b[*g] != '\n')
		;
	*g = ((b[*g] == '\0' && *rd == BUFF_SIZE)) ? -1 : *g;
	if (((*g == 0 || *rd == 0) && BUFF_SIZE == 1))
	{
		if (*l)
			*l[0] = (*l[0] == '\n') ? '\0' : *l[0];
		else
			*l = ft_strnew(1);
		return ((*rd > 0 || ft_strlen(*l) > 0) ? 1 : 0);
	}
	else if (*l && *l[0] == '\n' && *rd == 1 &&
			BUFF_SIZE == 1 && (*l[0] = '\0'))
		return (1);
	return (-1);
}

int			putbuffer(char **c, char **l, int *fd)
{
	int		rd;
	int		g;
	char	b[BUFF_SIZE + 1];
	char	*s;
	int		r;

	g = -1;
	while (g <= 0)
	{
		bzero(b, BUFF_SIZE + 1);
		if ((rd = read(*fd, b, BUFF_SIZE)) >= 0)
			b[rd] = '\0';
		else
			return (rd);
		if ((r = read_put(b, &rd, &g, l)) != -1)
			return (r);
		if (((b[g] = (b[g] != '\0') ? '\0' : b[g]) || 1) && !(*l) && rd > 0)
			*l = ft_strdup(b);
		else if (((s = *l) || 1) && rd != 0 &&
				(*l = ft_strjoin(s, b)))
			ft_memdel((void **)&s);
		if (((sbar(c, &b[g + 1], g)) || rd <= 0) && ((*fd = rd) || 1))
			return ((rd <= 0 && (!*l || *l[0] == '\0')) ? 0 : 1);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static t_list	*begin_all = NULL;
	t_list			*begin;
	int				rd;
	char			*s;

	if (fd < 0 || !(line))
		return (-1);
	*line = NULL;
	begin = get_t_fd(&begin_all, (size_t)fd);
	rd = begin && begin->content && ft_strchr(begin->content, '\n') ?
		ft_strchr(begin->content, '\n') - (char*)(begin->content) + 1 : 0;
	if (begin->content && ((rd && ((begin->content[rd - 1]) = '\0') == '\0')))
	{
		*line = ft_strdup(begin->content);
		s = begin->content;
		begin->content = ft_strdup(begin->content + rd);
		ft_memdel((void **)&s);
		return (1);
	}
	*line = (begin->content) ? ft_strdup(begin->content) : *line;
	if ((rd = (putbuffer((char **)&(begin->content), line, &fd))) == 0)
		ft_memdel((void **)line);
	if (rd == 1 && fd == 0 && (begin->content && ft_strlen(begin->content) > 0))
		ft_poplist(&begin_all, begin);
	return (rd);
}
