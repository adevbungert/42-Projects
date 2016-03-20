#include "../ft_select.h"

void			print_lst(t_lst *base)
{
	t_lst		*tmp;

	tmp = base->next;
	while (tmp != base)
	{
		ft_printf("%s\n", tmp->value);
		tmp = tmp->next;
	}
}

static void		add_elem(t_lst *base, char *av)
{
	t_lst	*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (new_elem)
	{
		new_elem->value = av;
		new_elem->prev = base;
		new_elem->next = base->next;
		base->next->prev = new_elem;
		base->next = new_elem;
	}
}

t_lst	*init_list(int ac, char **av)
{
	t_lst	*base;

	base = malloc(sizeof(*base));
	if (base != NULL)
	{
		base->prev = base;
		base->next = base;
	}
	while (ac > 1)
	{
		add_elem(base, av[ac - 1]);
		ac--;
	}
	return (base);
}
