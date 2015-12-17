/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 12:16:35 by abungert          #+#    #+#             */
/*   Updated: 2015/12/03 13:00:57 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void		aux_base_dix(int n, char *str, int *p)
{
	if (n < -9 || 9 < n)
		aux(n / 10, str, p);
	str[(*p)++] = '0' + ABS(n % 10);
}

static void		aux(unsigned int n, unsigned int b, char *str, int *p)
{
	char const	base[] = "123456789ABCDEF";

	if (n >= b)
		aux(n / b, b, str, p);
	str[(*p)++] = base[n % b];
}

char			*ft_itoa_base(int n, int base)
{
	char		*str;
	int			p;

	if (base < 2 || 16 < base
		|| !(str = (char *)malloc(sizeof(char) * (sizeof(int) * 8 + 1))))
		return (NULL);
	p = 0;
	if (base == 10 && n < 0)
		str[p++] = '-';
	if (base == 10)
		aux_base_dix(n, str, &p);
	else
		aux((unsigned int)n, (unsigned int)base, str, &p);
	str[p] = '\0';
	return (str);
}
