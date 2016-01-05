/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:23:18 by jperrin           #+#    #+#             */
/*   Updated: 2015/12/12 14:17:46 by jperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*dst2;
	size_t			i;

	i = 0;
	if (!src || !(d = (unsigned char*)malloc(sizeof(*src) * len)))
		return (NULL);
	s = (unsigned char*)src;
	dst2 = (unsigned char *)dst;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dst2[i] = d[i];
		i++;
	}
	free(d);
	return (dst2);
}
