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

int			see_key()
{
	char	buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		ft_printf("%d %d %d", buffer[0], buffer[1], buffer[2]);
		if (buffer[0] == 27)
			ft_printf("C'est une fleche !\n");
		else if (buffer[0] == 4)
		{
			ft_printf("Ctlr+d, on quitte ! \n");
			return (0);
		}
		ft_bzero(buffer, 3);
	}
	return (0);
}

static int	myoutc(int c)
{
	ft_putchar(c);
	return (0);
}

void		add_elem(t_lst *base, char *av)
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

void		init_list(int ac, char **av)
{
	t_lst	*base;

	base = malloc(sizeof(*base));
	if (base != NULL)
	{
		base->prev = base;
		base->next = base;
	}
	while (ac > 0)
	{
		add_elem(base, av[ac - 1]);
		ac--;
	}
}

int					main(int ac, char **av)
{
	char			*name_term;
	struct termios	term;

	if (ac <= 0)
		return (0);
	init_list(av, ac);

//	if ((name_term = getenv("TERM")) == NULL)
//		return (-1);
//	if (!(tgetent(NULL, name_term)))
//		return (-1);
//	if (tcgetattr(0, &term) == -1)
//		return (-1);
//	test();
	return (0);
}
