/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:07:04 by abungert          #+#    #+#             */
/*   Updated: 2015/11/27 16:47:40 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int i;
	int len;
	int sign;
	char *str;

	len = 0;
	if ((sign = n) < 0)
		n = -n;
	while (ft_power(10, len) < n)
		len++;
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return NULL;
	i = 1;
	str[0] = (n % 10) + 48; 
	while ((n /= 10) > 0)
		str[i++] = (n % 10) + 48;
	if (sign < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}