/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:32:42 by abungert          #+#    #+#             */
/*   Updated: 2015/12/01 17:54:22 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char const	*str1;
	char const	*str2;
	size_t		len;

	if (!s1 || !s2)
		return (NULL);
	str2 = s2;
	while (*s1 != '\0' && n > 0)
	{
		len = n;
		str1 = s1;
		while (*s2 != '\0' && *s1 == *s2 && len > 0)
		{
			++s1;
			++s2;
			len--;
		}
		if (*s2 == '\0')
			return ((char *)str1);
		s1 = str1 + 1;
		s2 = str2;
		n--;
	}
	return (*s2 == '\0' ? (char *)s1 : NULL);
}
