/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:23:41 by abungert          #+#    #+#             */
/*   Updated: 2016/03/21 18:31:28 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_select.h"

static int		is_arrow(char *key)
{
	if (key[0] == 27 && key[1] == 91 && key[2] >= 65 && key[2] <= 68)
		return (1);
	return (0);
}

static int		is_esc(char *key)
{
	if (key[0] == 27 && key[2] == 0)
		return (1);
	else
		return (0);
}

static int		is_space(char *key)
{
	if (key[0] == 32 && key[2] == 0)
		return (1);
	else
		return (0);
}

static int		is_enter(char *key)
{
	if (key[0] == 10 && key[1] == 0 && key[2] == 0)
		return (1);
	else
		return (0);
}

int				get_key(t_select *params)
{
	char		*key;

	if (!(key = malloc(4)))
		return (-1);
	while (read(0, key, 3))
	{
		if (is_arrow(key))
			press_arrow(params, key[2]);
		if (is_enter(key))
			press_enter(params);
		if (is_esc(key))
			break ;
		if (is_space(key))
			press_space(params);
		ft_bzero(key, 4);
	}
	return (0);
}
