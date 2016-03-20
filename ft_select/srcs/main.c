/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:39:33 by abungert          #+#    #+#             */
/*   Updated: 2016/03/16 15:45:46 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

static int	myoutc(int c)
{
	ft_putchar(c);
	return (0);
}

int			see_key(t_lst *base)
{
	char	buffer[3];
	char	*res;
	char	*area;

	print_lst(base);
	// area = malloc(sizeof(char) * 4);
	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27 && buffer[2] == 66)
			res = tgetstr("do", &area);
		else if (buffer[0] == 27 && buffer[2] == 65)
			res = tgetstr("up", &area);
		tputs(res, 1, myoutc);
		ft_bzero(buffer, 3);
	}
	return (0);
}

int					main(int ac, char **av)
{
	char			*name_term;
	struct termios	term;
	t_lst			*base;

	if (ac <= 0)
		return (0);
	base = init_list(ac, av);
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (!(tgetent(NULL, name_term)))
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	see_key(base);
	return (0);
}
