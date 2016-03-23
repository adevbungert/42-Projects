/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebungert <antoinebungert@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 10:06:46 by abungert          #+#    #+#             */
/*   Updated: 2016/03/23 11:44:28 by antoinebungert   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

int					restore_term(t_select *params)
{
	params->term.c_lflag |= ICANON;
	params->term.c_lflag |= ECHO;
	if (tcsetattr(0, 0, &(params->term)) == -1)
		return (-1);
	fputs("te");
	fputs("ve");
	if (params->returned)
		return_selected(params);
	free_lst(&params);
	return (0);
}

int					init_term(t_select *params)
{
	struct 			winsize win;
	char			*name_term;

	if ((name_term = getenv("TERM")) == NULL)
	{
		ft_printf("Cannot find environment TERM\n");
		return (-1);
	}
	if (tgetent(NULL, name_term) != 1)
		return (-1);
	if (tcgetattr(0, &(params->term)) == -1)
		return (-1);
	params->term.c_lflag &= ~ICANON;
	params->term.c_lflag &= ~ECHO;
	params->term.c_cc[VMIN] = 1;
	params->term.c_cc[VTIME] = 0;
	ioctl(0, TIOCGWINSZ, &win);
	params->win_col = win.ws_col;
	params->win_row = win.ws_row;
	if (tcsetattr(0, 0, &(params->term)) == -1)
		return (-1);
	fputs("ti");
	fputs("vi");
	return (0);
}

t_select			*save_term(t_select *params, int i)
{
	static t_select	*tmp = NULL;

	if (i == 0)
		tmp = params;
	return (tmp);
}