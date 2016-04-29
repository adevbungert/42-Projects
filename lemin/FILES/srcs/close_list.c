/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 09:47:52 by abungert          #+#    #+#             */
/*   Updated: 2016/04/29 11:54:15 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_close			*add_to_close(t_close *close_list, t_rooms *room)
{
	t_close		*new_close;
	t_close		*tmp;

	tmp = close_list;
	if (!(new_close = (t_close*)ft_memalloc(sizeof(t_close))))
		return (NULL);
	new_close->room = room;
	new_close->next = NULL;
	if (!close_list)
		close_list = new_close;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_close;
	}
	return (close_list);
}

int				is_in_close(t_close *close_list, t_rooms *connection)
{
	t_close		*tmp;

	tmp = close_list;
	while (tmp)
	{
		if (tmp->room == connection)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
