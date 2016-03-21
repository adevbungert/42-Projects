/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:36:19 by abungert          #+#    #+#             */
/*   Updated: 2016/03/21 19:23:58 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

void			free_lst(t_select **params)
{
	t_lst		*next;
	t_lst		*tmp;
	t_lst		*base;

	base = (*params)->list;
	tmp = base->next;
	while (tmp != base)
	{
		next = tmp->next;
		ft_memdel((void **)tmp);
		tmp = next;
	}
	ft_memdel((void **)params);
}

void			return_selected(t_select *params)
{
	t_lst		*tmp;
	t_lst		*base;
	int			space;

	base = params->list;
	tmp = base->next;
	space = 0;
	while (tmp != base)
	{
		if (tmp->selected)
		{
			if (space)
				ft_printf(" ");
			ft_printf("%s", tmp->value);
			space = 1;
		}
		tmp = tmp->next;
	}
	free_lst(&params);
}

void			print_lst(t_select *params)
{
	t_lst		*elem;
	t_lst		*base;

	fputs("cl");
	base = params->list;
	elem = base->next;
	while (elem != base)
	{
		print_with_effect(params, elem);
		elem = elem->next;
	}
	fmove(params);
}

static void		add_elem(t_lst *base, char *av)
{
	t_lst		*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (new_elem)
	{
		new_elem->value = ft_strdup(av);
		new_elem->selected = 0;
		new_elem->prev = base;
		new_elem->next = base->next;
		base->next->prev = new_elem;
		base->next = new_elem;
	}
}

t_select		*init_list(int ac, char **av)
{
	t_lst		*base;
	t_select	*params;
	size_t		size;

	size = 0;
	if (!(base = malloc(sizeof(*base))))
		return (NULL);
	if (!(params = malloc(sizeof(*params))))
		return (NULL);
	base->prev = base;
	base->next = base;
	while (ac > 1)
	{
		add_elem(base, av[ac - 1]);
		ac--;
		size++;
	}
	params->list = base;
	params->size_list = size;
	params->curs_y = 1;
	return (params);
}
