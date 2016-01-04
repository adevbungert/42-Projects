/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:18:34 by abungert          #+#    #+#             */
/*   Updated: 2015/12/14 14:58:55 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (size > 0)
	{
		while (dst[i] && i < size)
			i++;
		len = i;
		while (src[i - len] && i < size - 1)
		{
			dst[i] = src[i - len];
			i++;
		}
		if (i < size)
			dst[i] = 0;
	}
	return (len + ft_strlen(src));
}
