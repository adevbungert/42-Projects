/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:57:42 by abungert          #+#    #+#             */
/*   Updated: 2015/12/01 17:47:48 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char			*str;
	unsigned int	i;

	if (s && f)
	{
		str = s;
		i = 0;
		while (*str)
		{
			(*f)(i, str);
			i++;
			str++;
		}
	}
}
