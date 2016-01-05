/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:05:08 by jperrin           #+#    #+#             */
/*   Updated: 2015/11/29 15:59:32 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;
	unsigned char	c1;

	if (!src)
		return (NULL);
	c1 = (unsigned char)c;
	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == c1)
		{
			d[i] = c1;
			d += i + 1;
			return (d);
		}
		i++;
	}
	return (NULL);
}
