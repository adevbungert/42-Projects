/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:33:40 by abungert          #+#    #+#             */
/*   Updated: 2015/12/20 17:02:59 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

t_lst	*lst_pushback(t_lst **lst, t_lst *new)
{
	t_lst	*cur;

	cur = *lst;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
	return (*lst);
}

t_lst	*create_list_elem(int nb)
{
	t_lst	*new;

	if ((new = (t_lst*)malloc(sizeof(*new))))
	{
		new->nb = nb;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

int		add_to_list(int nb, t_lst **begin)
{
	t_lst	*new;

	if ((new = create_list_elem(nb)) != NULL)
	{
		lst_pushback(begin, new);
		return (1);
	}
	else
		return (0);
}

int		free_list(t_lst **begin)
{
	t_lst	*tmp_cur;

	tmp_cur = *begin;
	while (tmp_cur)
	{
		tmp_cur = tmp_cur->next;
		ft_memdel((void **)begin);
		*begin = tmp_cur;
	}
	return (1);
}
