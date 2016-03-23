/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:35:24 by abungert          #+#    #+#             */
/*   Updated: 2016/03/21 17:38:09 by abungert         ###   ########.fr       */
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

void			print_with_effect(t_select *params, t_lst *elem)
{
	t_lst		*current;

	current = get_current_elem(params);
	if (elem->selected)
		fputs("mr");
	if (elem == current)
		fputs("us");
	ft_printf("%s\n", elem->value);
	fputs("me");
	fputs("ue");
}
