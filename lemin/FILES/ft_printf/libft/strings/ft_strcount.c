/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:35:31 by abungert          #+#    #+#             */
/*   Updated: 2016/04/29 10:36:57 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcount(char *str, char to_find)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == to_find)
			count++;
		str++;
	}
	return (count);
}
