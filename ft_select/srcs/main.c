/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinebungert <antoinebungert@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:39:33 by abungert          #+#    #+#             */
/*   Updated: 2016/03/23 11:12:02 by antoinebungert   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

int			ft_select(int ac, char **av, t_select *params)
{
	fputs("cl");
	if (!(params = init_list(ac, av, params)))
		return (-1);	
	ft_get_col_n(params);
	ft_check_size(params);
	save_term(params, 0);
	get_key(params);
	return (0);
}

int				main(int ac, char **av)
{
	t_select	params;

	params.list = NULL;
	if (ac <= 1)
		return (-1);
	ft_signal();
	if (init_term(&params) == -1)
		return (-1);
	if (ft_select(ac, av, &params) == -1)
		return (-1);	
	if (restore_term(&params) == -1)
		return (-1);
	return (0);
}
