/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:19:06 by abungert          #+#    #+#             */
/*   Updated: 2015/12/07 21:24:16 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_list1			*check_fd(t_list1 *tmp, int fd)
{
	t_list1		*new_link;

	while (tmp->next)
	{
		if (tmp->n_fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp->n_fd == fd)
		return (tmp);
	new_link = ft_lst1new(fd);
	tmp->next = new_link;
	return (new_link);
}

int	static		check_eol_lst(t_list1 **lst, char **line)
{
	int		i;
	t_list1	*tmp;

	i = 0;
	tmp = *lst;
	if (!(tmp->content))
		return (0);
	while (tmp->content[i])
	{
		if (tmp->content[i] == '\n' || tmp->content[i] == '\0')
		{
			if (!(*line = ft_strsub(tmp->content, 0, i)))
				return (-1);
			if (tmp->content[i] == '\0')
				return (0);
			if(!(((*lst)->content) = ft_strdup(&(tmp->content[i + 1]))))
				return (-1);
			return (1);
		}
		i++;
	}
	return (0);
}

int static		check_eol_buf(t_list1 **lst, char **line, char *BUF)
{
	int		i;
	char	*tmp;

	i = 0;
	while (BUF[i])
	{
		if (BUF[i] == '\n' || BUF[i] == '\0')
		{
			if (*lst)
			{
				tmp = ft_strsub(BUF, 0, i);
				if ((*lst)->content)
				{
					if(!(*line = ft_strjoin((*lst)->content, tmp)))
						return (-1);
				}
				else
				{
					if(!(*line = ft_strdup(tmp)))
						return (-1);
				}
			}
			if (BUF[i + 1])
			{
				if (!((*lst)->content = ft_strdup(&(BUF[i + 1]))))
					return (-1);
			}
			else
				ft_strdel(&(*lst)->content);
			return (1);
		}
		i++;
	}
	if (i > 0 && (*lst)->content)
	{
		if (!((*lst)->content = ft_strjoin((*lst)->content, BUF)))
			return (-1);
	}
	else if (i > 0)
	{
		if (!((*lst)->content = ft_strdup(BUF)))
			return (-1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	t_list1 static	*lst = NULL;
	char			*BUF;
	int				ret;

	if (!lst)
		lst = ft_lst1new(fd);
	else
		lst = check_fd(lst, fd);
	if (!(check_eol_lst(&(lst), line)))
	{
		if (!(BUF = (char *)malloc(sizeof(char) * BUF_SIZE + 1)))
			return (-1);
		while (!(check_eol_buf(&(lst), line, BUF)))
		{
			ret = read(fd, BUF, BUF_SIZE);
			if (ret == 0)
				if (!(check_eol_lst(&(lst), line)))
					return (0);
			if (ret == -1)
				return (-1);
			BUF[ret] = '\0';
		}
		free(BUF);
		BUF = NULL;
	}
	//if (ft_strlen(lst->content) != 0)
	//	return (1);
	return (1);
}
