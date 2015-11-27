/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:24:28 by abungert          #+#    #+#             */
/*   Updated: 2015/11/27 14:29:19 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	while (n != 0)
	{
		if (*src == '\0')
		{
			ft_memset(dst, '\0', n);
			break;
		}
		*dst = *src;
		n--;
		dst++;
		src++;
	}
	return dst;
}
