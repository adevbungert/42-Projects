#include "../ft_select.h"

int					ft_check_size(t_select *params)
{	
	if (params->win_row - 2 < params->size_list || params->win_col - 2 < params->col_n)
	{
		fputs("cl");
		ft_putendl_fd("Windows too small!", 2);
		return (0);
	}
	else
	{
		fputs("cl");
		print_lst(params);
	}
	return (1);
}

void				ft_resize(void)
{
	t_select		*params;
	struct winsize	win;

	params = NULL;
	params = save_term(params, 1);
	fputs("cl");
	ioctl(0, TIOCGWINSZ, &win);
	params->win_col = win.ws_col;
	params->win_row = win.ws_row;
	ft_check_size(params);
}

void			ft_get_col_n(t_select *params)
{
	t_lst		*tmp;
	t_lst		*base;

	base = params->list;
	tmp = base->next;
	while (tmp != base)
	{
		if (tmp->len > params->col_n)
			params->col_n = tmp->len;
		tmp = tmp->next;
	}
}
