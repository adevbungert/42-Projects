/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:07:04 by abungert          #+#    #+#             */
/*   Updated: 2016/01/05 15:13:21 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		itoa_bis(int n, char *str, int *p)
{
	if (n < -9 || 9 < n)
		itoa_bis(n / 10, str, p);
	str[(*p)++] = '0' + ABS(n % 10);
}

static int		ft_get_size(int n)
{
	if (n < 10 && n > -10)
	{
		if (n < 10 && n >= 0)
			return (1);
		return (2);
	}
	return (ft_get_size(n / 10) + 1);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			p;

	if (!(str = (char *)malloc(sizeof(char) * (ft_get_size(n) + 1))))
		return (NULL);
	p = 0;
	if (n < 0)
		str[p++] = '-';
	itoa_bis(n, str, &p);
	str[p] = '\0';
	return (str);
}
