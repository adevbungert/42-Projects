/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:54:05 by abungert          #+#    #+#             */
/*   Updated: 2016/03/22 13:55:25 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

void		press_arrow(t_select *params, char key)
{
	if (key == 66)
	{
		if (params->curs_y == params->size_list)
			params->curs_y = 1;
		else
			params->curs_y++;
	}
	else if (key == 65)
	{
		if (params->curs_y == 1)
			params->curs_y = params->size_list;
		else
			params->curs_y--;
	}
	print_lst(params);
}

void		press_enter(t_select *params)
{
	restore_term();
	return_selected(params);
	exit(0);
}

void		press_space(t_select *params)
{
	char	key;
	t_lst	*current;

	key = 66;
	current = get_current_elem(params);
	current->selected = current->selected ? 0 : 1;
	press_arrow(params, key);
}

void		press_delete(t_select *params)
{
	t_lst	*current;
	t_lst	*prev;
	t_lst	*next;

	current = get_current_elem(params);
	prev = current->prev;
	next = current->next;
	ft_memdel((void **)&current);
	prev->next = next;
	next->prev = prev;
	print_lst(params);
}
