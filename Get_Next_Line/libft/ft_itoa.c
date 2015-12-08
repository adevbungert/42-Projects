/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:07:04 by abungert          #+#    #+#             */
/*   Updated: 2015/12/01 17:37:38 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		itoa_bis(int n, char *str, int *p)
{
	if (n < -9 || 9 < n)
		itoa_bis(n / 10, str, p);
	str[(*p)++] = '0' + ABS(n % 10);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			p;

	if (!(str = (char *)malloc(sizeof(char) * (sizeof(int) * 8 + 1))))
		return (NULL);
	p = 0;
	if (n < 0)
		str[p++] = '-';
	itoa_bis(n, str, &p);
	str[p] = '\0';
	return (str);
}
