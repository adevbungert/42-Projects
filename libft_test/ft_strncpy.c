/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:24:28 by abungert          #+#    #+#             */
/*   Updated: 2015/12/09 16:15:34 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char *str;

    str = dst;
	while (*src != '\0' && n > 0)
	{
		*(dst++) = *(src++);
		n--;
	}
	while (n > 0)
	{
		*(dst++) = '\0';
		n--;
	}
	return (str);
}
