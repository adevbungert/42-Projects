#include "../ft_select.h"

static void		print_selected(t_lst *elem)
{
	fputs("so");
	ft_putstr_fd("\e[91m", 2);
	ft_putendl_fd(elem->value, 2);
	ft_putstr_fd("\e[0m", 2);
	fputs("se");
}

static void		print_current(t_lst *elem)
{
	fputs("us");
	ft_putstr_fd("\e[91m", 2);
	ft_putendl_fd(elem->value, 2);
	ft_putstr_fd("\e[0m", 2);
	fputs("ue");
}

static void		print_selected_current(t_lst *elem)
{
	fputs("us");
	fputs("so");
	ft_putstr_fd("\e[95m", 2);
	ft_putendl_fd(elem->value, 2);
	ft_putstr_fd("\e[0m", 2);
	fputs("se");
	fputs("ue");
}

void			print_with_effect(t_select *params, t_lst *elem)
{
	t_lst		*current;

	current = get_current_elem(params);
	if (elem->selected && elem == current)
		print_selected_current(elem);
	else if (elem->selected)
		print_selected(elem);
	else if (elem == current)
		print_current(elem);
	else
		ft_putendl_fd(elem->value, 2);
}

void			print_lst(t_select *params)
{
	t_lst		*elem;
	t_lst		*base;

	fputs("cl");
	base = params->list;
	elem = base->next;
	if (elem == base)
	{
		handle_inter();
		exit(0);
	}
	while (elem != base)
	{
		print_with_effect(params, elem);
		elem = elem->next;
	}
	fmove(params);
}