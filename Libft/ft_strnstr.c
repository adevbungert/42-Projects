/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:32:42 by abungert          #+#    #+#             */
/*   Updated: 2015/11/27 13:44:48 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, int n)
{
	size_t s2_len;
	const char	*str = s1;

	if (*s2 == '\0')
		return ((char *)str);
	s2_len = ft_strlen(s2);
	while (*str && (n != 0))
	{
		n--;
		if ((str = ft_strchr(str, *s2)) != NULL)
		{
			if ((ft_strncmp(str, s2, s2_len)) == 0)
				return ((char *) str);
		}
		str++;
	}
	return NULL;
}