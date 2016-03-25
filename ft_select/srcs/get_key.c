/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 12:05:28 by abungert          #+#    #+#             */
/*   Updated: 2016/03/24 12:06:09 by abungert         ###   ########.fr       */
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
	if (key[0] == 27 && key[1] == 0 && key[2] == 0)
		return (1);
	else
		return (0);
}

static int		is_space(char *key)
{
	if (key[0] == 32 && key[1] == 0 && key[2] == 0)
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

	key = ft_strnew(4);
	while (read(0, key, 3))
	{
		if (is_esc(key))
		{
			restore_term(params);
			exit(0);
		}
		if (ft_check_size(params))
		{
			if (is_arrow(key))
				press_arrow(params, key[2]);
			else if (is_enter(key))
				press_enter(params);
			else if (is_space(key))
				press_space(params);
			else if (key[0] == 127 || key[0] == 126 || key[0] == 8)
				press_delete(params);
		}
		ft_bzero(key, 4);
	}
	return (0);
}
