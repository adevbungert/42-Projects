/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:52:21 by abungert          #+#    #+#             */
/*   Updated: 2015/11/26 11:54:18 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, size_t n)
{
	char *s;

	s = dest;
	while (*s != '\0')
		s++;
	while ((n != 0) && *src)
	{
		*s = *src;
		n--;
		s++;
		src++;
	}
	if (*s != '\0')
		*s = '\0';
	return (dest);
}