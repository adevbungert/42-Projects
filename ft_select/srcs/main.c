/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:39:33 by abungert          #+#    #+#             */
/*   Updated: 2016/03/21 19:26:40 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

int				main(int ac, char **av)
{
	char		*name_term;
	t_select	*params;

	if (ac <= 0)
		return (0);
	if (!(params = init_list(ac, av)))
		return (-1);
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (!(tgetent(NULL, name_term)))
		return (-1);
	if (init_term() == -1)
		return (-1);
	print_lst(params);
	get_key(params);
	if (restore_term() == -1)
		return (-1);
	free_lst(&params);
	return (0);
}
