/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:24:28 by abungert          #+#    #+#             */
/*   Updated: 2015/12/08 16:42:32 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char *str;

	if (!dst || !src)
		return (NULL);
	str = dst;
	while (*src && n > 0)
	{
		n--;
		*str++ = *src++;
	}
	while (n-- > 0)
		*str++ = 0;
	return (dst);
}
