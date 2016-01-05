/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:30:55 by abungert          #+#    #+#             */
/*   Updated: 2015/12/20 12:15:19 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int		check_str(char *str)
{
	int		i;
	int		nb;
	char	*tmp;

	tmp = str;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] < '0' || tmp[i] > '9')
			return (0);
		else
			i++;
	}
	nb = ft_atoi(str);
	if (0 < nb && nb <= 10000)
		return (nb);
	return (0);
}
