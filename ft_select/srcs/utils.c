/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebungert <antoinebungert@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:35:24 by abungert          #+#    #+#             */
/*   Updated: 2016/03/23 12:00:02 by antoinebungert   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

static int		myoutc(int c)
{
	return(write(2, &c, 1));
}

void			fputs(char *res)
{
	tputs(tgetstr(res, NULL), 1, myoutc);
}

void			fmove(t_select *params)
{
	tputs(tgoto(tgetstr("cm", NULL), 0, params->curs_y), 1, myoutc);
}

t_lst			*get_current_elem(t_select *params)
{
	t_lst		*current;
	t_lst		*tmp;
	int			i;

	tmp = params->list;
	i = 0;
	while (i < params->curs_y)
	{
		i++;
		tmp = tmp->next;
	}
	current = tmp;
	return (current);
}
