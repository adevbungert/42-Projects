/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst1new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:16:38 by abungert          #+#    #+#             */
/*   Updated: 2015/12/08 12:11:00 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

t_list_gnl		    *ft_lst_gnl_new(int fd)
{
	t_list_gnl      *my_list;

	if (!(my_list = (t_list_gnl *)malloc(sizeof(*my_list))))
		return (NULL);
    my_list->fd = fd;
    if (!(my_list->content = ft_strnew(BUFF_SIZE + 1)))
        return (NULL);
	my_list->next = NULL;
	return (my_list);
}
